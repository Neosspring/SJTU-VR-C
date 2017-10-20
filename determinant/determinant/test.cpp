#include "determinant.h"
#include<vector>
#include<iostream>

using namespace std;

void TestPermutation()
{
	vector<int> det = { 1,3,7 };

	int det1[10][10] = { {1,2,3},{1,1,1},{2,2,1} };

	Determinant deter1(det1, 3);

	deter1.print(deter1.deter, 3);

	int det2[10][10] = { {1,0,1},{0,1,1},{0,0,1} };

	Determinant deter2(det2, 3);

	deter2.print(deter2.deter, 3);

	int ** result = deter1.mul(deter1.deter, deter2.deter, 3);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	/*cout << deter1.sizeOfDeter << endl;
	cout << deter1.value << endl;

	deter1.print(deter1.Adeter, 3);*/
}