#include "Stack.h"

void Stack::Push(int val)
{
	pNext = new Element(val,pNext);
}

int Stack::Pop()
{
	if (pNext == nullptr)
	{
		return -1;
	}
	else
	{
		int val = pNext->val;
		Element* pOld = pNext;
		pNext = pNext->pNext;
		delete pOld;
		return val;
	}
}

int Stack::Size() const
{
	Element* ptr = pNext;
	int count = 0;
	while (ptr != nullptr)
	{
		ptr = ptr->pNext;
		count++;
	}
	return count;
}

bool Stack::Empty() const
{
	return (pNext == nullptr);
}
