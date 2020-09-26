#include <cstdint>
#include <stdexcept>
#include "linked_stack.h"

template<typename T>
structures::Node<T>::Node(const T& data, Node<T>* next) {
    data_ = data;
    next_ = next;
}

template<typename T>
structures::Node<T>::Node(const T& data) {
    data_ = data;
}

template<typename T>
T& structures::Node<T>::data() {
    return data_;
}

template<typename T>
const T& structures::Node<T>::data() const {
    return data_;
}

template<typename T>
structures::Node<T>* structures::Node<T>::next() {
    return next_;
}

template<typename T>
const structures::Node<T>* structures::Node<T>::next() const {
    return next_;
}

template<typename T>
void structures::Node<T>::next(Node<T>* next) {
    next_ = next;
}

template<typename T>
structures::LinkedStack<T>::LinkedStack() {
    top_ = nullptr;
    size_ = 0;
}

template<typename T>
structures::LinkedStack<T>::~LinkedStack() {
    clear();
    delete top_;
}

template<typename T>
void structures::LinkedStack<T>::clear() {
    while (!empty()) {
        pop();
    }
}

template<typename T>
void structures::LinkedStack<T>::push(const T& data) {
    structures::Node<T>* new_node = new structures::Node<T>(data, top_);
    top_ = new_node;
    size_++;
}

template<typename T>
T structures::LinkedStack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Empty Stack");
    }
    structures::Node<T>* to_remove = top_;
    T data = to_remove->data();
    top_ = top_->next();
    size_--;
    delete to_remove;
    return data;
}

template<typename T>
T& structures::LinkedStack<T>::top() const {
    if (empty()) {
        throw std::out_of_range("Empty Stack");
    }
    return top_->data();
}

template<typename T>
bool structures::LinkedStack<T>::empty() const {
    return size() == 0;
}

template<typename T>
std::size_t structures::LinkedStack<T>::size() const {
    return size_;
}