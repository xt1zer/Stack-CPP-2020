#include "Stack.h"
#include <iostream>
using std::printf;

int main() {
	Stack<int> s;
	s.push(2);
	s.push(5);
	bool empty = s.isEmpty();
	int top = s.peek();
	printf("%d %d\n", empty, top);

	s.clear();
	empty = s.isEmpty();
	top = s.peek();
	printf("%d %d\n", empty, top);

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
