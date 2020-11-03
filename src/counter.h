/**
 * @file counter.h
 * @author Hans Buss, André Fernandes
 * @brief Declaração das funções usadas para efetuar a contagem de áreas na imagem.
 * 
 */

#include <string>
//!  Funções usadas para comer cu de curioso
namespace counter {
    
   /** 
     * @brief Remove os elementos na vizinhança de um array.
     * 
     * @param width inteiro 
     * @param height inteiro
     * @param array de booleanos representando a matriz
     * @param pos inteiro representando a posição onde deseja remover os vizinhos
     */
    void clear_neighbours(int width, int height, bool array[], int pos);
    
    /** 
     * @brief Retorna as áreas conectadas de uma imagem.
     * 
     * @param width inteiro
     * @param height inteiro
     * @param array de booleanos representando a matriz
     * 
     * @returns inteiro representando a quantidade de areas conenctadas 
     */
    int connectivity_counter(int width, int height, bool array[]);

    /** 
     * @brief Cria uma matriz booleana a partir de uma string de '0' e '1'.
     *
     * @param str_matrix no formato string 
     * @param width inteiro
     * @param height inteiro
     *
     * @return array de booleanos representando a matriz
     */
    bool* create_matrix(std::string str_matrix, int width, int height);
}
