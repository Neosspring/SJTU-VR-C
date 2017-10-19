#include "determinant.h"
#include<vector>
#include<iostream>

using namespace std;

void TestPermutation()
{
	vector<int> det = { 1,3,7 };

	int deter[10][10] = { {1,0,0},{0,1,0},{1,1,1} };

	Determinant deter1(deter, 3);

	deter1.print(deter1.deter, 3);

	cout << deter1.sizeOfDeter << endl;
	cout << deter1.value << endl;

	deter1.print(deter1.Adeter, 3);
}