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
	int max;                   //����������Ŀ��ƶ�����
	int sum = 1;
	int a[10],b[10];   //a��������������֣�b����������Ŷ�Ӧ���ֵķ���

	for (int i = 1; i <= size; i++) {
		
		sum = sum*i;                   //�������ֵĸ������ȫ���е�����

	}

	for (int i = 0; i < size; i++) {
		a[i] = i+1;
		b[i] = 0;                        //0��������1�������ң�һ��ʼ�������ַ���Ĭ������
	}

	while (count<sum) {                                      //������δ�ﵽȫ������ʱ������ѭ��
		int j = 0;
		int index;                                           //�������������ƶ����ֵ������±�

		for (int i = 0; i < size; i++) {
			c[count][i] = a[i];
		}


		for (int i = 0; i < size; i++) {                     //�ҵ����Ŀ��ƶ�����
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

		if (b[index] == 0) {                  //���ݷ��򽻻�����

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

		for (int i = 0; i < size; i++) {       //�ı���ƶ����ִ�����ķ���
			if (a[i] > max)
				if (b[i] == 1)
					b[i] = 0;
				else if (b[i] == 0)
					b[i] = 1;
		}


		
		count++;                                //ÿ�г�һ������������һ

	}

}


void main() {
	cout << "Thisi is a3" << endl;
}