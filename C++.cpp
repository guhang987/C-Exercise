#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include "object.h"
#include <vector>
using namespace std;
void display(int b[3][3]) {
	cout << "当前棋局：" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			switch (b[i][j])
			{
			case -10:
				cout << "-";
				break;
			case 1:
				cout << "X";
				break;
			case 0:
				cout << "O";
				break;
			default:
				break;
			}
			cout << " ";
		}
		cout << endl;
	}
}
int check(int b[3][3]) {
	/*优化点
	1.如何判断哪方胜？
	2.什么时候开始判断，什么时候必定是平局？
	*/
	for (int i = 0; i < 3; i++) {
		if (b[i][0] + b[i][1] + b[i][2] == 3) return 1;
		if (b[i][0] + b[i][1] + b[i][2] == 0) return 2;
	}
	for (int i = 0; i < 3; i++) {
		if (b[0][i] + b[1][i] + b[2][i] == 3) return 1;
		if (b[0][i] + b[1][i] + b[2][i] == 0) return 2;
	}
	if (b[0][0] + b[1][1] + b[2][2] == 3) return 1;
	if (b[0][0] + b[1][1] + b[2][2] == 0) return 2;
	if (b[2][0] + b[1][1] + b[0][2] == 3) return 1;
	if (b[2][0] + b[1][1] + b[0][2] == 0) return 2;
	return 0;
}
int main() {//优化点：图形化界面

	int checkerboard[3][3] = { {-10,-10,-10},{-10,-10,-10},{-10,-10,-10} };
	
	display(checkerboard);
	int x = -1, y = -1, pos = 1, cnt = 0,num=0;//1表示先手方 X方
	cout << "请X方输入摆放位置：";
	cin >> num;
	x = (num - 1) / 3;
	y = (num - 1) % 3;
	while (1) {//优化点 输入输出如何优化？
		if (pos == 1) checkerboard[x][y] = 1;
		else checkerboard[x][y] = 0;
		cnt++;
		display(checkerboard);
		if (cnt >= 5) {
			int stat= check(checkerboard);//刚开始是不需要检查状态的
			if (stat == 1) { cout << "You(X) Win!" << endl; break; }
			if (stat == 2) { cout << "You(O) Win!" << endl; break; }
		}
		if (cnt == 9) {
			cout << "平局！";
			break;
		}
		pos = ~pos;
		if(pos==1) cout << "请X方输入摆放位置：";
		else cout << "请O方输入摆放位置：";
		cin >> num;
		x = (num - 1) / 3;
		y = (num - 1) % 3;
		while (x < 0 || y < 0 || x>2 || y>2 || checkerboard[x][y] != -10)
		{
			cout << "输入错误请重新输入" << endl;
			cin >> num;
			x = (num - 1) / 3;
			y = (num - 1) % 3;
		}
	}
	return 0;
}