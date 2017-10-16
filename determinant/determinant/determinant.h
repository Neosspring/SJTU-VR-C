#pragma once
#include<vector>
#include<iostream>

using namespace std;

enum class Direction : char { Left, Right };

class determinant
{
public:
	vector<int> deter;
	vector<int> pIndex;
	vector<int> pDir;

	determinant(vector<int> det) {		
		for (int i = 0; i < det.size(); ++i) {
			deter.push_back(det[i]);
			pIndex.push_back(i);
			pDir.push_back(1);
		}
	};

	int findMovable(vector<int> v1, vector<int> dir, int n);
	vector<int> reverse(vector<int> v1, vector<int> dir, int index);
	void print(vector<int> v1, vector<int> v2);
	int GetInverseCount(vector<int> sequence, int size);

private:

};
