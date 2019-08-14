#pragma once

class Stack2
{
public:
	struct Element
	{
	public:
		Element(int val, Element* ptr_in)
			:
			val(val),
			pNext(ptr_in)
		{
		}
		int Count();
	public:
		int val;
		Element* pNext;
	};
	Stack2()
		:
		pTop(nullptr)
	{
	}

public:
	void Push(int val);
	int Pop();
	int Size();
	bool Empty();
	void Print();
private:
	Element* pTop;
};