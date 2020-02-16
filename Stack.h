#pragma once
#include <limits>
#include <fstream>

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
    Node<T>* m_top;

    void reverse() {
        Stack<T> temp(*this);
        clear();
        while (!temp.isEmpty())
            push(temp.pop());
    }

public:
    Stack<T>() : m_top(nullptr) {}
    Stack<T>(const Stack<T>& copy) {
        Iterator iter = copy.m_top;
        while (iter) {
            push(iter->value);
            iter = iter->next;
        }
    }

    typedef Node<T>* Iterator;
    Iterator top() { return m_top; }

    void push(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (!isEmpty())
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

    T peek() {
        if (!isEmpty())
            return m_top->value;
        return INT32_MIN;
    }

    void clear() {
        while (!isEmpty())
            pop();
    };

    bool isEmpty() {
        return !m_top;
    };

    void save(const char* fileName) {
        reverse();
        std::ofstream outFile(fileName);

        while (!outFile.is_open()) {
            printf("File didn't open, give me just a bit\n");
            outFile.open(fileName, std::ios::out);
        }

        Iterator it = m_top;

        while (it) {
            outFile << it->value << " ";
            it = it->next;
        }

        outFile.close();
    };

    void load(const char* fileName) {
        std::ifstream inFile(fileName);

        int i = 0;
        while (!inFile.is_open()) {
            if (i > 2) {
                printf("File failed to open, probably not found, idk\n");
                return;
            }
            printf("File didn't open, give me just a bit\n");
            inFile.open(fileName, std::ios::in);
            ++i;
        }

        if (!isEmpty())
            clear();

        T data;
        while (inFile >> data)
            push(data);

        inFile.close();
    };
};
