#include<iostream>
#include<stdio.h>
using namespace std;
int main() {
	int order;
	cout << "R是A上的关系，请输入A元素的个数：";
	cin >> order;
	//创建关系R并赋初值
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
	int* y = new int[order * order];//保存有序对
	int n = 0;
	cout << "请输入有序对(输入0,0结束输入)" << endl;
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
	cout << "关系R：" << endl;
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			cout << R[i][j] << " ";
		}
		cout << endl;
	}
	//创建临时关系矩阵tempR并赋初值
	int** tempR = new int* [order];
	for (int i = 0; i < order; i++) {
		tempR[i] = new int[order];
	}
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			tempR[i][j] = 0;
		}
	}



	//求对称闭包
	//将顺序对带入关系矩阵tempR
	for (int i = 0; x[i] != 0; i++) {
		tempR[x[i] - 1][y[i] - 1] = 1;
	}
	for (int i = 0; x[i] != 0; i++) {
		tempR[y[i] - 1][x[i] - 1] = 1;
	}
	//输出对称闭包关系矩阵
	cout << "对称闭包：" << endl;
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			cout << tempR[i][j] << " ";
		}
		cout << endl;
	}
	//临时关系矩阵状态还原
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			tempR[i][j] = 0;
		}
	}



	//求自反闭包
	//将顺序对带入关系矩阵tempR
	for (int i = 0; x[i] != 0; i++) {
		tempR[x[i] - 1][y[i] - 1] = 1;
	}
	//将恒等关系对带入矩阵
	for (int i = 0; i < order; i++) {
		tempR[i][i] = 1;
	}
	//输出自反闭包关系矩阵
	cout << "自反闭包：" << endl;
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			cout << tempR[i][j] << " ";
		}
		cout << endl;
	}
	//临时关系矩阵状态还原
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			tempR[i][j] = 0;
		}
	}



	//求传递闭包
	//创建R2有序对
	int* x2 = new int[order * order];
	int* y2 = new int[order * order];
	//创建R3有序对
	int* x3 = new int[order * order];
	int* y3 = new int[order * order];
	//求R2有序对
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
	//求R3有序对
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
	//将R+R2+R3保存在临时关系矩阵中
	for (int i = 0; x[i] != 0; i++) {
		tempR[x[i] - 1][y[i] - 1] = 1;
	}
	for (int i = 0; x2[i] != 0; i++) {
		tempR[x2[i] - 1][y2[i] - 1] = 1;
	}
	for (int i = 0; x3[i] != 0; i++) {
		tempR[x3[i] - 1][y3[i] - 1] = 1;
	}
	//输出传递闭包关系矩阵
	cout << "传递闭包：" << endl;
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			cout << tempR[i][j] << " ";
		}
		cout << endl;
	}
	//临时关系矩阵状态还原
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			tempR[i][j] = 0;
		}
	}



	//释放R与tempR
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
