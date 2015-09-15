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
	back->link = temp;
	back = temp;
	count++;
}

int main() {

	Node<int>* n1 = new Node<int>();

	n1->data = 42; // same as (*n1).data = 42;
	n1->link = NULL;

	Node<int>* n2 = new Node<int>();
	n2->data = 12;
	n1->link = n2;

	Node<int>* n3 = new Node<int>();
	n2->data = 84;
	n2->link = n3;
	n3->link = NULL;

	//Get rid of middle node
	n1->link = n3;
	delete n2;
	n2 = NULL;

	_getch();
	return 0;

	//participation code 841242
}