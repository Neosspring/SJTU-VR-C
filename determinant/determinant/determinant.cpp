#include "determinant.h"
#include<vector>
#include<iostream>

using namespace std;

void determinant::print(vector<int> v1, vector<int> v2) {
	for (int i = 0; i < v2.size(); i++) {
		cout << v1[v2[i]] << " ";
	}
	cout << endl;
}

int determinant::findMovable(vector<int> v1, vector<int> dir, int n) {
	int max = -1;
	for (int i = 0; i < n; i++) {
		if (max<0 || v1[i]>v1[max]) {
			if (dir[i] == 1 && i > 0 && v1[i] > v1[i - 1]) {
				max = i;
			}
			else if (dir[i] == 0 && i<n - 1 && v1[i]>v1[i + 1]) {
				max = i;
			}
		}
	}
	return max;
}

vector<int> determinant::reverse(vector<int> v, vector<int> left, int index) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > v[index]) {
			if (left[i] == 0)
				left[i] = 1;
			else
				left[i] = 0;
		}
	}
	return left;
}

int determinant::GetInverseCount(vector<int> sequence, int size)
{
	int count{ 0 };
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (sequence[i] > sequence[j])
				++count;
		}
	}
	return count;
}
