#include <iostream>

#include "linked_stack.h"
#include "linked_stack.cpp"

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

    return connectivity;
}


int main() {
    bool matrix[] = {1,1,1,0,
                     1,0,0,1,
                     0,1,1,1};
                     
    std::cout << connectivity_counter(4,3,matrix) << "\n";
}