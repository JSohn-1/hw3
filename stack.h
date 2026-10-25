
#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

template <typename T>
class Stack : public std::vector<T>
{
public:
    Stack() = default;
    ~Stack() = default;

    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();
    const T& top() const;
};

template <typename T>
bool Stack<T>::empty() const {
    return std::vector<T>::empty();
}

template <typename T>
size_t Stack<T>::size() const {
    return std::vector<T>::size();
}

template <typename T>
void Stack<T>::push(const T& item) {
    this->push_back(item);
}

template <typename T>
void Stack<T>::pop() {
    if (this->empty()) {
        throw std::underflow_error("Stack is empty");
    }
    this->pop_back();
}

template <typename T>
const T& Stack<T>::top() const {
    if (this->empty()) {
        throw std::underflow_error("Stack is empty");
    }
    return this->back();
}

#endif
