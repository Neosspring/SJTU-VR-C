#pragma once
#include "Matrix.h"
enum class Direction : char { Left, Right };
struct Sequence {
	int index[10];
	Direction dir[10];
	int count;
	Sequence(int size)
	{
		count = size;
		for (int i = 0; i < size; i++)
		{
			index[i] = i;
			dir[i] = Direction::Left;
		}
	}
};

struct Determinant {
	double  elem[10][10];
	int     order;

	Determinant(const double* m, int dim)
	{
		order = dim;
		for (int i = 0; i < dim; i++)
			for (int j = 0; j < dim; j++)
				elem[i][j] = m[i*dim + j];
	}

	Determinant()
	{
		order = 0;
	}
};
int GetInverseCount(const Sequence&);
bool Next(Sequence&  seq);
double Evaluate(const Determinant&);
Determinant operator* (const Determinant& dm1, const Determinant& dm2);
double GetCofactor(const Determinant& dm, int row, int col);
Determinant GetCofactors(const Determinant& dm);

