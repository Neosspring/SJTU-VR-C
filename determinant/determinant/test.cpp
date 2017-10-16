#include "determinant.h"
#include<vector>
#include<iostream>

using namespace std;

void TestPermutation()
{
	vector<int> det = { 1,3,7,6 };

	determinant deter1(det);
	for (int i = 0; i < deter1.deter.size(); i++) {
		cout << deter1.deter[deter1.pIndex[i]] << " ";
	}
	cout << endl;


}