#include "Vector.h"
#include <iostream>

using namespace std;

int main() {
	int number = 2;
	float dot;
	float mix;
	float v1[3] = { 1,2,3 };
	float v2[3] = { 1,1,1 };
	float v3[3] = { 2,1,1 };
	Vector vector1 = Vector_valuation(v1);
	Vector vector2 = Vector_valuation(v2);
	Vector vector3 = Vector_valuation(v3);
	cout << "vector1=";
	Vector_cout(vector1);
	cout << "vector2=";
	Vector_cout(vector2);
	cout << "vector3=";
	Vector_cout(vector3);

	dot = Vector_dot(vector1, vector3);
	cout << "vector1 ¡¤ vector2= " << dot << endl;

	Vector vector4 = Vector_cross(vector1, vector2);
	cout << "vector1 ¡Á vector2= ";
	Vector_cout(vector4);

	mix = Vector_mixed(vector1, vector2,vector3);
	cout << "(vector1 ¡Á vector2)¡¤ vector3= " << mix << endl;

	vector4 = vector1 + vector2;
	cout << "vector1 + vector2= ";
	Vector_cout(vector4);

	vector4 = vector1 - vector2;
	cout << "vector1 - vector2= ";
	Vector_cout(vector4);

	vector4 = vector1 * number;
	cout << "vector1 *2=";
	Vector_cout(vector4);


	return 0;
}