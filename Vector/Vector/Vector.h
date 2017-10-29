#pragma once
struct Vector
{
	float vector_x, vector_y, vector_z;
}; 

Vector Vector_valuation(float v[3]);
float Vector_dot(Vector v1,Vector v2);
Vector Vector_cross(Vector v1, Vector v2);
float Vector_mixed(Vector v1, Vector v2,Vector vector3);
Vector operator+(Vector v1, Vector v2);
Vector operator-(Vector v1, Vector v2);
Vector operator*(Vector v1, int number);
void Vector_cout(Vector v1);


	
	



