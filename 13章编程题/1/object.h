#pragma once
#include <iostream>
class Cd
{
public:
	Cd();
	Cd(const Cd & d);
	Cd(const char *s1, const char *s2, int n, double x);
	virtual ~Cd();
	virtual void Report() const;
	Cd& operator = (const Cd &d);
private:
	char performers[50];
	char label[20];
	int selections;//可选择数
	double playtime;//播放了多少分钟
};
class Classic : public Cd{//这里Bug 忘记加public
public:
	Classic();
	Classic(const char * p,const Classic & d);
	Classic(const char *p,const char * s1,const char *s2, int n, double x);
	~Classic();
	virtual void Report() const;

private:
	char product[40];
};

