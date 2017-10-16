#include "determinant.h"
#include<vector>
#include<iostream>

using namespace std;

void determinant::OutputSequence(int* pSeq, int* pIndices, int size)
{
	cout << "{";
	for (int i = 0; i < size; i++)
		cout << pSeq[pIndices[i]] << ", ";
	cout << "}" << endl;
}

bool determinant::GetNextSeqIndices(int* pIndices, Direction* pDir, int size)
{
	int maxMvIdx = -1;
	// find max moveable number

	for (int i = 0; i < size; i++)
	{
		if (maxMvIdx < 0 || pIndices[i] > pIndices[maxMvIdx])
		{
			if (pDir[i] == Direction::Left && i > 0 && pIndices[i] > pIndices[i - 1])
				maxMvIdx = i;
			else if (pDir[i] == Direction::Right && i < size - 1 && pIndices[i] > pIndices[i + 1])
			{
				maxMvIdx = i;
				i++;
			}
		}
	}
	if (maxMvIdx == -1)
		return false;
	// move number and change direction 

	for (int i = 0; i < size; i++)
	{
		if (i == maxMvIdx)
		{
			int swapIdx = pDir[i] == Direction::Left ? i - 1 : i + 1;
			std::swap(pIndices[swapIdx], pIndices[i]);
			std::swap(pDir[swapIdx], pDir[i]);
			maxMvIdx = swapIdx;
			if (maxMvIdx > i)
				i++;

		}
		else if (pIndices[i] > pIndices[maxMvIdx])
			pDir[i] = pDir[i] == Direction::Left ? Direction::Right : Direction::Left;
	}
	return true;
}

void determinant::GetPermutation(int seqence[], int size)
{
	int* pIndex = new int[size];
	Direction* pDir = new Direction[size];
	for (int i = 0; i < size; i++)
	{
		pIndex[i] = i;
		pDir[i] = Direction::Left;
	}
	do {

		OutputSequence(seqence, pIndex, size);

	} while (GetNextSeqIndices(pIndex, pDir, size));

	delete[] pIndex;
	delete[] pDir;

}

int determinant::GetInverseCount(int sequence[], int size)
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
