/**
 * @file counter.h
 * @author Hans Buss, André Fernandes
 * @brief Implementação das funções usadas para efetuar a contagem de áreas na imagem.
 * 
 */
#include "linked_stack.h"

#include <iostream>
#include <string> 


namespace counter {

void clear_neighbours(int width, int height, bool array[], int pos) {
    structures::LinkedStack<int> stack;

    stack.push(pos);

    while (!stack.empty()) {
        int last = stack.pop(); 
        array[last] = 0;

        if ((last % width) > 0 && array[last-1]) {
            stack.push(last-1);     
        }
        if ((last % width) < width-1 && array[last+1]) {
            stack.push(last+1);
        }
        if ((last / width) > 0 && array[last-width]) {
            stack.push(last-width);
        }
        if ((last / width) < height-1 && array[last+width]) {
            stack.push(last+width);
        }
    }

} 

int connectivity_counter(int width, int height, bool array[]) {
    bool* array_copy = new bool[width*height];
    for (int i = 0; i < width*height; i++) {
        array_copy[i] = array[i];
    }

    int connectivity = 0;
    for (int i = 0; i < width*height; i++) {
        if (array_copy[i]) {
            connectivity++;
            clear_neighbours(width, height, array_copy, i);
        }
    }

    delete array_copy;
    return connectivity;
}

bool* create_matrix(std::string str_matrix, int width, int height) {
    bool* bool_matrix = new bool[width*height];

    int j = 0;
    for (auto i = 0u; i < str_matrix.size(); i++) {
        if (str_matrix[i] == '0' || str_matrix[i] == '1') {
            bool_matrix[j] = (str_matrix[i] == '1');
            j++;
        }
    }
    return bool_matrix;
}

}
