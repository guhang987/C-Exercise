#pragma once
#include <iostream>
using std::ostream;

class Port
{
public:
	Port(const char *br = "none", const char *st = "none", int b = 0);
	Port(const Port &p);
	virtual ~Port();//如果故意不写实现呢---编译失败 无法解析符号
	Port& operator = (const Port &p);
	Port& operator += (const int b);
	Port& operator -= (const int b);
	int BottleCount() const { return bottles; }//简单的函数就可以在声明里面写了？
	virtual void Show() const;
	friend ostream& operator<<(ostream &os, const Port &p);

private:
	char * brand;
	char style[20];
	int bottles;

};

class VintagePort : public Port {
public:
	VintagePort();
	VintagePort(const char *br, int b, const char *nn, int y);
	VintagePort(const VintagePort &vp);
	~VintagePort(){ delete[] nickname; }
	VintagePort &operator=(const VintagePort &vp);
	void Show() const;
	friend ostream & operator<<(ostream &os, const VintagePort &vp);

private:
	char * nickname;
	int year;
};


