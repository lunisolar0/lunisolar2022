#include<iostream>
#include<stdio.h>
using namespace std;
int main() {
	int order;
	cout << "R��A�ϵĹ�ϵ��������AԪ�صĸ�����";
	cin >> order;
	//������ϵR������ֵ
	int** R = new int* [order];
	for (int i = 0; i < order; i++) {
		R[i] = new int[order];
	}
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			R[i][j] = 0;
		}
	}
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			cout << R[i][j] << " ";
		}
		cout << endl;
	}
	int* x = new int[order * order];
	int* y = new int[order * order];//���������
	int n = 0;
	cout << "�����������(����0,0��������)" << endl;
	while (1) {
		int tempx, tempy;
		scanf("%d,%d", &tempx, &tempy);
		if (tempx != 0 && tempy != 0) R[tempx - 1][tempy - 1] = 1;
		int flag = 1;
		for (int i = 0; i < n; i++) {
			if (x[i] == tempx && y[i] == tempy) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			x[n] = tempx;
			y[n] = tempy;
			n++;
		}
		if (tempx == 0 && tempy == 0) break;
	};
	cout << "��ϵR��" << endl;
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			cout << R[i][j] << " ";
		}
		cout << endl;
	}
	//������ʱ��ϵ����tempR������ֵ
	int** tempR = new int* [order];
	for (int i = 0; i < order; i++) {
		tempR[i] = new int[order];
	}
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			tempR[i][j] = 0;
		}
	}



	//��ԳƱհ�
	//��˳��Դ����ϵ����tempR
	for (int i = 0; x[i] != 0; i++) {
		tempR[x[i] - 1][y[i] - 1] = 1;
	}
	for (int i = 0; x[i] != 0; i++) {
		tempR[y[i] - 1][x[i] - 1] = 1;
	}
	//����ԳƱհ���ϵ����
	cout << "�ԳƱհ���" << endl;
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			cout << tempR[i][j] << " ";
		}
		cout << endl;
	}
	//��ʱ��ϵ����״̬��ԭ
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			tempR[i][j] = 0;
		}
	}



	//���Է��հ�
	//��˳��Դ����ϵ����tempR
	for (int i = 0; x[i] != 0; i++) {
		tempR[x[i] - 1][y[i] - 1] = 1;
	}
	//����ȹ�ϵ�Դ������
	for (int i = 0; i < order; i++) {
		tempR[i][i] = 1;
	}
	//����Է��հ���ϵ����
	cout << "�Է��հ���" << endl;
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			cout << tempR[i][j] << " ";
		}
		cout << endl;
	}
	//��ʱ��ϵ����״̬��ԭ
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			tempR[i][j] = 0;
		}
	}



	//�󴫵ݱհ�
	//����R2�����
	int* x2 = new int[order * order];
	int* y2 = new int[order * order];
	//����R3�����
	int* x3 = new int[order * order];
	int* y3 = new int[order * order];
	//��R2�����
	n = 0;
	for (int i = 0; y[i] != 0; i++) {
		for (int j = 0; x[j] != 0; j++) {
			if (y[i] == x[j]) {
				x2[n] = x[i];
				y2[n] = y[j];
				n++;
			}
		}
	}
	x2[n] = 0;
	y2[n] = 0;
	//��R3�����
	n = 0;
	for (int i = 0; y2[i] != 0; i++) {
		for (int j = 0; x[j] != 0; j++) {
			if (y2[i] == x[j]) {
				x3[n] = x2[i];
				y3[n] = y[j];
				n++;
			}
		}
	}
	x3[n] = 0;
	y3[n] = 0;
	//��R+R2+R3��������ʱ��ϵ������
	for (int i = 0; x[i] != 0; i++) {
		tempR[x[i] - 1][y[i] - 1] = 1;
	}
	for (int i = 0; x2[i] != 0; i++) {
		tempR[x2[i] - 1][y2[i] - 1] = 1;
	}
	for (int i = 0; x3[i] != 0; i++) {
		tempR[x3[i] - 1][y3[i] - 1] = 1;
	}
	//������ݱհ���ϵ����
	cout << "���ݱհ���" << endl;
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			cout << tempR[i][j] << " ";
		}
		cout << endl;
	}
	//��ʱ��ϵ����״̬��ԭ
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			tempR[i][j] = 0;
		}
	}



	//�ͷ�R��tempR
	for (int i = 0; i < order; i++) {
		delete[] tempR[i];
	}
	delete[]tempR;
	for (int i = 0; i < order; i++) {
		delete[] R[i];
	}
	delete[]R;
	return 0;
}
