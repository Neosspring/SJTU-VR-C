#include <utility>
#include "Matrix.h"

Matrix operator+(const Matrix& m1, const Matrix& m2) 
{
	Matrix res;
	for (int i = 0; i < m1.row; i++) {
		for (int j = 0; j < m1.column; j++) {
			res.elem[i][j] = m1.elem[i][j] + m2.elem[i][j];
		}
	}
	res.column = m1.column;
	res.row = m1.row;
	return res;
}

Matrix operator-(const Matrix& m1, const Matrix& m2)
{
	Matrix res;
	for (int i = 0; i < m1.row; i++) {
		for (int j = 0; j < m1.column; j++) {
			res.elem[i][j] = m1.elem[i][j] - m2.elem[i][j];
		}
	}
	res.column = m1.column;
	res.row = m1.row;
	return res;
}

Matrix operator*(const Matrix& m1, const Matrix& m2) 
{
	Matrix res;
	for (int i = 0; i < m1.row; i++) {
		for (int j = 0; j < m2.column; j++) {
			res.elem[i][j] = 0.0;
			for (int k = 0; k < m1.column; k++) {
				res.elem[i][j] += m1.elem[i][k] * m2.elem[k][j];
			}
		}
	}
	res.column = m1.column;
	res.row = m2.row;
	return res;
}