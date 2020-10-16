/**
 * 
 * @brief Declaração das funções usadas para a verificação do XML.
 * 
 */

#include <string>

namespace xml {
	
	
	/* 
	 * @brief Função usada para verificar se o XML é valido ou não.
	 * 
	 * @params XML em formato string. 
	 * @returns: 0 se é valido.
	 * @returns: 1 se é invalido.
	 */
	bool verifier(const std::string &xml);

	
	std::string extract(const std::string& origin, const std::string& start, 
		const std::string& end, std::size_t& from);

	
	std::string subextractor(const std::string& origin, const std::string& start, const std::string& close);


} 

