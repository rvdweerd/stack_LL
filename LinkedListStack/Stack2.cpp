#include "Stack2.h"
#include "Chilistring.h"

Stack2::Stack2()
	:
	pTop(nullptr)
{
}

Stack2::Stack2(Element* ptr)
	:
	pTop(ptr)
{
}

Stack2::~Stack2()
{
	if (!Empty())
	{
		delete pTop;
		pTop = nullptr;
	}
}

Stack2::Stack2(const Stack2& source)
{
	*this = source;
}

Stack2& Stack2::operator=(const Stack2& source)
{
	if (this != &source)
	{
		if (!this->Empty())
		{
			delete pTop;
			this->pTop = nullptr;
		}
		if (source.Empty())
		{
			this->pTop = nullptr;
		}
		else
		{
			Element* pOrigin = source.pTop;
			this->pTop = new Element(pOrigin->val, nullptr);
			Element* pTarget = this->pTop;
						
			while (pOrigin->pNext != nullptr)
			{
				pOrigin = pOrigin->pNext;
				pTarget->pNext = new Element(pOrigin->val, nullptr);
				pTarget = pTarget->pNext;

			}
		}
	}
	return *this;
}

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
		int val = pTop->val;
		Element* p_tmp = pTop;
		pTop = pTop->pNext;
		
		p_tmp->pNext = nullptr;
		delete p_tmp;
		p_tmp = nullptr; //Necessary?
		
		return val;
	}
}

int Stack2::Size() const
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

bool Stack2::Empty() const
{
	return (pTop==nullptr);
}

void Stack2::Print() const
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
