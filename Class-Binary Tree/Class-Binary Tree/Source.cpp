#include <iostream>
#include <conio.h>	

using namespace std;

template <typename T>
class Node {
public:
	T data;
	Node * llink;
	Node * rlink;

};

template <typename T>
class sortedBinaryTree {
public:
	sortedBinaryTree();
	//~sortedBinaryTree();
	void insertItem(const T& item);
	void inOrder();
private:
	Node<T> * root;
	void inOrder(Node<T> * ptr);

};

template <typename T>
sortedBinaryTree<T>::sortedBinaryTree() {
	root = NULL;
}

template <typename T>
void sortedBinaryTree<T>::insertItem(const T& item) {
	if (root == NULL)
	{
		root = new Node<T>();
		root->rlink = NULL;
		root->llink = NULL;
		root->data = item;
		return;
	}
	Node<T> * cur = root;
	Node<T> * temp = new Node<T>();
	temp->rlink = NULL;
	temp->llink = NULL;
	temp->data = item;
	bool inserted = false;
	do
	{
		if (item > cur->data)
		{
			if (cur->rlink == NULL)
			{
				cur->rlink = temp;
				inserted = true;
			}
			else
			{
				cur = cur->rlink;
			}

		}
		else
		{
			if (cur->llink == NULL)
			{
				cur->llink = temp;
				inserted = true;
			}
			else
			{
				cur = cur->llink;
			}
		}
	} while (!inserted);
}

template <typename T>
void sortedBinaryTree<T>::inOrder() {
	inOrder(root);
}

template <typename T>
void sortedBinaryTree<T>::inOrder(Node<T> * ptr) {
	if (ptr != NULL)			//Recursive
	{
		inOrder(ptr->llink);	//Go left
		cout << ptr->data << " ";	//Display
		inOrder(ptr->rlink);	//Go right
	}
}


int main() {
	sortedBinaryTree<int> t;
	t.insertItem(10);
	t.insertItem(12);
	t.insertItem(72);	
	t.insertItem(01);
	t.insertItem(14);
	t.insertItem(13);
	t.insertItem(07);
	t.insertItem(11);

	t.inOrder();

	_getch();
	return 0;
}