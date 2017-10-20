#include "determinant.h"
#include<vector>
#include<iostream>

using namespace std;

void Determinant::print(vector<int> v1, vector<int> v2) 
{
	for (int i = 0; i < v2.size(); i++) {
		cout << v1[v2[i]] << " ";
	}
	cout << endl;
}

void Determinant::print(int v1[10][10],int size) 
{
	for (int i = 0; i < size; i++) {
		for (int j = 0 ; j < size; j++)
		{
			cout << v1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int Determinant::findMovable(vector<int> deter, vector<int> dir, int n) 
{
	int max = -1;
	for (int i = 0; i < n; i++) 
	{
		if (max<0 || deter[i] > deter[max]) 
		{
			if (dir[i] == 1 && i > 0 && deter[i] > deter[i - 1]) 
			{
				max = i;
			}
			else if (dir[i] == 0 && i < n - 1 && deter[i] > deter[i + 1]) 
			{
				max = i;
			}
		}
	}

	return max;
}

vector<int> Determinant::reverse(vector<int> v, vector<int> left, int index) 
{
	for (int i = 0; i < v.size(); i++) 
	{
		if (v[i] > v[index]) 
		{
			if (left[i] == 0)
				left[i] = 1;
			else
				left[i] = 0;
		}
	}
	return left;
}

int Determinant::GetInverseCount(vector<int> sequence, int size)
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

vector<int> Determinant::swap(vector<int> v, int index1, int index2) 
{
	int index = v[index1];
	v[index1] = v[index2];
	v[index2] = index;
	return v;
}

int Determinant::valueOfDeterminant(int ** deter, int size)
{
	int det[10][10];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			det[i][j] = deter[i][j];
		}
	}
	return valueOfDeterminant(det, size);
}

int Determinant::valueOfDeterminant(int deter[10][10], int size) 
{
	vector<int> pIndex;
	vector<int> pDir;
	int index = size - 1;	
	int value = 0;
	int product;
	for (int i = 0; i < size; ++i) 
	{
		pIndex.push_back(i);
		pDir.push_back(1);
	}
	do
	{
		/*for (int i = 0; i < size; i++) {
			cout << pIndex[i] << " ";
		}
		cout << endl;*/
		if (GetInverseCount(pIndex, size) / 2 == 0) 
		{
			product = 1;
		}
		else 
		{
			product = -1;
		}
		for (int i = 0; i < size; i++) 
		{
			product *= deter[pIndex[i]][i];
		}
		value += product;
		int flag = pDir[index];
		int swapIdx = flag == 1 ? index - 1 : index + 1;
		pIndex = swap(pIndex, swapIdx, index);
		pDir = swap(pDir, swapIdx, index);
		if (flag == 1) 
		{
			index--;
		}
		else 
		{
			index++;
		}
		pDir = reverse(pIndex, pDir, index);
		index = findMovable(pIndex, pDir, size);
	} while (index != -1);
	if (GetInverseCount(pIndex, size) / 2 == 0)
	{
		product = 1;
	}
	else
	{
		product = -1;
	}
	for (int i = 0; i < size; i++)
	{
		product *= deter[pIndex[i]][i];
	}
	value += product;
	return value;
}


int ** Determinant::getAdeter(int deter[10][10], int x, int y, int size)
{
	int **adeter = 0;

	adeter = new int*[size];

	int k = 0;

	for (int i = 0; i < size - 1; i++)
	{
		if (i == x) {
			k = 1;
		}
		adeter[i] = new int[size];
		for (int j = 0; j < size - 1; j++)
		{
			int l;
			if (j < y) {
				l = 0;
			}
			else {
				l = 1;
			}
			adeter[i][j] = deter[i+k][j+l];
		}
	}
	return adeter;
}

int ** Determinant::mul(int d1[10][10], int d2[10][10], int size)
{
	int **deter = 0;

	deter = new int*[size];

	for (int i = 0; i < size; i++) {
		deter[i] = new int[size];
		for (int j = 0; j < size; j++) {
			int count = 0;
			for (int k = 0; k < size; k++) {
				count += d1[i][k] * d2[k][j];
			}
			deter[i][j] = count;
		}
	}

	return deter;
}