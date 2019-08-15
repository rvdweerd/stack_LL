#pragma once

class Stack2
{
private:
	class Element
	{
	public:
		Element(int val, Element* ptr_in)
			:
			val(val),
			pNext(ptr_in)
		{}
		~Element()
		{
			//if (pNext != nullptr)
			//{
				delete pNext;
				pNext = nullptr;
			//}
		}
		Element(const Element& source)
			:
			val( source.val )
		{
			if (source.pNext == nullptr)
			{
				pNext = nullptr;
			}
			else
			{
				pNext = new Element(*source.pNext);
			}
		}
		int Count() const
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
		int GetVal() const
		{
			return val;
		}
		Element* Disconnect()
		{
			Element* pTemp = pNext;
			pNext = nullptr;
			//delete this; COULD ALSO BE USED INSTEAD OF DELETE IN POP FUNCION
			return pTemp;
		}
		Element* GetNext() const
		{
			return pNext;
		}
		void SetNext(Element* ptr_in)
		{
			pNext = ptr_in;
		}
	private:
		int val;
		Element* pNext= nullptr;
	};
	
public:
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
	Element* pTop = nullptr;
};