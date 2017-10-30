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