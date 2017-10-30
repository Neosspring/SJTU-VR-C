#include "Vec.h"

Vec operator+(const Vec &v1, const Vec &v2)
{
	Vec res;
	for (int i = 0; i < 3; i++) {
		res.elem[i] = v1.elem[i] + v2.elem[i];
	}
	return res;
}

Vec operator-(const Vec &v1, const Vec &v2)
{
	Vec res;
	for (int i = 0; i < 3; i++) {
		res.elem[i] = v1.elem[i] - v2.elem[i];
	}
	return res;
}

Vec operator*(const int &k, const Vec &v)
{
	Vec res;
	for (int i = 0; i < 3; i++) {
		res.elem[i] = v.elem[i] * k;
	}
	return res;
}

Vec operator*(const Vec &v, const int &i)
{
	return i * v;
}

double Dot(const Vec &v1, const Vec &v2)
{
	double res = 0;
	for (int i = 0; i < 3; i++)
	{
		res += v1.elem[i] * v2.elem[i];
	}
	return res;
}

Vec Cross(const Vec &v1, const Vec &v2)
{
	Vec res;
	res.elem[0] = v1.elem[1] * v2.elem[2] - v1.elem[2] * v2.elem[1];
	res.elem[1] = v1.elem[2] * v2.elem[0] - v1.elem[0] * v2.elem[2];
	res.elem[2] = v1.elem[0] * v2.elem[1] - v1.elem[1] * v2.elem[0];
	return res;
}