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
	~sortedBinaryTree();
	void insertItem(const T& item);
	void preOrder();
	void inOrder();
	void postOrder();
private:
	Node<T> * root;
	void preOrder(Node<T> * ptr);
	void inOrder(Node<T> * ptr);
	void postOrder(Node<T> * ptr);
	void deleteTree(Node<T> * ptr);

};

template <typename T>
sortedBinaryTree<T>::sortedBinaryTree() {
	root = NULL;
}

template <typename T>
sortedBinaryTree<T>::~sortedBinaryTree() {
	deleteTree(root);
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

template <typename T>
void sortedBinaryTree<T>::deleteTree(Node<T> * ptr) {
	if (ptr != NULL)
	{
		deleteTree(ptr->llink);
		deleteTree(ptr->rlink);
		delete ptr;
	}
}

template <typename T>
void sortedBinaryTree<T>::preOrder() {
	preOrder(root);
}

template <typename T>
void sortedBinaryTree<T>::preOrder(Node<T> * ptr) {
	if (ptr != NULL)			//Recursive
	{
		cout << ptr->data << " ";	//Display
		preOrder(ptr->llink);	//Go left
		preOrder(ptr->rlink);	//Go right
	}
}

template <typename T>
void sortedBinaryTree<T>::postOrder() {
	postOrder(root);
}

template <typename T>
void sortedBinaryTree<T>::postOrder(Node<T> * ptr) {
	if (ptr != NULL)			//Recursive
	{
		postOrder(ptr->llink);	//Go left
		postOrder(ptr->rlink);	//Go right
		cout << ptr->data << " ";	//Display
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

	t.preOrder();
	cout << endl;
	t.inOrder();
	cout << endl;
	t.postOrder();

	_getch();
	return 0;
}

// 111314 participation code 11/4/2015