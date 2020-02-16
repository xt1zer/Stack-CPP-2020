#include "Stack.h"
#include <iostream>
using std::printf;

int main() {
	Stack<int> s;
	s.load("stack.txt");
	Stack<int>::Iterator it = s.top();
	while (it) {
		printf("%d\n", it->value);
		it = it->next;
	}

	//s.clear();
	//empty = s.isEmpty();
	//top = s.peek();
	//printf("%d %d\n", empty, top);

	//int pop = s.pop();
	//empty = s.isEmpty();
	//top = s.peek();
	//printf("%d %d %d\n", pop, empty, top);

	//pop = s.pop();
	//empty = s.isEmpty();
	//top = s.peek();
	//printf("%d %d %d\n", pop, empty, top);

	return 0;
}
