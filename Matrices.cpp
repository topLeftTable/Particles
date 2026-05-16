#include "Matrices.h"
using namespace Matrices;

Matrix::Matrix(int _rows, int _cols)
{
	// dd YOUR CODE HERE !!!
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

RotationMatrix::RotationMatrix(double theta) : Matrix(getRows(), getCols())
{
	// dd YOUR CODE HERE !!!
}

ScalingMatrix::ScalingMatrix(double scale) : Matrix(getRows(), getCols())
{
	// wk YOUR CODE HERE !!!
}

TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(getRows(), getCols())
{
	// ld YOUR CODE HERE !!!
}

