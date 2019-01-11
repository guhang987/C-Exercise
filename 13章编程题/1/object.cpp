#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "object.h"
using std::cin;
using std::cout;
using std::endl;

Cd::Cd()
{

}

Cd::Cd(const Cd & d)
{
	memcpy(performers, d.performers, 50);
	memcpy(label, d.label, 20);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd(const char * s1, const char * s2, int n, double x)
{
	strcpy(performers,s1);
	strcpy(label, s2);
	//memcpy(label, s2, 20);
	selections = n;
	playtime = x;
}

Cd::~Cd()
{
}

void Cd::Report() const
{
	cout << "performers:" << performers << endl;
	cout << "label:" << label << endl;
	cout << "selections:" << selections << endl;
	cout << "playtime:" << playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
	memcpy(performers, d.performers, 50);
	memcpy(label, d.label, 20);
	selections = d.selections;
	playtime = d.playtime;
	return *this;// TODO: 在此处插入 return 语句
}

Classic::Classic()
{
}

Classic::Classic(const char * p,const Classic & d):Cd(d)
{
	strcpy(product,p);
}

Classic::Classic(const char * p,const char * s1,const char * s2, int n, double x):Cd(s1,s2,n,x)
{
	strcpy(product,p);//这里Bug 之前是memcpy 然后把奇怪的地方复制过来了。。。
}

Classic::~Classic()
{
}

void Classic::Report() const
{
	Cd::Report();
	cout << "product:" << product << endl;
}
