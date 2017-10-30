#include <iostream>
#include "Vec.h"
using namespace std;

void Print(const Vec& v)
{
	cout << "( ";
	for (int i = 0; i < 3; i++)
	{
		cout << v.elem[i] << " ";
	}
	cout << ")" << endl;
}

void TestVectorSum()
{
	const double v1[3] = { 1,2,3 };
	const double v2[3] = { 3,2,1 };

	Vec vv1(&v1[0]);
	Vec vv2(&v2[0]);
	Vec res = vv1 + vv2;

	Print(vv1);
	Print(vv2);
	Print(res);
}

void TestVectorSub()
{
	const double v1[3] = { 1,2,3 };
	const double v2[3] = { 3,2,1 };

	Vec vv1(&v1[0]);
	Vec vv2(&v2[0]);
	Vec res = vv1 - vv2;

	Print(vv1);
	Print(vv2);
	Print(res);
}

void TestVectorMul()
{
	const double v[3] = { 1,2,3 };

	Vec vv(&v[0]);
	Vec res1 = 2 * vv;
	Vec res2 = vv * 3;

	Print(vv);
	Print(res1);
	Print(res2);
}

void TestVectorDot()
{
	const double v1[3] = { 1,2,3 };
	const double v2[3] = { 3,2,1 };

	Vec vv1(&v1[0]);
	Vec vv2(&v2[0]);
	double res = Dot(vv1,vv2);

	Print(vv1);
	Print(vv2);
	cout << res << endl;
}

void TestVectorCross()
{
	const double v1[3] = { 1,2,3 };
	const double v2[3] = { 3,2,1 };

	Vec vv1(&v1[0]);
	Vec vv2(&v2[0]);
	Vec res = Cross(vv1, vv2);

	Print(vv1);
	Print(vv2);
	Print(res);
}