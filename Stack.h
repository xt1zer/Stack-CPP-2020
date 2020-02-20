#pragma once
#include <limits>
#include <fstream>
#include <iostream>

template <typename T>
struct Node {
    T value;
    Node* next;

    Node(T data) : value(data), next(nullptr) {}

    ~Node() {
        next = nullptr;
    }
};

template <typename T>
class Stack {
private:
    Node<T>* m_top = nullptr;

    void reverse() {
        Stack<T> temp;
        while (!isEmpty())
            temp.push(pop());
        m_top = temp.m_top;
    }

public:
    Stack<T>() : m_top(nullptr) {}
    //    Stack<T>(const Stack<T>& copy) {
    //        Iterator iter = copy.m_top;
    //        while (iter) {
    //            push(iter->value);
    //            iter = iter->next;
    //        }
    //    }

    typedef Node<T>* Iterator;
    Iterator top() { return m_top; }

    void push(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = m_top;
        m_top = newNode;
    };

    T pop() {
        if (isEmpty())
            return INT32_MIN;

        T output = m_top->value;
        Node<T>* oldTop = m_top;

        if (m_top->next)
            m_top = m_top->next;
        else
            m_top = nullptr;

        delete oldTop;

        return output;
    };

    T peek() const {
        if (!isEmpty())
            return m_top->value;
        return INT32_MIN;
    }

    void clear() {
        while (!isEmpty())
            pop();
    };

    bool isEmpty() const {
        return !m_top;
    };

    void save(const std::string fileName) const {
        reverse();
        std::ofstream outFile(fileName);

        while (!outFile.is_open()) {
            std::cout << "File didn't open, give me just a bit\n";
            outFile.open(fileName, std::ios::out);
        }

        Iterator it = m_top;

        while (it) {
            outFile << it->value << " ";
            it = it->next;
        }

        outFile.close();
        std::cout << "Stack saved to file!\n";
    };

    void load(const std::string fileName) {
        std::ifstream inFile(fileName);

        int i = 0;
        while (!inFile.is_open()) {
            if (i > 2) {
                std::cout << "File failed to open, probably not found, idk\n";
                return;
            }
            std::cout << "File didn't open, give me just a bit\n";
            inFile.open(fileName, std::ios::in);
            ++i;
        }

        if (!isEmpty())
            clear();

        T data;
        while (inFile >> data)
            push(data);

        inFile.close();
        std::cout << "Stack created from file!\n";
    };
};
