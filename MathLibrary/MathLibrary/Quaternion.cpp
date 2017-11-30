#include "Quaternion.h"
#include "Vec.h"
#include<math.h>
#include<iostream>

using namespace std;

Quaternion::Quaternion()
{
	s = x = y = z = 0;
}


Quaternion::~Quaternion()
{

}

Quaternion::Quaternion(double s1, double x1, double y1, double z1) {
	s = s1;
	x = x1;
	y = y1;
	z = z1;
}

Quaternion Quaternion:: operator=(const Quaternion& quaternion1) {
	Quaternion quaternion;
	quaternion.s = quaternion1.s;
	quaternion.x = quaternion1.x;
	quaternion.y = quaternion1.y;
	quaternion.z = quaternion1.z;
	return quaternion;
}

Quaternion operator+(const Quaternion& quaternion1, const Quaternion&  quaternion2) {
	Quaternion quaternion3;
	quaternion3.s = quaternion1.s + quaternion2.s;
	quaternion3.x = quaternion1.x + quaternion2.x;
	quaternion3.y = quaternion1.y + quaternion2.y;
	quaternion3.z = quaternion1.z + quaternion2.z;
	return quaternion3;
}

Quaternion operator-(const Quaternion& quaternion1, const Quaternion&  quaternion2) {
	Quaternion quaternion3;
	quaternion3.s = quaternion1.s - quaternion2.s;
	quaternion3.x = quaternion1.x - quaternion2.x;
	quaternion3.y = quaternion1.y - quaternion2.y;
	quaternion3.z = quaternion1.z - quaternion2.z;
	return quaternion3;
}

Quaternion operator*(const Quaternion& quaternion1, const Quaternion& quaternion2) {
	Quaternion quaternion3;
	quaternion3.s = quaternion1.s*quaternion2.s - quaternion1.x*quaternion2.x - quaternion1.y*quaternion2.y - quaternion1.z*quaternion2.z;
	quaternion3.x = quaternion1.s*quaternion2.x + quaternion2.s*quaternion1.x + quaternion1.y*quaternion2.z - quaternion2.y*quaternion1.z;
	quaternion3.y = quaternion1.s*quaternion2.y + quaternion2.s*quaternion1.y + quaternion1.z*quaternion2.x - quaternion2.z*quaternion1.x;
	quaternion3.z = quaternion1.s*quaternion2.z + quaternion2.s*quaternion1.z + quaternion1.x*quaternion2.y - quaternion2.x*quaternion1.y;
	return quaternion3;
}

double Quaternion::Distance() {
	double distance;
	distance = s*s + x*x + y*y + z*z;
	distance = sqrt(distance);
	return distance;
}

Quaternion Quaternion::Normalized() {
	Quaternion quaternion;
	quaternion.s = s / this->Distance();
	quaternion.x = x / this->Distance();
	quaternion.y = y / this->Distance();
	quaternion.z = z / this->Distance();
	return quaternion;
}

Quaternion Quaternion::Conjugate() {
	Quaternion quaternion;
	quaternion.s = s;
	quaternion.x = -x;
	quaternion.y = -y;
	quaternion.z = -z;
	return quaternion;
}

Quaternion Quaternion::Inverse() {
	Quaternion quaternion;
	quaternion.s = s;
	quaternion.x = -x;
	quaternion.y = -y;
	quaternion.z = -z;
	quaternion.s = quaternion.s / this->Distance() / this->Distance();
	quaternion.x = quaternion.x / this->Distance() / this->Distance();
	quaternion.y = quaternion.y / this->Distance() / this->Distance();
	quaternion.z = quaternion.z / this->Distance() / this->Distance();

	return quaternion;
}

void Quaternion::Display() {
	cout << s << ' + ' << x << " i + " << y << " j + " << z << ' k' << endl;
}

double Quaternion::Dot(const Quaternion& q1, const Quaternion& q2) {
	return q1.s*q2.s + q1.x*q2.x + q1.y*q2.y + q1.z*q1.z;
}

double Quaternion::GetAngle(const Quaternion& q1, const Quaternion& q2) {
	Quaternion qq1(q1);
	Quaternion qq2(q2);
	double angle;
	angle = Dot(q1, q2) / (qq1.Distance()*qq2.Distance());
	return angle;
}

Quaternion Quaternion::Cross(const Quaternion& q1, const Quaternion& q2) {
	Vec v1(q1.x, q1.y, q1.z);
	Vec v2(q2.x, q2.y, q2.z);
	double w = q1.s*q2.s - VecDot(v1, v2);
	Vec v = q1.s*v2 + q2.s*v1 + VecCross(v2, v1);
	Quaternion result(w, v.elem[0], v.elem[1], v.elem[2]);
	return result;
}

Quaternion Quaternion::Rotate(const Quaternion& p, const Quaternion& q, const double angle) {

}