#pragma once

class Stack
{
public:
	class Element
	{
	public:
		Element() = default;
		Element(int val, Element* pNext)
			:
			val(val),
			pNext(pNext)
		{
		}
		/*
		~Element()
		{
			pNext = nullptr;
		}
		*/
	public:
		int val;
		Element* pNext = nullptr;
	};
	
	Stack() 
		:
		pNext(nullptr)
	{
	}
	~Stack()
	{
		while (pNext != nullptr)
		{
			Element* pOld = pNext;
			pNext = pNext->pNext;
			
			pOld->pNext = nullptr;
			delete pOld;
		}
	}
	Stack(const Stack& source)
	{
		int count = source.Size();
		for (int i = count-1; i >= 0; i--)
		{
			Element* ptr = source.pNext;
			for (int j = i; j > 0; j--)
			{
				ptr = ptr->pNext;
			}
			Push(ptr->val);
		}
	}
	Stack& operator=(const Stack& source)
	{
		if (this != &source)
		{
			while (this->pNext != nullptr)
			{
				Element* pOld = this->pNext;
				this->pNext = this->pNext->pNext;

				pOld->pNext = nullptr;
				delete pOld;
			}

			int count = source.Size();
			for (int i = count - 1; i >= 0; i--)
			{
				Element* ptr = source.pNext;
				for (int j = i; j > 0; j--)
				{
					ptr = ptr->pNext;
				}
				Push(ptr->val);
			}
		}
		return *this;
	}

public:
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;


private:
	Element* pNext = nullptr;
};