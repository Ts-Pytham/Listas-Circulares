#pragma once
#include "Node.cpp"
template <class T>
class DoubleCircularList
{
	Node<T>* First;
	Node<T>* Last;
	public:
		DoubleCircularList();
		~DoubleCircularList() {}
		bool IsEmpty();
		void InsertLast(T data);
		void InsertBegin(T data);
		void InsertInOrder(T data);
		int Remove(T data);
		void Show();
		int Quantity();
		T Get(int pos);
		
		
};

