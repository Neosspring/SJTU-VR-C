#include "Vector.h"
#include <iostream>
using namespace std;

Vector Vector_valuation(float v[3]) {
	Vector vector;
	vector.vector_x = v[0];
	vector.vector_y = v[1];
	vector.vector_z = v[2];
	return vector;
}

float Vector_dot(Vector v1, Vector v2) {
	float vector_dot = v1.vector_x * v2.vector_x + v1.vector_y * v2.vector_y + v1.vector_z * v2.vector_z;
	return vector_dot;
}

Vector Vector_cross(Vector v1, Vector v2) {
	Vector vector;
	vector.vector_x = v1.vector_y * v2.vector_z - v1.vector_z * v2.vector_y;
	vector.vector_y = v1.vector_z * v2.vector_x - v1.vector_x * v2.vector_z;
	vector.vector_z = v1.vector_x * v2.vector_y - v1.vector_y * v2.vector_x;
	return vector;
}

float Vector_mixed(Vector v1, Vector v2, Vector v3) {
	float vector_mixed;
	vector_mixed=v1.vector_x*v2.vector_y*v3.vector_z + v1.vector_y*v2.vector_z*v3.vector_x + v1.vector_z*v2.vector_x*v3.vector_y - v1.vector_z*v2.vector_y*v3.vector_x - v1.vector_y*v2.vector_x*v3.vector_z - v1.vector_x*v2.vector_z*v3.vector_y;
	return vector_mixed;
}
Vector operator+(Vector v1, Vector v2) {
	Vector vector;
	vector.vector_x = v1.vector_x + v2.vector_x;
	vector.vector_y = v1.vector_y + v2.vector_y;
	vector.vector_z = v1.vector_z + v2.vector_z;
	return vector;
}
Vector operator-(Vector v1, Vector v2) {
	Vector vector;
	vector.vector_x = v1.vector_x - v2.vector_x;
	vector.vector_y = v1.vector_y - v2.vector_y;
	vector.vector_z = v1.vector_z - v2.vector_z;
	return vector;
}
Vector operator*(Vector v1, int number) {
	Vector vector;
	vector.vector_x = v1.vector_x * number;
	vector.vector_y = v1.vector_y * number;
	vector.vector_z = v1.vector_z * number;
	return vector;
}

void Vector_cout(Vector v1) {
	cout << '(' << v1.vector_x << ',' << v1.vector_y << ',' << v1.vector_z << ')' << endl;
}
