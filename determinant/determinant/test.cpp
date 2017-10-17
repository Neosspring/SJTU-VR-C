#include "determinant.h"
#include<vector>
#include<iostream>

using namespace std;

void TestPermutation()
{
	vector<int> det = { 1,3,7 };

	vector<vector<int>> deter = { {1,2,3},{4,5,6},{7,8,9} };

	cout << deter.size() << endl;

	determinant deter1(det);

	deter1.print(deter1.deter, deter1.pIndex);

	int index = deter1.findMovable(deter1.pIndex, deter1.pDir, deter1.deter.size());

	while (index != -1) {
		int flag = deter1.pDir[index];
		int swapIdx = flag == 1 ? index - 1 : index + 1;
		
		deter1.pIndex = deter1.swap(deter1.pIndex, swapIdx, index);
		
		deter1.print(deter1.deter, deter1.pIndex);

		deter1.pDir = deter1.swap(deter1.pDir, swapIdx, index);

		if (flag == 1) {
			index--;
		}
		else {
			index++;
		}

		deter1.pDir = deter1.reverse(deter1.pIndex, deter1.pDir, index);

		index = deter1.findMovable(deter1.pIndex, deter1.pDir, deter1.deter.size());
	}
}