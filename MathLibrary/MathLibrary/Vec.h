#pragma once
struct Vec {
	double elem[3]{ 0,0,0 };

	Vec(const double* m)
	{
		for (int i = 0; i < 3; i++) {
			elem[i] = m[i];
		}
	}
	Vec(double x, double y, double z) {
		elem[0] = x;
		elem[1] = y;
		elem[2] = z;
	}

	Vec(){}
};
Vec operator+(const Vec &v1, const Vec &v2);
Vec operator-(const Vec &v1, const Vec &v2);
Vec operator*(const int &i, const Vec &v);
Vec operator*(const Vec &v, const int &i);
double VecDot(const Vec &v1, const Vec &v2);
Vec VecCross(const Vec &v1, const Vec &v2);