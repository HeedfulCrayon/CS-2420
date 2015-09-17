#include <iostream>
#include <conio.h>

using namespace std;

template <typename T>
class Node {
public:
	T data;
	Node* link;
};

template <typename T>
class LinkedList {
public:
	LinkedList();
	//~LinkedList();
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
void LinkedList<T>::insertLast(const T& item) {
	Node<T>* temp = new Node<T>();
	temp->data = item;
	temp->link = NULL;
	if (front == NULL)
	{
		//empty list scenario
		front = temp;
	}
	else
	{
		//at least one node scenario
		back->link = temp;
	}
	back = temp;
	count++;
}

template <typename T>
void LinkedList<T>::insertFirst(const T& item) {
	Node<T>* temp = new Node<T>();
	temp->data = item;
	temp->link = front;
	front = temp;
	if (back == NULL)
	{
		back = temp;
	}
	count++;
}
template <typename T>
void LinkedList<T>::deleteFirst() {
	if (front == NULL)	// If the list is empty
	{
		return;
	}
	Node<T>* temp = front;
	front = front->link;
	if (front == NULL)	//If list has only one node
	{
		back = NULL;
	}
	delete temp;
	count--;
}

template <typename T>
void LinkedList<T>::deleteLast() {
	if (front == NULL)	// empty list scenario
	{
		return;
	}
	if (front == back)	// one node scenario
	{
		delete back;
		front = NULL;
		back = NULL;
		count--;
		return;
	}
	Node<T>* cur = front;	// two or more node scenario
	while (cur->link != back)
	{
		cur = cur->link;
	}	//cur should be at the second to last node
	delete back;
	back = cur;
	back->link = NULL;
	count--;
}

template <typename T>
void LinkedList<T>::deleteItem(const T& item) {
	if (front == NULL)	// empty list scenario
	{
		return;
	}
	Node<T>* cur = front;
	Node<T>* prev = NULL;
	while (cur != NULL && cur->data != item) {
		prev = cur;
		cur = cur->link;
	}
	if (cur->data == item)
	{
		// check for only node scenario
		if (front == back)
		{
			front = NULL;
			back = NULL;
			delete cur;
			count--;
			return;
		}
		//prev is behind cur and cur is the node to delete
		if (prev == NULL)	// First node scenario
		{
			front = front->link;
			delete cur;
			count--;
			return;
		}
		prev->link = cur->link;
		delete cur;
		if (prev->link == NULL)	// Last node scenario
		{
			back = prev;
		}
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