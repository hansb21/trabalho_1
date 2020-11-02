/**
 * @file linked_stack.h
 * @author Hans Buss, André Fernandes
 * @brief Declaração da linked stack.
 * 
 */

#ifndef STRUCTURES_LINKED_STACK_H
#define STRUCTURES_LINKED_STACK_H

#include <cstdint>
#include <stdexcept>


//! Estruturas de Dados.
namespace structures {

template<typename T>
//! Pilha Encadeada.
class LinkedStack {
 public:
	//! Destrutor.
	~LinkedStack();

	//! Empilha.
	void push(const T& data);
	//! Desempilha.
	T pop();
	//! Acessa o topo da Pilha.
	T& top() const;
	//! Confere se a Pilha está vazia.
	bool empty() const;
	//! Retorna o tamanho da Pilha.
	std::size_t size() const;
	//! Limpa a Pilha.
	void clear();

 private:
	//! Elemento-Nodo da Pilha Encadeada.
	class Node {
	 public:
		//! Construtor apenas com dado.
		explicit Node(const T& data): data_{data} {}
		//! Construtor completo.
		explicit Node(const T& data, Node* next): data_{data}, next_{next} {}

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

	Node* top_{nullptr};  //!< Nodo-topo.
	std::size_t size_{0u};  //!< Tamanho atual.
};

// implementacao incluida aqui
#include "linked_stack.cpp"

}  // namespace structures

#endif
