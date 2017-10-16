#pragma once
#include<vector>

using namespace std;

enum class Direction : char { Left, Right };

class determinant
{
public:
	determinant(vector<int> det, int size) {
		vector<int> deter = det;
	};

	void OutputSequence(int* pSeq, int* pIndices, int size);
	bool GetNextSeqIndices(int* pIndices, Direction* pDir, int size);
	void GetPermutation(int seqence[], int size);
	int GetInverseCount(int sequence[], int size);

	int deter[100];

private:

};
