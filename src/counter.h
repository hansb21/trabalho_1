/**
 * 
 * @brief Declaração das funções usadas para efetuar a contagem de áreas na imagem.
 * 
 */

#include <string>

namespace counter {
    /* 
	 * @brief Remove os elementos na vizinhança de um array.
	 */
    void clear_neighbours(int width, int height, bool array[], int pos);
    
    /* 
	 * @brief Retorna as áreas conectadas de uma imagem.
	 */
    int connectivity_counter(int width, int height, bool array[]);

    /* 
	 * @brief Cria uma matriz booleana a partir de uma string de '0' e '1'.
	 */
    bool* create_matrix(std::string str_matrix, int width, int height);
}