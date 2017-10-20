#pragma once
#include<vector>
#include<iostream>

using namespace std;

class Determinant
{
public:
//	vector<int> deter;
//	vector<int> pIndex;
//	vector<int> pDir;
	int deter[10][10];
	int value, sizeOfDeter;
	int Adeter[10][10];

	Determinant(int det[10][10], int size) 
	{
		for (int i = 0; i < size; i++) 
		{
			for (int j = 0; j < size; j++)
			{
				deter[i][j] = det[i][j];
			}
		}
		sizeOfDeter = size;
		value = valueOfDeterminant(deter, sizeOfDeter);
		for (int i = 0; i < size; i++) 
		{
			for (int j = 0; j < size; j++) 
			{
				if ((i + j) % 2 == 0) 
				{
					Adeter[i][j] = valueOfDeterminant(getAdeter(deter, i, j, size), size - 1);
				}
				else 
				{
					Adeter[i][j] = -1 * valueOfDeterminant(getAdeter(deter, i, j, size), size - 1);
				}
			}
		}
	};

	int findMovable(vector<int> v, vector<int> dir, int n);
	vector<int> reverse(vector<int> v1, vector<int> dir, int index);
	void print(int v1[10][10], int size);
	int GetInverseCount(vector<int> sequence, int size);
	vector<int> swap(vector<int> v, int index1, int index2);
	int valueOfDeterminant(int deter[10][10], int sise);
	int valueOfDeterminant(int ** deter, int size);
	int **getAdeter(int deter[10][10], int x, int y, int size);
	int ** Determinant::mul(int d1[10][10], int d2[10][10], int size);

private:

};
