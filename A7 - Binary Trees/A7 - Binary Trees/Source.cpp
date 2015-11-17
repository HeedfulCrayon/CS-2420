#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <math.h>

//To prevent those using g++ from trying to use a library
//they don't have
#ifndef __GNUC__
#include <conio.h>
#else
#include <stdio.h>
#endif


using namespace std;

template <typename T>
class Node {
public:
	T data;
	Node * llink;
	Node * rlink;
};

class processMath {
private:
	stack<string> mathStack;
	double castStrToDouble(string const &s);
	string castDoubleToStr(const double d);
	void initialize();
	bool isDigit(char c);
	bool isOperator(char c);
	void expressionProcessor(Node<string> *p);
	void computeExpression(Node<string> *p);
	void inOrderTraversal(Node<string> * ptr);
	void postOrderTraversal(Node<string> * ptr);
	Node<string> * root;
protected:
	string expression;
	int position;
public:
	processMath();
	void displayParseTree();
	void expressionProcessor(string &expression);
	string computeExpression();	void inOrderTraversal();
	void postOrderTraversal();

};

void processMath::initialize() {
	expression = "";
	position = 0;
	while (!mathStack.empty()) {
		mathStack.pop();
	}

}

double processMath::castStrToDouble(const string &s) {
	istringstream iss(s);
	double x;
	iss >> x;
	return x;
}

string processMath::castDoubleToStr(const double d) {
	ostringstream oss;
	oss << fixed << d;
	return oss.str();

}

processMath::processMath() {
	initialize();
}


void processMath::displayParseTree() {
	cout << "The expression seen using in-order traversal: ";
	inOrderTraversal();
	cout << endl;
	cout << "The expression seen using post-order traversal: ";
	postOrderTraversal();
	cout << endl;

}

void processMath::inOrderTraversal() {
	inOrderTraversal(root);
}

void processMath::inOrderTraversal(Node<string> * ptr) {
	if (ptr != NULL)
	{
		inOrderTraversal(ptr->llink);
		cout << ptr->data << " ";
		inOrderTraversal(ptr->rlink);
	}
}

void processMath::postOrderTraversal() {
	postOrderTraversal(root);
}

void processMath::postOrderTraversal(Node<string> * ptr) {
	if (ptr != NULL)
	{
		postOrderTraversal(ptr->llink);
		postOrderTraversal(ptr->rlink);
		cout << ptr->data << " ";
	}
}

bool processMath::isDigit(char c) {
	switch (c)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9': return true;
		break;
	default: return false;
		break;
	}
}

bool processMath::isOperator(char c) {
	switch (c)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '^': return true;
	default: return false;
		break;
	}
}

void processMath::expressionProcessor(string& expression) {
	if (expression != "")
	{
		this->expression = expression;
		position = 0;
		root = new Node<string>();
		root->rlink = NULL;
		root->llink = NULL;
		expressionProcessor(root);
	}
}

void processMath::expressionProcessor(Node<string> * ptr) {
	while (position < expression.length())
	{
		if (expression[position] == '(')
		{
			Node<string> * temp = new Node<string>();
			temp->llink = NULL;
			temp->rlink = NULL;
			ptr->llink = temp;
			position++;
			expressionProcessor(temp);
		}
		if (isDigit(expression[position]))
		{
			string temp(1,expression[position]);
			position++;
			while (isDigit(expression[position]))
			{
				temp = temp + string(1, expression[position]);
				position++;
			}
			ptr->data = temp;
			return;
		}
		if (isOperator(expression[position]))
		{
			ptr->data = expression[position];
			Node<string> * temp = new Node<string>();
			temp->llink = NULL;
			temp->rlink = NULL;
			ptr->rlink = temp;
			position++;
			expressionProcessor(temp);
		}
		if (expression[position] == ')')
		{
			position++;
			return;
		}
		position++;
	}
}

string processMath::computeExpression() {
	computeExpression(root);
	return mathStack.top();
}

void processMath::computeExpression(Node<string> *p) {
	if (p != NULL) {
		computeExpression(p->llink);
		computeExpression(p->rlink);
		mathStack.push(p->data);
		if (isOperator(p->data[0]))
		{
			string temp = mathStack.top();
			mathStack.pop();
			double num1 = castStrToDouble(mathStack.top());
			mathStack.pop();
			double num2 = castStrToDouble(mathStack.top());
			mathStack.pop();
			if (temp == "^")
			{
				mathStack.push(castDoubleToStr(pow(num2, num1)));
			}
			else if (temp == "+")
			{
				mathStack.push(castDoubleToStr(num2 + num1));
			}
			else if (temp == "-")
			{
				mathStack.push(castDoubleToStr(num2 - num1));
			}
			else if (temp == "/")
			{
				mathStack.push(castDoubleToStr(num2 / num1));
			}
			else if (temp == "*")
			{
				mathStack.push(castDoubleToStr(num2 * num1));
			}
		}
	}

}

void pressAnyKeyToContinue() {
	printf("Press any key to continue\n");

	//Linux and Mac users with g++ don't need this
	//But everyone else will see this message.
#ifndef __GNUC__
	_getch();
#else
	int c;
	fflush(stdout);
	do c = getchar(); while ((c != '\n') && (c != EOF));
#endif

}


int main() {
	processMath *mp = new processMath;

	string expression = "(4+7)";
	mp->expressionProcessor(expression);
	mp->displayParseTree();
	cout << "The result is: " << mp->computeExpression() << endl; //Should display 5

	expression = "(543+321)";
	mp->expressionProcessor(expression);
	mp->displayParseTree();
	cout << "The result is: " << mp->computeExpression() << endl; //Should display 864

	expression = "(7-4)";
	mp->expressionProcessor(expression);
	mp->displayParseTree();
	cout << "The result is: " << mp->computeExpression() << endl; //Should display 3

	expression = "((2-5)-5)";
	mp->expressionProcessor(expression);
	mp->displayParseTree();
	cout << "The result is: " << mp->computeExpression() << endl; //Should display -8

	expression = "(4^3)";
	mp->expressionProcessor(expression);
	mp->displayParseTree();
	cout << "The result is: " << mp->computeExpression() << endl; //Should display 64

	expression = "(5*(6/2))";
	mp->expressionProcessor(expression);
	mp->displayParseTree();
	cout << "The result is: " << mp->computeExpression() << endl; //Should display 15

	expression = "((1 + 2) * (3 + 4))";
	mp->expressionProcessor(expression);
	mp->displayParseTree();
	cout << "The result is: " << mp->computeExpression() << endl; //Should display 21

	expression = "(((((3+12)-7)*120)/(2+3))^3)";
	mp->expressionProcessor(expression);
	mp->displayParseTree();
	cout << "The result is: " << mp->computeExpression() << endl; //Should display 7077888

	expression = "(((((9+(2*(110-(30/2))))*8)+1000)/2)+(((3^4)+1)/2))";
	mp->expressionProcessor(expression);
	mp->displayParseTree();
	cout << "The result is: " << mp->computeExpression() << endl; //Should display 1337

	pressAnyKeyToContinue();
	return 0;
}