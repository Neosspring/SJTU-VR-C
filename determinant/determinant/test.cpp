#include "determinant.h"
#include<vector>

using namespace std;

void TestPermutation()
{
	vector<int> det = { 1,3,7,6 };

	determinant deter1(det,4);
	deter1.GetPermutation(deter1.deter, 4);

}
