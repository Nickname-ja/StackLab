#pragma once
#include <iostream>

template <typename T>
struct NODE
{
    T info;
    NODE* next;
    NODE(T info, NODE* ptr = nullptr) : info(info), next(ptr) {};
    ~NODE() {
        next = nullptr;
    }
};

template <typename T>
using ptrNODE = NODE<T>*;

template <typename T>
struct Stack {
private:
    ptrNODE<T> head;
    size_t count;
public:
    Stack();
    bool empty();
    size_t size();
    void push(T elem);
    void pop();
    T top();
    void view();
    void clear();
    ~Stack();
};

template<typename T>
inline Stack<T>::Stack()
{
    head = nullptr;
    count = 0;
}

template<typename T>
inline bool Stack<T>::empty()
{

    return head == nullptr;
}

template<typename T>
inline size_t Stack<T>::size()
{
    return count;
}

template<typename T>
inline void Stack<T>::push(T elem)
{
    head = new NODE<T>(elem, head);
}

template<typename T>
inline void Stack<T>::pop()
{
    ptrNODE<T> ptr = head;
    head = head->next;
    delete ptr;
    --count;
}

template<typename T>
inline T Stack<T>::top()
{
    return head->info;
}

template<typename T>
inline void Stack<T>::view()
{
    ptrNODE<T> ptr{ head };
    while (ptr) {
        std::cout << ptr->info << ' ';
        ptr = ptr->next;
    }
    std::cout << '\n';
}

template<typename T>
inline void Stack<T>::clear()
{
    while (!empty()) {
        pop();
    }
}

template<typename T>
inline Stack<T>::~Stack()
{
    clear();
}
