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
	vector<vector<int>> ddeter;

	determinant(vector<int> det) {
		for (int i = 0; i < det.size(); ++i) {
			deter.push_back(det[i]);
			pIndex.push_back(i);
			pDir.push_back(1);
		}
	};

	determinant(vector<vector<int>> det) {
		for (int i = 0; i < det.size(); ++i) {
			pIndex.push_back(i);
			pDir.push_back(1);
		}
		for (int i = 0; i < det.size(); i++) {
			for (int j = 0; j < det.size(); j++){
			ddeter[i, j] = det[i, j];
}
		}
	};

	int findMovable(vector<int> v, vector<int> dir, int n);
	vector<int> reverse(vector<int> v1, vector<int> dir, int index);
	void print(vector<int> v1, vector<int> v2);
	int GetInverseCount(vector<int> sequence, int size);
	vector<int> swap(vector<int> v, int index1, int index2);

private:

};
