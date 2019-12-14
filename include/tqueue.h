#ifndef __TQUEUE_H__
#define __TQUEUE_H__

#include <iostream>
#include <memory>

using namespace std;

const int MAX_SIZE = 10000;

// ОЧЕРЕДЬ НА ЦИКЛИЧЕСКОМ МАССИВЕ
template <class ValType>
class TQueue
{
	unique_ptr <ValType[]> pMem;
	int Size;
	int Top; 
	int Bot;
public:
	TQueue(int s = 6);
//	TQueue(const TQueue &q);
	~TQueue();
	void Pop();                         // убрать элемент
	void Push(ValType elem);            // добавить элемент 
	bool TopBorder();
	bool BotBorder();
	bool IsEmpty();
	bool IsFull();
	void Repack();
//	bool operator==(const TQueue &q) const;
	ValType operator[](int pos);
};

template <class ValType>
TQueue<ValType>::TQueue(int s)
{
	if ((s < 0) || (s > MAX_SIZE)) throw "Error";
	Top = 0;
	Bot = 0;
	Size = s;
	pMem.reset(new ValType[Size]);
}
/*
template <class ValType>
TQueue<ValType>::TQueue(const TQueue<ValType> &q) 
{
	Size = q.Size;
	TopElem = s.TopElem;
	pStack = new ValType[Size];
	for (int i = 0; i < Size; i++)
		pStack[i] = s.pStack[i];
}
*/
template <class ValType>
TQueue<ValType>::~TQueue()
{
}

template <class ValType> 
bool TQueue<ValType>::BotBorder()
{
	if (Bot == 0) return true;
	return false;
}

template <class ValType> 
bool TQueue<ValType>::TopBorder()
{
	if (Top == Size) return true;
	return false;
}

template <class ValType>
bool TQueue<ValType>::IsEmpty()
{
	if ((Bot == 0) && (Top == 0)) return true;
	return false;
}

template <class ValType>
bool TQueue<ValType>::IsFull()
{
	if ((Top == Size) && (Bot == 0)) return true;
	if ((!IsEmpty()) && (Top == Bot)) return true;
	return false;
}

template <class ValType> 
void TQueue<ValType>::Push(ValType elem)
{
	if (IsFull()) Repack();
	if (TopBorder()) Top = 0;
	Top = Top + 1;
	pMem[Top - 1] = elem;
}

template <class ValType> 
void TQueue<ValType>::Pop()
{
	if (IsEmpty()) throw "Error"; 
	if (BotBorder()) Bot = Size;
	Bot = Bot - 1;
}

template <class ValType>
void TQueue<ValType>::Repack()
{
	unique_ptr <ValType[]> ptemp;
	ptemp.reset(new ValType[Size * 2]);
	for (int i = 0; i < Size; i++)
		ptemp[i] = pMem[i];
	Bot = 1;
	Top = Size;
	Size = Size * 2;
	pMem.swap(ptemp);
}

template <class ValType>
ValType TQueue<ValType>::operator[](int pos)
{
	if ((pos < Bot) || (pos > Top)) throw "error";
	return pMem[pos];
}
/*
template <class ValType>
bool TQueue<ValType>::operator==(const TQueue &q) const
{
	bool flag = true;
	if ((Bot != q.Bot) || (Top != q.Top)) return false;
	for (int i = 0; i <= Top; i++)
	{
		if (pMem[i] != q.pMem[i])
		{
			flag = false;
			break;
		}
	}
	return flag;
}
*/


#endif
