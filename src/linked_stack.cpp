/**
 * @file linked_stack.cpp
 * @author Hans Buss, André Fernandes
 * @brief Implementação da linked stack.
 * 
 */
template<typename T>
LinkedStack<T>::~LinkedStack() {
	clear();
}

template<typename T>
void LinkedStack<T>::clear() {
	while (!empty())
		pop();
}

template<typename T>
void LinkedStack<T>::push(const T& data) {
	top_ = new Node(data, empty() ? nullptr : top_);
	++size_;
}

template<typename T>
T LinkedStack<T>::pop() {
	if (empty())
		throw std::out_of_range("Pilha vazia, underflow.");

	auto nodepopped = top_;
	const T datapopped = top_->data();

	if (size() == 1)
		top_ = nullptr;
	else
		top_ = top_->next();

	delete nodepopped;

	--size_;
	return datapopped;
}

template<typename T>
T& LinkedStack<T>::top() const {
	if (empty())
		throw std::out_of_range("Pilha vazia, nada no topo.");

	return top_->data();
}

template<typename T>
bool LinkedStack<T>::empty() const {
	return size_ == 0;
}

template<typename T>
std::size_t LinkedStack<T>::size() const {
	return size_;
}
