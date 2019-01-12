#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include "object.h"
using namespace std;
int main() {
	{
		Port p1;
		Port p2("sss", "ss", 5);
		p2.Show();
		Port p3("ssc", "dc", 43);
		p3 +=3;
		cout << p3;


	}
	return 0;
}
