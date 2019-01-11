#pragma once
#include <iostream>
typedef unsigned long Item;
using std::ostream;
class Stack
{
public:
	Stack(int n = MAX);
	Stack(const Stack & st);
	~Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item & item);
	bool pop(Item & item);
	Stack & operator  =(const Stack &st);
	friend ostream& operator<<(ostream &os, const Stack &st);//���ַ���st���������os
private:
	enum { MAX = 10 };
	Item * Pitems;//���item\ ջ��Ԫ�� 
	int size;
	int top;
};

