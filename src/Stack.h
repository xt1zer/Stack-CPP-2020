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

public:
    Stack<T>() : m_top(nullptr) {}

    typedef Node<T>* Iterator;
    Iterator top() { return m_top; }

    void reverse() {
        Stack<T> temp;
        while (!isEmpty())
            temp.push(pop());
        m_top = temp.m_top;
    }

    void push(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = m_top;
        m_top = newNode;
    }

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
    }

    T peek() const {
        if (!isEmpty())
            return m_top->value;
        return INT32_MIN;
    }

    void clear() {
        while (!isEmpty())
            pop();
    }

    bool isEmpty() const {
        return !m_top;
    }
};
