/**
 * @file linked_queue.h
 * @author Hans Buss, André Fernandes
 * @brief Declaração da linked queue.
 * 
 */
#ifndef STRUCTURES_LINKED_QUEUE_H
#define STRUCTURES_LINKED_QUEUE_H

#include <cstdint>
#include <stdexcept>


//! Estruturas de Dados.
namespace structures {

template<typename T>
//! Fila Encadeada.
class LinkedQueue {
 public:
	//! Destrutor.
	~LinkedQueue();

	//! Limpa a Fila.
	void clear();
	//! Enfileira.
	void enqueue(const T& data);
	//! Desenfileira.
	T dequeue();
	//! Acessa a frente da Fila.
	T& front() const;
	//! Acessa o último da Fila.
	T& back() const;
	//! Confere se a Fila está vazia.
	bool empty() const;
	//! Retorna o tamanho da Fila.
	std::size_t size() const;

 private:
	//! Elemento-Nodo da Fila Encadeada.
	class Node {
	 public:
		//! Construtor apenas com dado.
		explicit Node(const T& data) : data_{data} {}
		//! Construtor completo.
		explicit Node(const T& data, Node* next) : data_{data}, next_{next} {}

		//! getter: dado.
		T& data() { return data_; }
		//! getter const: dado.
		const T& data() const { return data_; }
		//! getter: próximo.
		Node* next() { return next_; }
		//! getter const: próximo.
		const Node* next() const { return next_; }
		//! setter: próximo.
		void next(Node* node) { next_ = node; }

	 private:
		T data_;
		Node* next_{nullptr};
	};

	Node* head_{nullptr};  //!< Nodo-cabeca.
	Node* tail_{nullptr};  //!< Node-cauda.
	std::size_t size_{0u};  //!< Tamanho atual.
};

// implementacao incluida aqui
#include "linked_queue.c"

}  // namespace structures

#endif
