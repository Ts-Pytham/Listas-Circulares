#include "Node.hpp"

template<class T>
Node<T>::Node() {
	this->Next = NULL;
	this->Previous = NULL;
}

template <class T>
Node<T>::Node(T data) {
	this->Data = data;
	this->Next = NULL;
	this->Previous = NULL;
}

template <class T>
Node<T>* Node<T>::GetNext() {
	return this->Next;
}

template <class T>
void Node<T>::SetNext(Node<T>* Next) {
	this->Next = Next;
}

template <class T>
Node<T>* Node<T>::GetPrevious() {
	return this->Previous;
}

template <class T>
void Node<T>::SetPrevious(Node<T>* Previous) {
	this->Previous = Previous;
}

template <class T>
T Node<T>::GetData() {
	return this->Data;
}

template <class T>
void Node<T>::SetData(T Data) {
	this->Data = Data;
}

template <class T>
void Node<T>::ShowInfo() {
	std::cout << " " << this->Data << std::endl;
}