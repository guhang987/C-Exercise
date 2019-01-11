#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "object.h"
using std::cin;
using std::cout;
using std::endl;



Stack::Stack(int n)
{
	Pitems = nullptr;
	size = n;
	top = 0;
}

Stack::Stack(const Stack & st)
{
	Pitems = new Item[st.size];
	for (int i = 0; i < st.size; i++) {
		Pitems[i] = st.Pitems[i];
	}
	size = st.size;
	top = st.top;
}

Stack::~Stack()
{
}

bool Stack::isempty() const
{
	return !top;
}

bool Stack::isfull() const
{
	return !(size - top );
}

bool Stack::push(const Item & item)
{
	if (isfull()) return false;
	if (isempty()) {
		Pitems = new Item[1];
		Pitems[0] = item;
		top++;
	}
	else {
		Item *temp = new Item[size + 1];
		memcpy(temp, Pitems, sizeof(Item)*top);
		temp[top] = item;
		top++;
		delete[] Pitems;
		Pitems = temp;
		return true;
	}
}

bool Stack::pop(Item & item)
{
	if (isempty()) return false;
	Item *temp = new Item[top - 1];
	memcpy(temp, Pitems, sizeof(Item)*(top - 1));
	delete[]Pitems;
	Pitems = temp;
	top--;
	return true;
}

Stack & Stack::operator=(const Stack & st)
{
	Pitems = new Item[st.size];
	memcpy(Pitems, st.Pitems, st.size);
	size = st.size;
	top = st.top;
	return *this;// TODO: �ڴ˴����� return ���
}

ostream & operator<<(ostream & os, const Stack & st)
{
	os << "ջ�Ĵ�С��" << st.size << " ջ��ָ�룺" << st.top << "\n";
	os << "|---------|\n";
	for (int i = 0; i < st.top; i++) {
		os << "|��" << st.top - i - 1 << "�㣺" << std::setw(2)<<st.Pitems[st.top - i - 1] << "|\n";
		os << "|---------|\n";
	}
	os << "----------------------------\n";
	return os;// TODO: �ڴ˴����� return ���
}
