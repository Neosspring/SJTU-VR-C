#include <utility>
#include "Determinant.h"

int GetInverseCount(const Sequence&  seq)
{
	int count{ 0 };
	for (int i = 0; i < seq.count - 1; i++)
	{
		for (int j = i + 1; j < seq.count; j++)
		{
			if (seq.index[i] > seq.index[j])
				++count;
		}
	}
	return count;
}

bool Next(Sequence&  seq)
{
	int maxMvIdx = -1;
	// find max moveable number

	for (int i = 0; i <seq.count; i++)
	{
		if (maxMvIdx < 0 || seq.index[i] > seq.index[maxMvIdx])
		{
			if (seq.dir[i] == Direction::Left && i > 0 && seq.index[i] > seq.index[i - 1])
				maxMvIdx = i;
			else if (seq.dir[i] == Direction::Right && i < seq.count - 1 && seq.index[i] > seq.index[i + 1])
			{
				maxMvIdx = i;
				i++;
			}
		}
	}
	if (maxMvIdx == -1)
		return false;
	// move number and change direction 

	for (int i = 0; i < seq.count; i++)
	{
		if (i == maxMvIdx)
		{
			int swapIdx = seq.dir[i] == Direction::Left ? i - 1 : i + 1;
			std::swap(seq.index[swapIdx], seq.index[i]);
			std::swap(seq.dir[swapIdx], seq.dir[i]);
			maxMvIdx = swapIdx;
			if (maxMvIdx > i)
				i++;

		}
		else if (seq.index[i] >  seq.index[maxMvIdx])
			seq.dir[i] = seq.dir[i] == Direction::Left ? Direction::Right : Direction::Left;
	}
	return true;
}


double Evaluate(const Determinant& dm)
{
	Sequence perm(dm.order);
	double value = 0;
	do {
		double unitProduct = 1.0;
		for (int i = 0; i < dm.order; i++)
		{
			unitProduct *= dm.elem[i][perm.index[i]];
		}
		int inverse = GetInverseCount(perm);

		if (inverse & 0x01) //odd number
			unitProduct = -unitProduct;
		value += unitProduct;
	} while (Next(perm));
	return value;
}

Determinant operator* (const Determinant& dm1, const Determinant& dm2)
{
	// Assume the orders between two determinant are same. 
	// We should throw a exception if not 
	Determinant res;
	for (int i = 0; i < dm1.order; i++)
		for (int j = 0; j < dm1.order; j++)
		{
			res.elem[i][j] = 0.0;
			for (int k = 0; k < dm1.order; k++)
				res.elem[i][j] += dm1.elem[i][k] * dm2.elem[k][j];
		}
	res.order = dm1.order;
	return res;
}

double GetCofactor(const Determinant& dm, int row, int col)
{
	Determinant subDm;
	for (int i = 0, m = 0; i < dm.order; i++)
	{
		if (i == row)
			continue; //skip row
		for (int j = 0, n = 0; j < dm.order; j++)
		{
			if (j == col)
				continue; // skip col 
			subDm.elem[m][n++] = dm.elem[i][j];
		}
		m++;
	}
	subDm.order = dm.order - 1;
	double cofac = Evaluate(subDm);
	return ((row + col) & 0x01) ? -cofac : cofac;
}

Determinant GetCofactors(const Determinant& dm)
{
	Determinant res;
	res.order = dm.order;
	for (int i = 0; i < dm.order; i++)
		for (int j = 0; j < dm.order; j++)
			res.elem[i][j] = GetCofactor(dm, i, j);
	return res;
}
