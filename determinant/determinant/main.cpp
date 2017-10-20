#include <iostream>
#include<string>
#include<math.h>

using namespace std;



struct Determinant {
	int matrix[2][2];
};

void Determinant_Multiplication(Determinant a, Determinant b) {
	Determinant c;
	int a_row = sizeof(a.matrix) / sizeof(a.matrix[0]);
	int a_column = sizeof(a.matrix[0]) / sizeof(a.matrix[0][0]);
	int b_row = sizeof(b.matrix) / sizeof(b.matrix[0]);
	int b_column = sizeof(b.matrix[0]) / sizeof(b.matrix[0][0]);

	for (int i = 0; i<a_row; i++)
		for (int j = 0; j < b_column; j++) {
			int sum = 0;
			for (int k = 0; k < a_column; k++) {
				sum = sum + a.matrix[i][k] * b.matrix[k][j];
			}
			c.matrix[i][j] = sum;
		}
	for (int i = 0; i < a_row; i++) {
		for (int j = 0; j < b_row; j++)
			cout << c.matrix[i][j] << " ";
		cout << endl;
	}

	//cout << c.matrix[0][1];



}

int reverse(int sequence[], int size) {
	int result = 0;

	for (int index1 = 0; index1 < size; index1++) {
		for (int index2 = index1 + 1; index2 < size; index2++) {
			if (sequence[index1] > sequence[index2]) {
				result++;
			}
		}
	}
	return result;
}


int GetPermutation(int size, int sequence[2][2]) {
	int count = 0;
	int max;
	int sum = 1;
	int a[2], b[2];

	for (int i = 1; i <= size; i++) {

		sum = sum*i;

	}

	for (int i = 0; i < size; i++) {

		b[i] = 0;
		a[i] = i + 1;
	}

	while (count<sum) {
		int j = 0;
		int index;
		int max_number = size;

		for (int i = 0; i < size; i++) {
			sequence[count][i] = a[i];
		}
		for (int i = 0; i < size; i++) {
			if (a[i] == max_number) {
				if ((b[i] == 1 && i != (size - 1) && a[i] > a[i + 1]) || (b[i] == 0 && i != 0 && a[i] > a[i - 1])) {
					max = a[i];
					index = i;
					break;
				}
				else
					i = -1;
				max_number--;
			}
		}

		if (b[index] == 0) {

			a[index] = a[index - 1];
			a[index - 1] = max;
			int temp1 = b[index];
			b[index] = b[index - 1];
			b[index - 1] = temp1;

		}
		else if (b[index] == 1) {
			a[index] = a[index + 1];
			a[index + 1] = max;
			int temp2 = b[index];
			b[index] = b[index + 1];
			b[index + 1] = temp2;

		}

		for (int i = 0; i < size; i++) {
			if (a[i] > max)
				if (b[i] == 1)
					b[i] = 0;
				else if (b[i] == 0)
					b[i] = 1;
		}
		count++;
	}
	return count;
}

int determinat_value(Determinant a) {
	int result = 0;
	int number = sizeof(a.matrix[0]) / sizeof(a.matrix[0][0]);
	int sort[2][2], b[5];
	int count = GetPermutation(number, sort);
	for (int i = 0; i < count; i++) {
		int result1 = 1;
		for (int j = 0; j < number; j++) {
			b[j] = sort[i][j];
		}
		for (int k = 0; k<number; k++)
			result1 = result1*a.matrix[k][b[k] - 1];

		result = result + pow(-1, reverse(b, number))*result1;
	}

	return result;
}


int main() {
	Determinant a = { 1,2,3,4 };
	Determinant b = { 1,2,3,4 };

	cout << "行列式a：" << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			cout << a.matrix[i][j] << ' ';
		cout << endl;
	}
	cout << endl;

	cout << "行列式b：" << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			cout << b.matrix[i][j] << ' ';
		cout << endl;
	}
	cout << endl;

	cout << "行列式a,b相乘后的结果为：" << endl;
	Determinant_Multiplication(a, b);

	int c[2][2];
	int d = GetPermutation(2, c);
	cout << endl;

	cout << "行列式a的值为：" << determinat_value(a);




	return 0;
}