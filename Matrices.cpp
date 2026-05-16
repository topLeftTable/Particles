#include "Matrices.h"

namespace Matrices
{
/// Construct a matrix of the specified size.
/// Initialize each element to 0.
Matrix::Matrix(int _rows, int _cols) : rows(_rows), cols(_cols)
{
	a.resize(rows);
	for (int i = 0; i < rows; i++)
	{
		a[i].resize(cols, 0);
	}
}

Matrix operator+(const Matrix &a, const Matrix &b)
{
	// wk YOUR CODE HERE !!!
	if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
	{
		throw runtime_error("Error: dimensions must agree");
	}

	Matrix result(a.getRows(), a.getCols());

	for (int r = 0; r < a.getRows(); r++)
	{
		for (int c = 0; c < a.getCols(); c++)
		{
			result(r, c) = a(r, c) + b(r, c);
		}
	}
	return result;
}

/// Matrix multiply.  See description.
/// usage:  c = a * b;
Matrix operator*(const Matrix &a, const Matrix &b)
{
	// ld YOUR CODE HERE !!!
	if (a.getCols() != b.getRows())
	{
		throw runtime_error("Error: dimensions must agree");
	}

	Matrix result(a.getRows(), b.getCols());

	for (int i = 0; i < a.getRows(); i++)
	{
		for (int k = 0; k < b.getCols(); k++)
		{
			double sum = 0;
			for (int j = 0; j < a.getCols(); j++)
			{
				sum += a(i, j) * b(j, k);
			}
			result(i, k) = sum;
		}
	}
	return result;
}

bool operator==(const Matrix &a, const Matrix &b)
{
	// dd YOUR CODE HERE !!!
	if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
	{
		return false;
	}

	for (int r = 0; r < a.getRows(); r++)
	{
		for (int c = 0; c < a.getCols(); c++)
		{
			if (a(r, c) - b(r, c) > 0.001 || a(r, c) - b(r, c) < -0.001)
				return false;
		}
	}

	return true;
}

bool operator!=(const Matrix &a, const Matrix &b)
{
	// wk YOUR CODE HERE !!!
	return !(a == b);
}

/// Output matrix.
/// Separate columns by ' ' and rows by '\n'
ostream &operator<<(ostream &os, const Matrix &a)
{
	// ld YOUR CODE HERE !!!
	for (int x = 0; x < a.getRows(); x++)
	{
		for (int y = 0; y < a.getCols(); y++)
		{
			os << a(x, y) << ' ';
		}
		os << "\n";
	}
	return os;
}

RotationMatrix::RotationMatrix(double theta) : Matrix(2, 2)
{
	// dd YOUR CODE HERE !!!
}

ScalingMatrix::ScalingMatrix(double scale) : Matrix(2, 2)
{
	// wk YOUR CODE HERE !!!
}

/// 2D Translation matrix
/// usage:  A = T + A will shift all coordinates of A by (xShift, yShift)
///
/// Call the parent constructor to create a 2xn matrix
/// Then assign each element as follows:
/*
xShift  xShift  xShift  ...
yShift  yShift  yShift  ...
*/
/// paramaters are xShift, yShift, and nCols
/// nCols represents the number of columns in the matrix
/// where each column contains one (x,y) coordinate pair
TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols)
	: Matrix(2, nCols)
{
	// ld YOUR CODE HERE !!!
	for (int i = 0; i < nCols; i++) a[0][i] = xShift;
	for (int j = 0; j < nCols; j++) a[1][j] = yShift;
}
} // namespace Matrices