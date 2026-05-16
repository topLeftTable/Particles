#include "Matrices.h"
using namespace Matrices;

Matrix::Matrix(int _rows, int _cols)
{
	// YOUR CODE HERE !!!
}

Matrix operator+(const Matrix &a, const Matrix &b)
{
	// YOUR CODE HERE !!!
}

Matrix operator*(const Matrix &a, const Matrix &b)
{
	// YOUR CODE HERE !!!
}

bool operator==(const Matrix &a, const Matrix &b)
{
	// YOUR CODE HERE !!!
}

bool operator!=(const Matrix &a, const Matrix &b)
{
	// YOUR CODE HERE !!!
}

ostream &operator<<(ostream &os, const Matrix &a)
{
	// YOUR CODE HERE !!!
}

RotationMatrix::RotationMatrix(double theta) : Matrix(getRows(), getCols())
{
	// YOUR CODE HERE !!!
}

ScalingMatrix::ScalingMatrix(double scale) : Matrix(getRows(), getCols())
{
	// YOUR CODE HERE !!!
}

TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(getRows(), getCols())
{
	// YOUR CODE HERE !!!
}

