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

	int len = strlen(d.performers);
	performers = new char[len + 1];
	memcpy(performers, d.performers, len);
	performers[len] = '\0';
	len = strlen(d.label);
	label = new char[len + 1];
	memcpy(label, d.label, len);
	label[len] = '\0';
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd(const char * s1, const char * s2, int n, double x)
{

	int len = strlen(s1);
	performers = new char[len + 1];
	memcpy(performers, s1, len);
	performers[len] = '\0';
	len = strlen(s2);
	label = new char[len + 1];
	memcpy(label, s2, len);
	label[len] = '\0';
	selections = n;
	playtime = x;
}

Cd::~Cd()
{
	delete[] performers;
	delete[] label;
	performers = nullptr;
	label = nullptr;
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
	if (this == &d) return *this;
	delete[] performers;
	delete[] label;
	int len = strlen(d.performers);
	performers = new char[len + 1];
	memcpy(performers, d.performers, len);
	performers[len] = '\0';
	len = strlen(d.label);
	label = new char[len + 1];
	memcpy(label, d.label, len);
	label[len] = '\0';
	selections = d.selections;
	playtime = d.playtime;
	return *this;// TODO: 在此处插入 return 语句
}

Classic::Classic()
{
	product = new char[1];
	product[0] = '\0';
}

Classic::Classic(const char * p, const Cd & d) :Cd(d)
{
	int len = strlen(p);
	product = new char[len + 1];
	strcpy(product, p);
	product[len] = '\0';
}

Classic::Classic(const char * p, const char * s1, const char * s2, int n, double x) :Cd(s1, s2, n, x)
{
	int len = strlen(p);
	product = new char[len + 1];
	strcpy(product, p);
	product[len] = '\0';
}

Classic::Classic(const Classic & c):Cd(c)
{
	int len = strlen(c.product);
	product = new char[len + 1];
	strcpy(product, c.product);
	product[len] = '\0';
}

Classic & Classic::operator=(const Classic & d)
{
	if (this == &d) return *this;
	Cd::operator=(d);
	delete[] product;//why delete
	int len = strlen(d.product);
	product = new char[len + 1];
	strcpy(product, d.product);
	product[len] = '\0';
	return *this;// TODO: 在此处插入 return 语句
}

Classic::~Classic()
{
	delete[] product;
}

void Classic::Report() const
{
	Cd::Report();
	cout << "product:" << product << endl;
}
