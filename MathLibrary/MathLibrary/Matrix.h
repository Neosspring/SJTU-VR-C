#pragma once
#include "Determinant.h"

struct Matrix {
	double elem[10][10];
	int row, column;

	Matrix(const double* m, int r, int c)
	{
		row = r;
		column = c;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++) 
			{
				elem[i][j] = m[i*r + j];
			}
		}
	}

	Matrix() 
	{
		row = column = 0;
	}
};
Matrix operator+(const Matrix& m1, const Matrix& m2);
Matrix operator-(const Matrix& m1, const Matrix& m2);
Matrix operator*(const Matrix& m1, const Matrix& m2);
Matrix getInverse(const double* m, int size);