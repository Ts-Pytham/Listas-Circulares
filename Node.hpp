#pragma once
#include <iostream>
template <class T>
class Node
{
	private:
		Node<T>* Next;
		Node<T>* Previous;
		T Data;
	public:
		Node();
		Node(T data);
		~Node() {}
		void ShowInfo();
		Node<T>* GetNext();
		Node<T>* GetPrevious();
		T GetData();
		void SetNext(Node<T>* Next);
		void SetPrevious(Node<T>* Previous);
		void SetData(T Data);
};

