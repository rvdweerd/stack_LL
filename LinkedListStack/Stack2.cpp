#include "Stack2.h"
#include "Chilistring.h"

void Stack2::Push(int val)
{
	pTop = new Element(val,pTop);
}

int Stack2::Pop()
{
	if ( Empty() )
	{
		return -1;
	}
	else
	{
		Element* p_tmp = pTop;
		pTop = pTop->pNext;
		//p_tmp->pNext = nullptr; //Necessary?
		delete p_tmp;
		p_tmp = nullptr;
	}
}

int Stack2::Size()
{
	if ( Empty() )
	{
		return 0;
	}
	else
	{
		return pTop->Count();
	}
}

bool Stack2::Empty()
{
	return (pTop==nullptr);
}

void Stack2::Print()
{
	chili::print("test");
}

int Stack2::Element::Count()
{
	if (pNext == nullptr)
	{
		return 1;
	}
	else
	{
		return pNext->Count() + 1;
	}
}
