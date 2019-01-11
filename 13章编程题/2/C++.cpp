#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include "object.h"
void Bravo(const Cd&disk);
using namespace std;
int main() {
	{
		Cd c1("Beatles", "Capitol", 14, 35.5);
		Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",//这里Bug 因为定义处没加const
			"Alfred Brendel", "Philips", 2, 57.17);
		Cd *pcd;

		cout << "Using object directly:\n";
		c1.Report();
		c2.Report();

		cout << "Using type cd * pointer to objects:\n";
		pcd = &c1;
		pcd->Report();
		pcd = &c2;
		pcd->Report();

		cout << "Calling a function whit a cd reference argument:\n";
		Bravo(c1);
		Bravo(c2);

		cout << "Testing assignment: ";
		Classic copy;
		copy = c2;
		copy.Report();
	
	}
	return 0;
}

void Bravo(const Cd & disk)
{
	disk.Report();
}
