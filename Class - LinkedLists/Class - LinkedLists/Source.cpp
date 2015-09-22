#include <iostream>
#include <conio.h>

using namespace std;

template <typename T>
class Node {
public:
	T data;
	Node* forward;
	Node* backward;
};

template <typename T>
class LinkedList {
public:
	LinkedList();
	~LinkedList();
	void insertLast(const T& item);
	void insertFirst(const T& item);
	void deleteFirst();
	void deleteLast();
	void deleteItem(const T& item);
private:
	Node<T>* front;
	Node<T>* back;
	unsigned int count;
};

template <typename T>
LinkedList<T>::LinkedList() {
	front = NULL;
	back = NULL;
	count = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	while (front != NULL)
	{
		Node<T>* temp;
		temp = front;
		front = front->forward;
		delete temp;
	}
	back = NULL;
	count = 0;
}

template <typename T>
void LinkedList<T>::insertLast(const T& item) {
	Node<T>* temp = new Node<T>();
	temp->data = item;
	temp->forward = NULL;
	temp->backward = NULL;
	if (front == NULL)
	{
		//empty list scenario
		front = temp;
	}
	else
	{
		//at least one node scenario
		back->forward = temp;
		temp->backward = back;
	}
	back = temp;
	count++;
}

template <typename T>
void LinkedList<T>::insertFirst(const T& item) {
	Node<T>* temp = new Node<T>();
	temp->data = item;
	temp->forward = NULL;
	temp->backward = NULL;
	if (back == NULL)
	{
		//empty list scenario
		back = temp;
	}
	else
	{
		//at least one node scenario
		front->backward = temp;
		temp->forward = front;
	}
	front = temp;
	count++;
}
template <typename T>
void LinkedList<T>::deleteFirst() {
	if (front == NULL)	// If the list is empty
	{
		return;
	}
	Node<T>* temp = front;
	front = front->forward;
	if (front == NULL)	//If list has only one node
	{
		back = NULL;
	}
	else
	{
		front->backward = NULL;
	}
	delete temp;
	count--;
}

template <typename T>
void LinkedList<T>::deleteLast() {
	if (back == NULL)	// If the list is empty
	{
		return;
	}
	Node<T>* temp = back;
	back = back->backward;
	if (back == NULL)	//If list has only one node
	{
		front = NULL;
	}
	else
	{
		back->forward = NULL;
	}
	delete temp;
	count--;
}

template <typename T>
void LinkedList<T>::deleteItem(const T& item) {
	if (front == NULL)	// empty list scenario
	{
		return;
	}
	Node<T>* cur = front;
	while (cur != NULL && cur->data != item)
	{
		cur = cur->forward;
	}
	if (cur->data == item)
	{
		if (front == back)// single node list
		{
			front = NULL;
			back = NULL;
			cur->forward = NULL;
			cur->backward = NULL;
			delete cur;
			count--;
		}
		if (cur->backward == NULL)// First node scenario
		{
			front = front->forward;
			front->backward = NULL;
			delete cur;
			count--;
			return;
		}
		if (cur->forward == NULL)// Last node scenario
		{
			back = back->backward;
			back->forward = NULL;
			delete cur;
			count--;
			return;
		}
		cur->backward->forward = cur->forward;// Middle node scenario
		cur->forward->backward = cur->backward;
		
		delete cur;
		count--;
	}
}

int main() {

	//Node<int>* n1 = new Node<int>();

	//n1->data = 42; // same as (*n1).data = 42;
	//n1->link = NULL;

	//Node<int>* n2 = new Node<int>();
	//n2->data = 12;
	//n1->link = n2;

	//Node<int>* n3 = new Node<int>();
	//n2->data = 84;
	//n2->link = n3;
	//n3->link = NULL;

	////Get rid of middle node
	//n1->link = n3;
	//delete n2;
	//n2 = NULL;

	LinkedList<int> mylist;
	mylist.insertLast(42);
	mylist.insertLast(12);
	mylist.insertLast(84);
	mylist.insertFirst(32);
	mylist.insertFirst(25);
	mylist.insertFirst(22);
	mylist.deleteItem(12);
	mylist.deleteItem(84);
	mylist.deleteItem(22);

	_getch();
	return 0;

	// 9/14 participation code 841242
	// 9/16 participation code 536837
}