#include <iostream>
#include<string>

using namespace std;

//void Determinant_Multiplication(Determinant a, Determinant b);

struct Determinant {
	int matrix[10][10];
};

void Determinant_Multiplication(Determinant a, Determinant b) {
	Determinant c;
	int a_row = sizeof(a.matrix) / sizeof(a.matrix[0]);
	int a_column = sizeof(a.matrix[0]) / sizeof(a.matrix[0][0]);
	int b_row = sizeof(b.matrix) / sizeof(b.matrix[0]);
	int b_column = sizeof(b.matrix[0]) / sizeof(b.matrix[0][0]);

	for(int i=0;i<a_row;i++)
		for (int j = 0; j < b_column; j++) {
			int sum = 0;
			for (int k = 0; k < a_column; k++) {
				sum = +a.matrix[i][k] * b.matrix[k][j];
			}
			c.matrix[i][j] = sum;
		}
			
		

}

int reverse(int sequence[],int size) {
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


void GetPermutation(int size,int c[10][10]) {
	int count = 0;
	int max;                   //用来存放最大的可移动数字
	int sum = 1;
	int a[10],b[10];   //a数组用来存放数字，b数组用来存放对应数字的方向

	for (int i = 1; i <= size; i++) {
		
		sum = sum*i;                   //根据数字的个数算出全排列的总数

	}

	for (int i = 0; i < size; i++) {
		a[i] = i+1;
		b[i] = 0;                        //0代表向左，1代表向右，一开始所有数字方向默认向左
	}

	while (count<sum) {                                      //当计数未达到全排列数时，继续循环
		int j = 0;
		int index;                                           //用来保存最大可移动数字的数组下标

		for (int i = 0; i < size; i++) {
			c[count][i] = a[i];
		}


		for (int i = 0; i < size; i++) {                     //找到最大的可移动数字
			int j = size;
			if (a[i] == j) {
				if ((b[i] == 1 && i != (size - 1) && a[i] > a[i + 1]) || (b[i] == 0 && i != 0 && a[i] > a[i - 1])) {
					max = a[i];
					index = i;
					break;
				}
				else
					i = -1;
				j--;
			}

		}

		if (b[index] == 0) {                  //根据方向交换数字

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

		for (int i = 0; i < size; i++) {       //改变比移动数字大的数的方向
			if (a[i] > max)
				if (b[i] == 1)
					b[i] = 0;
				else if (b[i] == 0)
					b[i] = 1;
		}


		
		count++;                                //每列出一个排序后计数加一

	}

}


void main() {
	cout << "Thisi is a3" << endl;
}