/**
 * @file counter.h
 * @author Hans Buss, André Fernandes
 * @brief Declaração das funções usadas para efetuar a contagem de áreas na imagem.
 * 
 */

#include <string>

//! Funções para contar regiões na imagem.
namespace counter {
    /**
	 * @brief Remove os elementos na vizinhança de um array.
     * 
     * @param width inteiro representando largura 
     * @param height inteiro representando largura
     * @param array de booleanos representando a matriz
     * @param pos inteiro representando a posição onde deseja remover os vizinhos
	 */
    void clear_neighbours(int width, int height, bool array[], int pos);
    
    /**
	 * @brief Retorna as áreas conectadas de uma imagem.
     * 
     * @param width inteiro representando largura
     * @param height inteiro representando largura
     * @param array de booleanos representando a matriz
     * 
     * @returns inteiro representando a quantidade de areas conenctadas 
     */
    int connectivity_counter(int width, int height, bool array[]);

    /**
	 * @brief Cria uma matriz booleana a partir de uma string de '0' e '1'.
     *
     * @param str_matrix string representando a matriz de 0 e 1  
     * @param width inteiro representando largura
     * @param height inteiro representando largura
     *
     * @returns array de booleanos representando a matriz
	 */
    bool* create_matrix(std::string str_matrix, int width, int height);
}
