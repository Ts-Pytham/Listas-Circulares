#include "DoubleCircularList.hpp"

template <class T>
DoubleCircularList<T>::DoubleCircularList() {
	this->First = NULL;
	this->Last = NULL;
}

template <class T>
bool DoubleCircularList<T>::IsEmpty() {
	return this->First == NULL;
}

template <class T>
void DoubleCircularList<T>::InsertLast(T data) {
	Node<T>* aux = new Node<T>(data);
	if (IsEmpty()) {
		First = aux;
		First->SetNext(aux);
		First->SetPrevious(aux);
		Last = First;
	}
	else {
		Last->SetNext(aux);
		aux->SetNext(First);
		aux->SetPrevious(Last);
		Last = aux;
	}
	Last->SetNext(First);
}

template <class T>
void DoubleCircularList<T>::InsertBegin(T data) {
	Node<T>* aux = new Node<T>(data);
	if (IsEmpty()) {
		First = aux;
		First->SetNext(aux);
		First->SetPrevious(aux);
		Last = First;
	}
	else {
		First->SetPrevious(aux);
		aux->SetNext(First);
		aux->SetPrevious(Last);
		First = aux;
	}
	Last->SetNext(First);
}

template <class T>
void DoubleCircularList<T>::InsertInOrder(T data) {
	if (IsEmpty())
		InsertBegin(data);
	else {
		Node<T>* aux = new Node<T>(data);
		if (aux->GetData() <= First->GetData())
			InsertBegin(data);
		else if (aux->GetData() >= Last->GetData())
			InsertLast(data);
		else {
			Node<T>* p = First;
			Node<T>* q = First;
			do {
				q = p;
				p = p->GetNext();

			} while (p->GetData() < aux->GetData());
			q->SetNext(aux);
			p->SetPrevious(aux);
			aux->SetNext(p);
			aux->SetPrevious(q);
		}
	}
}

template <class T>
int DoubleCircularList<T>::Remove(T data) {
	int Found = 1;
	if (!IsEmpty()) {
		Node<T>* aux = First;

		do {
			if (aux->GetData() == data) {
				Node<T>* delete_node = aux;

				if (First->GetNext() == First)
				{
					/* Borramos cuando solo haya un solo nodo en la lista. */
					First = NULL;
					Last = First;
					delete First;
					return 0;
				}

				if (aux == First) {
					First = First->GetNext();
					First->SetPrevious(Last);
					Last->SetNext(First);
				}
				else if (aux == Last) {
					Last = Last->GetPrevious();
					First->SetPrevious(Last);
					Last->SetNext(First);
				}
				else {
					aux->GetPrevious()->SetNext(aux->GetNext());
					aux->GetNext()->SetPrevious(aux->GetPrevious());
				}
				Found = 0;
				aux = aux->GetNext();
				delete delete_node;
				continue;
			}
			aux = aux->GetNext();
			if (aux == First) break;
		} while (true);
	}
}
template <class T>
int DoubleCircularList<T>::Quantity() {
	if (!IsEmpty()) {
		int i = 0;
		Node<T>* aux = First;
		while (true) {
			++i;
			aux = aux->GetNext();
			if (aux == First)
				return i;
		}
	}
	return 0;
}
template <class T>
void DoubleCircularList<T>::Show() {
	if (!IsEmpty()) {
		Node<T>* aux = First;
		while (true) {
			aux->ShowInfo();
			aux = aux->GetNext();
			if (aux == First)
				break;
		}
	}
}

template <class T>
T DoubleCircularList<T>::Get(int pos) {
	if (!IsEmpty() && pos < Quantity()) {
		Node<T>* aux = First;
		Node<T>* aux2 = Last;
		int i = 0;
		int j = Quantity() - 1;
		while (j >= i) {
			if (i == pos)
				return aux->GetData();
			if (j == pos)
				return aux2->GetData();
			aux = aux->GetNext();
			aux2 = aux2->GetPrevious();
			++i;
			--j;
			if (aux == First || aux2 == Last)
				break;
		}
	}
	return NULL;
}