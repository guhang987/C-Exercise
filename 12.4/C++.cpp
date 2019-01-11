#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include "object.h"
#include <time.h>
using namespace std;
int main() {
	Stack st1(20);
	srand(time(0));
	for (size_t i = 0; i < 10; i++)
	{
		if (!st1.push(rand() % 100))
		{
			cout << "Push error!" << endl;;
		}

	}
	cout << st1;
	Item i;
	st1.pop(i);
	st1.pop(i);
	st1.push(0);
	cout << st1;
	Stack st2(st1);
	cout << st2;
	Stack st3 = st1;
	cout << st3;
	return 0;

}