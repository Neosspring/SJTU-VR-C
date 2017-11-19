#pragma once
class Quaternion
{
public:
	double s, x, y, z;
	Quaternion();
	~Quaternion();
	Quaternion(double s1, double x1, double y1, double z1);
	double Distance();
	Quaternion Inverse();
	Quaternion Conjugate();
	Quaternion Normalized();
	void Display();
	Quaternion operator=(const Quaternion& quaternion1);

};

Quaternion operator+(const Quaternion& quaternion1, const Quaternion& quaternion2);
Quaternion operator-(const Quaternion& quaternion1, const Quaternion& quaternion2);
Quaternion operator*(const Quaternion& quaternion1, const Quaternion& quaternion2);


