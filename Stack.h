#pragma once
#include <limits>
#include <fstream>
using std::ofstream;

template <typename T>
struct Node {
	T value;
	Node* next;

	Node(T data) : value(data), next(nullptr){}

	~Node(){
		next = nullptr;
	}
};

template <typename T>
class Stack {
private:
	Node<T>* top = nullptr;

public:
	typedef Node<T>* Iterator;

	void push(const T& data) {
		Node<T>* newNode = new Node<T>(data);
		if (!isEmpty())
			newNode->next = top;
		top = newNode;
	};

	T pop() {
		if (isEmpty())
			return INT_MIN;

		T output = top->value;
		Node<T>* oldTop = top;

		if (top->next)
			top = top->next;
		else
			top = nullptr;

		delete oldTop;

		return output;
	};

	T peek(){
		if (!isEmpty())
			return top->value;
		return INT_MIN;
	}

	void clear() {
		while (!isEmpty())
			pop();
	};

	bool isEmpty() {
		return !top;
	};

	void save(const char* fileName){
		ofstream outFile(fileName);
	};

	void load(const char* fileName){

	};
};
