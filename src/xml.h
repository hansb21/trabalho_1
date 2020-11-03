/**
 * @file xml.h	
 * @author Hans Buss, André Fernandes
 * @brief Declaração das funções necessárias para validar e extrair dos arquivos .xml.
 *
 */
#ifndef XML_H
#define XML_H

#include <string>

//! Funções para o uso de XML.
namespace xml {
	
	
	/**
	 * @brief Função usada para verificar se o XML é valido ou não.
	 * 
	 * @param XML Arquivo que será verificado em formato string. 
	 * @return 0 se é valido.
	 * @return 1 se é invalido.
	 */
	bool verifier(const std::string &xml);

	/**
	 * @brief Extrai a partir de uma string, a substring entre os pares delimitadores das posições.
	 *
	 * @param origin String a ser usada.
	 * @param start Posição de abertura.
	 * @param end Posição de encerramento.
	 * @param from Indice por onde se começa a pesquisa na string.
	 *
	 * @return std::string Contéudo que foi extraido, ou vázio se nada foi encontrado.
	 */
	std::string extract(const std::string& origin, const std::string& start, 
		const std::string& end, std::size_t& from);

	/**
	 * @brief Extrai a substring que existir dentre o par de delimitadores.
	 * 
	 * @param origin String a ser usada.
	 * @param start Posição de abertura.
	 * @param end Posição de encerramento.
	 * @param from Indice por onde se começa a pesquisa na string.
	 *
	 * @return std::string Contéudo que foi extraido, ou vázio se nada foi encontrado.
	 */
	std::string subextractor(const std::string& origin, const std::string& start, const std::string& close);


}  //namespace xml

#endif // XML_H
