#pragma once
#include "Stack.h"

void choice(const int &c, Stack<int> &stack) {
	system("clear");

	switch (c) {
	case 1: {
		int value;
		printf("Enter value: ");
		scanf("%d", &value);
		stack.push(value);
		break;
	}

	case 2: {
		int value = stack.pop();
		printf("Popped value %d\n", value);
		break;
	}

	case 3: {
		if (stack.isEmpty())
			printf("Stack is empty\n");
		else
			printf("Top = %d\n", stack.peek());
		break;
	}

	case 4: {
		stack.clear();
		printf("Stack cleared\n");
		break;
	}

	case 5: {
		if (stack.isEmpty())
			printf("Stack is empty\n");
		else
			printf("Stack is not empty\n");
		break;
	}

	case 6: {
		std::string fileName;
		printf("Enter filename: ");
		std::cin >> fileName;
//		scanf("%s", &fileName);
		stack.save(fileName);
		break;
	}

	case 7: {
		std::string fileName;
		printf("Enter filename: ");
		std::cin >> fileName;
//		scanf("%s", &fileName);
		stack.load(fileName);
		break;
	}

	}
}

void menu(Stack<int> &stack) {
	int c;
	while (true) {
		printf("Options:\n\n");
		printf("1. Push element\n");
		printf("2. Pop element\n");
		printf("3. Get top value\n");
		printf("4. Clear stack\n");
		printf("5. Check if empty\n");
		printf("6. Save to file\n");
		printf("7. Read from file\n");

		scanf("%d", &c);

		choice(c, stack);
	}
}
