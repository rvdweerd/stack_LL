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
	//if (!Empty())
	//{
		delete pTop;
		pTop = nullptr;
	//}
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
			/* OPTION ONE
			Element* pOrigin = source.pTop;
			this->pTop = new Element(pOrigin->GetVal(), nullptr);
			Element* pTarget = this->pTop;
						
			while (pOrigin->GetNext() != nullptr)
			{
				pOrigin = pOrigin->GetNext();
				pTarget->SetNext( new Element(pOrigin->GetVal(), nullptr) );
				pTarget = pTarget->GetNext();

			}
			*/
			this->pTop = new Element( *source.pTop );

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
		const int valTemp = pTop->GetVal();
		Element* pOldTop = pTop;
		pTop = pTop->Disconnect();
		delete pOldTop;

		/* ALTERNATIVE WITHOUT DISCONNECT FUNCTION
		Element* pOldTop = pTop;
		pTop = pTop->GetNext();
		
		pOldTop->pNext = nullptr;
		delete pOldTop;
		pOldTop = nullptr; //Necessary?
		*/

		return valTemp;
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
