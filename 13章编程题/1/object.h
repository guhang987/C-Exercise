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
	int selections;//��ѡ����
	double playtime;//�����˶��ٷ���
};
class Classic : public Cd{//����Bug ���Ǽ�public
public:
	Classic();
	Classic(const char * p,const Classic & d);
	Classic(const char *p,const char * s1,const char *s2, int n, double x);
	~Classic();
	virtual void Report() const;

private:
	char product[40];
};

