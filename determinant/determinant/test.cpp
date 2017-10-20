#include "determinant.h"
#include<vector>
#include<iostream>

using namespace std;

void TestPermutation()
{
	int det1[10][10] = { {1,2,3},{1,1,1},{2,2,1} };

	Determinant deter1(det1, 3);

	cout << "determinant1:" << endl;

	deter1.print(deter1.deter, 3);

	int det2[10][10] = { {1,0,1},{0,1,1},{0,0,1} };

	Determinant deter2(det2, 3);

	cout << "determinant2:" << endl;

	deter2.print(deter2.deter, 3);

	cout << "determinant1 * determinant2 = " << endl;

	int ** result = deter1.mul(deter1.deter, deter2.deter, 3);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	cout << "value of determinant1: "<<deter1.value << endl;

	cout << "algebraic complement of determinant1:" << endl;

	deter1.print(deter1.Adeter, 3);
}