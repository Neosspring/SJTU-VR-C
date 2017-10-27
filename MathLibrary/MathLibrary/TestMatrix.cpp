#include <iostream>
#include "Matrix.h"
using namespace std;

void Print(const Determinant& dm);

void Print(const Matrix& dm)
{
	for (int i = 0; i < dm.row; i++)
	{
		cout << "( ";
		for (int j = 0; j < dm.column; j++)
			cout << dm.elem[i][j] << "  ";
		cout << ')' << endl;
	}
	cout << endl;
}

void TestSum()
{
	const double m1[][3] = { {1,2,3},{4,5,6},{7,8,9} };
	const double m2[][3] = { {3,2,1},{6,5,4},{9,8,7} };

	Matrix mm1(&m1[0][0], 3, 3);
	Matrix mm2(&m2[0][0], 3, 3);
	Matrix res = mm1 + mm2;

	Print(mm1);
	Print(mm2);
	Print(res);
}

void TestSub()
{
	const double m1[][3] = { { 1,2,3 },{ 4,5,6 },{ 7,8,9 } };
	const double m2[][3] = { { 3,2,1 },{ 6,5,4 },{ 9,8,7 } };

	Matrix mm1(&m1[0][0], 3, 3);
	Matrix mm2(&m2[0][0], 3, 3);
	Matrix res = mm1 - mm2;

	Print(mm1);
	Print(mm2);
	Print(res);
}

void TestMul()
{
	const double m1[][3] = { { 1,2,3 },{ 4,5,6 },{ 7,8,9 } };
	const double m2[][3] = { { 3,2,1 },{ 6,5,4 },{ 9,8,7 } };

	Matrix mm1(&m1[0][0], 3, 3);
	Matrix mm2(&m2[0][0], 3, 3);
	Matrix res = mm1 * mm2;

	Print(mm1);
	Print(mm2);
	Print(res);
}

void TestInverse()
{
	const double m[][3] = { {1,0,3},{0,2,1},{1,3,0} };
	
	Determinant d(&m[0][0], 3);
	Matrix mm(&m[0][0], 3, 3);
	Matrix res = getInverse(&m[0][0], 3);

	Print(mm);
	Print(res);
}