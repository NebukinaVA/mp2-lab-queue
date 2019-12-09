#ifndef __TQUEUE_H__
#define __TQUEUE_H__

#include <iostream>
#include <memory>

using namespace std;

const int MAX_STACK_SIZE = 10000;

// ОЧЕРЕДЬ НА ЦИКЛИЧЕСКОМ МАССИВЕ
template <class ValType>
class TQueue
{
	unique_ptr <ValType[]> pMem;
	int Size;
	int Top; //пусть указывает на элемент + 1
	int Bot;
public:
	TQueue(int s = 6);
	~TQueue();
	void Pop();                         // убрать элемент
	void Push(ValType elem);            // добавить элемент 
	bool TopBorder();
	bool BotBorder();
	bool IsEmpty();
	bool IsFull();
};

template <class ValType>
TQueue<ValType>::TQueue(int s)
{
	if ((s < 0) || (s > MAX_STACK_SIZE)) throw "Error";
	Top = -1;
	Bot = -1;
	Size = s;
	pMem.reset(new ValType[Size]);
}

template <class ValType>
TQueue<ValType>::~TQueue()
{
}

template <class ValType> 
bool TQueue<ValType>::BotBorder()
{
	if (Bot == -1) return true;
	return false;
}

template <class ValType> 
bool TQueue<ValType>::TopBorder()
{
	if (Top == Size - 1) return true;
	return false;
}

template <class ValType>
bool TQueue<ValType>::IsEmpty()
{
	if ((Bot == -1) && (Top == -1)) return true;
	return false;
}

template <class ValType>
bool TQueue<ValType>::IsFull()
{
	if ((Top == Size - 1) && (Bot == 0)) return true;
	if ((!IsEmpty()) && (Top == Bot)) return true;
	return false;
}

template <class ValType> 
void TQueue<ValType>::Push(ValType elem)
{
	if (IsFull()) throw "Error"; //repack
	if (TopBorder()) Top = -1;
	Top = Top + 1;
	pMem[Top] = elem;
}

template <class ValType> 
void TQueue<ValType>::Pop()
{
	if (IsEmpty()) throw "Error"; 
	if (BotBorder()) Bot = Size;
	Bot = Bot - 1;
}


#endif
