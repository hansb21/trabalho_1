#ifndef STRUCTURES_LINKED_STACK_H
#define STRUCTURES_LINKED_STACK_H

#include <cstdint>

namespace structures {

template<typename T>
class Node {
 public:
    Node(const T& data, Node<T>* next);
    explicit Node(const T& data);
    T& data();
    const T& data() const;
    Node<T>* next();
    const Node<T>* next() const;
    void next(Node<T>* node);
 private:
    T data_;
    Node<T>* next_{nullptr};
};

template<typename T>
class LinkedStack {
 public:
    LinkedStack();
    ~LinkedStack();
    void clear();
    void push(const T& data);
    T pop();
    T& top() const;
    bool empty() const;
    std::size_t size() const;

 private:
    Node<T>* top_;
    std::size_t size_;
};

}  // namespace structures

#endif 
