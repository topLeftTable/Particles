#include "Matrices.h"
using namespace Matrices;

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
}

Matrix operator*(const Matrix &a, const Matrix &b)
{
	// ld YOUR CODE HERE !!!
}

bool operator==(const Matrix &a, const Matrix &b)
{
	// dd YOUR CODE HERE !!!
}

bool operator!=(const Matrix &a, const Matrix &b)
{
	// wk YOUR CODE HERE !!!
}

ostream &operator<<(ostream &os, const Matrix &a)
{
	// ld YOUR CODE HERE !!!
}

RotationMatrix::RotationMatrix(double theta) : Matrix(2, 2)
{
	// dd YOUR CODE HERE !!!
}

ScalingMatrix::ScalingMatrix(double scale) : Matrix(2, 2)
{
	// wk YOUR CODE HERE !!!
}

TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(2, nCols)
{
	// ld YOUR CODE HERE !!!
}

