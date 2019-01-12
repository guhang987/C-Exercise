#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "object.h"
using std::cin;
using std::cout;
using std::endl;

Port::Port(const char * br, const char * st, int b)
{
	int len = strlen(br);
	brand = new char[len + 1];
	strcpy_s(brand, len+1, br);//为什么这里len就出错 说buffer小呢
	len = strlen(st);
	if (len >= 30) return;
	strcpy_s(style, len+1, st);
	bottles = b;
}

Port::~Port()
{
}

Port & Port::operator=(const Port & p)
{
	if (this == &p) return *this;
	brand = new char[strlen(p.brand)+1];
	strcpy(brand, p.brand);
	strcpy_s(style, 20, p.style);
	bottles = p.bottles;
	return *this;
	// TODO: 在此处插入 return 语句
}

Port & Port::operator+=(const int b)
{
	bottles += b;
	return *this;
	// TODO: 在此处插入 return 语句
}

Port & Port::operator-=(const int b)
{
	bottles -= b;
	return *this;
	// TODO: 在此处插入 return 语句
}

void Port::Show() const
{
	cout << "brand: " << brand << endl;
	cout << "style: " << style << endl;
	cout << "bottles: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
	// TODO: 在此处插入 return 语句
}

VintagePort::VintagePort()
{
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y):Port(br,"null",b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort & vp)
{

}

VintagePort::~VintagePort()
{
}
