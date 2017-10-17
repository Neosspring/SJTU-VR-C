#pragma once
#include<vector>
#include<iostream>

using namespace std;

class determinant
{
public:
	vector<int> deter;
	vector<int> pIndex;
	vector<int> pDir;
	int ddeter[10][10];

	determinant(vector<int> det) {
		for (int i = 0; i < det.size(); ++i) {
			deter.push_back(det[i]);
			pIndex.push_back(i);
			pDir.push_back(1);
		}
	};

	determinant(int det[10][10], int size) {
		for (int i = 0; i < size; ++i) {
			pIndex.push_back(i);
			pDir.push_back(1);
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++){
				ddeter[i][j] = det[i][j];
			}
		}
	};

	int findMovable(vector<int> v, vector<int> dir, int n);
	vector<int> reverse(vector<int> v1, vector<int> dir, int index);
	void print(vector<int> v1, vector<int> v2);
	void determinant::print(int v1[10][10], int size);
	int GetInverseCount(vector<int> sequence, int size);
	vector<int> swap(vector<int> v, int index1, int index2);

private:

};
