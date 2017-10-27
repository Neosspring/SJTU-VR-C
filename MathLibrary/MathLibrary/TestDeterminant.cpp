#include <iostream>
#include "Determinant.h"
using namespace std;

void Print(const Determinant& dm)
{
	for (int i = 0; i < dm.order; i++)
	{
		cout << "| ";
		for (int j = 0; j < dm.order; j++)
			cout << dm.elem[i][j] << "  ";
		cout << '|' << endl;
	}
	cout << endl;
}

void TestEvaluation()
{
	const double m[][3] = { { 2, 2, 2 },{ 0, 2, 2 },{ 0, 0, 2 } };
	const double expectValue = 8.0;
	cout << "<<<<<<<<<<<<Test evaluation of  a determiant<<<<<<<<<<" << endl;
	Determinant dm(&m[0][0], 3);
	double result = Evaluate(dm);
	Print(dm);
	if (expectValue == result)
		cout << "Pass£¡";
	else
		cout << "Failed! ";
	cout << "expection value : " << result << " actual value : " << result << endl;
	cout << "<<<<<<<<<<<<Test end<<<<<<<<<<" << endl << endl;

}

void TestMutiply()
{
	const double m1[][3] = { { 2, 0, 0 },{ 0, 2, 0 },{ 0, 0, 2 } };
	const double m2[][3] = { { 3, 0, 0 },{ 0, 4, 0 },{ 0, 0, 5 } };

	Determinant dm1(&m1[0][0], 3);
	Determinant dm2(&m2[0][0], 3);
	Determinant res = dm1* dm2;
	cout << "<<<<<<<<<<<<Test a determinant time by another determiant<<<<<<<<<<" << endl;
	Print(dm1);
	Print(dm2);
	cout << "The result of two determinant is :" << endl;
	Print(res);
	cout << "<<<<<<<<<<<<Test end <<<<<<<<<<" << endl << endl;
}

void TestCofactors()
{
	const double m[][3] = { { 2, 2, 2 },{ 0, 2, 2 },{ 0, 0, 2 } };
	Determinant dm(&m[0][0], 3);
	Determinant res = GetCofactors(dm);
	cout << "<<<<<<<<<<<<Test computation of the cofactors of determiant<<<<<<<<<<" << endl;
	Print(dm);
	cout << "The cofactors  of determinant is " << endl;
	Print(res);
	cout << "<<<<<<<<<<<<Test end <<<<<<<<<<" << endl << endl;
}