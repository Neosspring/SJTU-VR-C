#include <utility>
#include <iostream>
#include "Matrix.h"
#include "Determinant.h"
using namespace std;

void Print(const Determinant& dm);
void Print(const Matrix& dm);

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

Matrix getInverse(const double* m,int size)
{
	Determinant mm(m, size);

	double count = Evaluate(mm);
	Determinant result = GetCofactors(mm);
	Matrix res;
	res.column = size;
	res.row = size;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			res.elem[i][j] = result.elem[i][j] / count;
		}
	}

	return res;
}