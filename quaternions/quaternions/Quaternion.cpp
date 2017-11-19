#include "Quaternion.h"
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
	cout << s << '+' << x << "i+" << y << "j+" << z << 'k' << endl;
}