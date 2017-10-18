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

int Determinant::findMovable(vector<int> v, vector<int> dir, int n) 
{
	int max = -1;
	for (int i = 0; i < n; i++) 
	{
		if (max<0 || v[i]>v[max]) 
		{
			if (dir[i] == 1 && i > 0 && v[i] > v[i - 1]) 
			{
				max = i;
			}
			else if (dir[i] == 0 && i < n - 1 && v[i] > v[i + 1]) 
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

//Determinant::operator * (int d1[10][10], int d2[10][10])
//{
//
//}