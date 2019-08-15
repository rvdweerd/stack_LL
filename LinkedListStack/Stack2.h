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
	Stack2();
	Stack2(Element* ptr);
	~Stack2();
	Stack2(const Stack2& source);
	Stack2& operator=(const Stack2& source);


public:
	void Push(int val);
	int Pop();
	int Size() const;
	bool Empty() const;
	void Print() const;
private:
	Element* pTop;
};