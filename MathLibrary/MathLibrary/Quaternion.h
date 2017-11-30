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
	double Dot(const Quaternion& q1,const Quaternion& q2);
	double GetAngle(const Quaternion& q1, const Quaternion& q2);
	Quaternion Cross(const Quaternion& q1, const Quaternion& q2);
	Quaternion Rotate(const Quaternion& p, const Quaternion& q, const double angle);
};

Quaternion operator+(const Quaternion& quaternion1, const Quaternion& quaternion2);
Quaternion operator-(const Quaternion& quaternion1, const Quaternion& quaternion2);
Quaternion operator*(const Quaternion& quaternion1, const Quaternion& quaternion2);


