#pragma once
#include "Stack.h"

void choice(const int &c, Stack<int> &stack) {
	system("clear");

	switch (c) {
	case 1: {
		int value;
		std::cout << "Enter value: ";
		std::cin >> value;
		stack.push(value);
		break;
	}

	case 2: {
		int value = stack.pop();
		std::cout << "Popped value " << value << std::endl;
		break;
	}

	case 3: {
		if (stack.isEmpty())
			std::cout << "Stack is empty\n";
		else
			std::cout << "Top = " << stack.peek() << std::endl;
		break;
	}

	case 4: {
		stack.clear();
		std::cout << "Stack cleared\n";
		break;
	}

	case 5: {
		if (stack.isEmpty())
			std::cout << "Stack is empty\n";
		else
			std::cout << "Stack is not empty\n";
		break;
	}

	case 6: {
		std::string fileName;
		std::cout << "Enter filename: ";
		std::cin >> fileName;
		stack.save(fileName);
		break;
	}

	case 7: {
		std::string fileName;
		std::cout << "Enter filename: ";
		std::cin >> fileName;
		stack.load(fileName);
		break;
	}

	}
}

void menu(Stack<int> &stack) {
	int c;
	while (true) {
		std::cout << "Options:\n\n";
		std::cout << "1. Push element\n";
		std::cout << "2. Pop element\n";
		std::cout << "3. Get top value\n";
		std::cout << "4. Clear stack\n";
		std::cout << "5. Check if empty\n";
		std::cout << "6. Save to file\n";
		std::cout << "7. Read from file\n";

		std::cin >> c;

		choice(c, stack);
	}
}
