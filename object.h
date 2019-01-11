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
	friend ostream& operator<<(ostream &os, const Stack &st);//把字符串st赋给输出流os
private:
	enum { MAX = 10 };
	Item * Pitems;//存放item\ 栈的元素 
	int size;
	int top;
};

