#pragma once

template <typename T>
struct Node {
    T value;
    Node* next;
};

template <typename T>
class Stack {
private:
    Node<T>* top;
public:
    typedef Node<T>* Iterator;

    void push(T value);
    T pop();
    T peek();
    void clear();
    bool isEmpty();
    void save(char* fileName);
    void load(char* fileName);
};
