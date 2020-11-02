/**
 * @file linked_queue.cpp
 * @author Hans Buss, André Fernandes
 * @brief Implementação da linked queue.
 * 
 */
template<typename T>
LinkedQueue<T>::~LinkedQueue() {
	clear();
}

template<typename T>
void LinkedQueue<T>::clear() {
	while (!empty())
		dequeue();
}

template<typename T>
void LinkedQueue<T>::enqueue(const T& data) {
	auto nodenew = new Node(data, tail_);
	if (empty())
		head_ = nodenew;
	tail_ = nodenew;
	++size_;
}

template<typename T>
T LinkedQueue<T>::dequeue() {
	if (empty())
		throw std::out_of_range("Fila vazia, underflow.");

	auto nodepopped = head_;
	const T datapopped = head_->data();

	auto it = tail_;
	for (auto i = 1u; i < size_ - 1; ++i)
		it = it->next();

	head_ = it;
	head_->next(nullptr);

	delete nodepopped;
	--size_;

	if (empty()) {
		head_ = nullptr;
		tail_ = nullptr;
	}

	return datapopped;
}

template<typename T>
T& LinkedQueue<T>::front() const {
	if (empty())
		throw std::out_of_range("Fila vazia, nada na frente.");
	else
		return head_->data();
}

template<typename T>
T& LinkedQueue<T>::back() const {
	if (empty())
		throw std::out_of_range("Fila vazia, nada atras.");
	else
		return tail_->data();
}

template<typename T>
bool LinkedQueue<T>::empty() const {
	return size_ == 0;
}

template<typename T>
std::size_t LinkedQueue<T>::size() const {
	return size_;
}
