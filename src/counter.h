/**
 * 
 * @brief Declaração das funções usadas para efetuar a contagem de áreas na imagem.
 * 
 */

#include <string>

namespace counter {
    /* 
	 * @brief Remove os elementos na vizinhança de um array.
     * 
     * @params width inteiro 
     * @params height inteiro
     * @params array de booleanos representando a matriz
     * @params pos inteiro representando a posição onde deseja remover os vizinhos
	 */
    void clear_neighbours(int width, int height, bool array[], int pos);
    
    /* 
	 * @brief Retorna as áreas conectadas de uma imagem.
     * 
     * @params width inteiro
     * @params height inteiro
     * @params array de booleanos representando a matriz
     * 
     * @returns inteiro representando a quantidade de areas conenctadas 
	 */
    int connectivity_counter(int width, int height, bool array[]);

    /* 
	 * @brief Cria uma matriz booleana a partir de uma string de '0' e '1'.
     *
     * @params str_matrix no formato string 
     * @params width inteiro
     * @params height inteiro
     *
     * @return array de booleanos representando a matriz
	 */
    bool* create_matrix(std::string str_matrix, int width, int height);
}