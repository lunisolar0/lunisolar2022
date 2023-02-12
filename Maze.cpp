#include<iostream>
#include<cstdlib>
#include<Windows.h>
using namespace std;
int** maze;
int order;
char record[1000];
int top = -1;
typedef struct Location 
{
	int x = 1;
	int y = 1;
};
Location t;

//初始化迷宫
void InitMaze() {
	cout << "请输入正方形迷宫的阶数：";
	cin >> order;
	order = order + 2;
	//创建关系R并赋初值
	maze = new int* [order];
	for (int i = 0; i < order; i++) {
		maze[i] = new int[order];
	}
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			if (i == 0 || j == 0) maze[i][j] = 1;
			else if (i == order - 1 || j == order - 1) maze[i][j] = 1;
			else maze[i][j] = 0;
		}
	}
}

//打印迷宫
void PrintMaze() {
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			if (maze[i][j] == 0 || maze[i][j] == 3) cout << "  ";
			else if (maze[i][j] == 2) cout << "* ";
			else cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//随机生成迷宫地形
void RondomMaze() {
	srand(time(NULL));
	for (int i = 1; i < order - 1; i++) {
		for (int j = 1; j < order - 1; j++) {
			int ran = rand() % 3;
			if (ran == 0) maze[i][j] = 1;
			else maze[i][j] = 0;
		}
	}
	maze[1][1] = 0;
	maze[order - 2][order - 2] = 0;
	int ran = rand() % 2;
	if (ran == 0) maze[1][2] = 0;
	else maze[2][1] = 0;
	ran = rand() % 2;
	if (ran == 0) maze[order - 3][order - 2] = 0;
	else maze[order - 2][order - 3] = 0;
}

//走迷宫
void RunMaze() {
	maze[t.x][t.y] = 2;
	if (maze[t.x + 1][t.y] == 0) {
		t.x++;
		record[++top] = 's';
	}
	else if (maze[t.x][t.y + 1] == 0) {
		t.y++;
		record[++top] = 'd';
	}
	else if (maze[t.x - 1][t.y] == 0) {
		t.x--;
		record[++top] = 'w';
	}
	else if (maze[t.x][t.y - 1] == 0) {
		t.y--;
		record[++top] = 'a';
	}
	else if (maze[order - 2][order - 2] != 2) {
		maze[t.x][t.y] = 3;
		if (record[top] == 'w') {
			t.x++;
			top--;
		}
		else if (record[top] == 'a') {
			t.y++;
			top--;
		}
		else if (record[top] == 's') {
			t.x--;
			top--;
		}
		else if (record[top] == 'd') {
			t.y--;
			top--;
		}
		if (t.x == 1 && t.y == 1 && maze[t.x + 1][t.y] != 0 && maze[t.x][t.y + 1] != 0) {
			system("cls");
			PrintMaze();
			cout << "这是一个死迷宫！" << endl;
			return;
		}
	}
	system("cls");
	PrintMaze();
	if (maze[order - 2][order - 2] == 2) {
		cout << "闯关成功！";
	}
	else RunMaze();
}

//破坏性走迷宫
void BreakMaze() {
	maze[t.x][t.y] = 2;
	if (t.x + 1 == order - 1) {
		if (t.y + 1 != order - 1) maze[t.x][t.y + 1] = 0;
	}
	else if (t.y + 1 == order - 1) {
		if (t.x + 1 != order - 1) maze[t.x + 1][t.y] = 0;
	}
	else if (maze[t.x + 1][t.y] == 1 && maze[t.x][t.y + 1] == 1) {
		maze[t.x][t.y + 1] = 0;
	}
	if (maze[t.x + 1][t.y] != 1) {
		t.x++;
		record[++top] = 's';
	}
	else if (maze[t.x][t.y + 1] != 1) {
		t.y++;
		record[++top] = 'd';
	}
	else if (maze[t.x - 1][t.y] != 1) {
		t.x--;
		record[++top] = 'w';
	}
	else if (maze[t.x][t.y - 1] != 1) {
		t.y--;
		record[++top] = 'a';
	}
	system("cls");
	PrintMaze();
	if (maze[order - 2][order - 2] == 2) {
		cout << "成功通出一条道路！";
		return;
	}
	else BreakMaze();
}

int main() {
	InitMaze();
	PrintMaze();
	RondomMaze();
	PrintMaze();
	RunMaze();
	if (maze[order - 2][order - 2] != 2) {
		cout << "即将采取对迷宫的破坏性措施强行通过！！！" << endl;
		Sleep(2000);
		BreakMaze();
	}
	for (int i = 0; i < order; i++) {
		delete [] maze[i];
	}
	delete[] maze;
	return 0;
}