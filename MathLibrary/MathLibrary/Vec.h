#pragma once
struct Vec {
	double elem[3]{ 0,0,0 };

	Vec(const double* m)
	{
		for (int i = 0; i < 3; i++) {
			elem[i] = m[i];
		}
	}

	Vec(){}
};
Vec operator+(const Vec &v1, const Vec &v2);
Vec operator-(const Vec &v1, const Vec &v2);
Vec operator*(const int &i, const Vec &v);
Vec operator*(const Vec &v, const int &i);
double Dot(const Vec &v1, const Vec &v2);
Vec Cross(const Vec &v1, const Vec &v2);