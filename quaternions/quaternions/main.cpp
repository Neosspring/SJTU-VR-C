#include "Quaternion.h"
#include<iostream>

using namespace std;

int main() {
	Quaternion quaternion(1,4,4,-4);
	Quaternion quaternion1(1, 1, 1, 1);
	cout << "quaternion=";
	quaternion.Display();
	cout << "quaternion1=";
	quaternion1.Display();

	Quaternion quaternion3 = quaternion + quaternion1;
	cout << "quaternion+quaternion1=";
	quaternion3.Display();

	Quaternion quaternion4 = quaternion - quaternion1;
	cout << "quaternion-quaternion1=";
	quaternion4.Display();

	double len = quaternion.Distance();
	cout << "quaternion�ĳ���Ϊ" << len << endl;

	Quaternion quaternion5 = quaternion.Normalized();
	cout << "quaternion��һ����Ϊ��";
	quaternion5.Display();

	Quaternion quaternion6 = quaternion.Conjugate();
	cout << "quaternion�Ĺ�����Ԫ��Ϊ��";
	quaternion6.Display();

	Quaternion quaternion7 = quaternion.Inverse();
	cout << "quaternion����Ϊ��";
	quaternion7.Display();


	return 0;
}