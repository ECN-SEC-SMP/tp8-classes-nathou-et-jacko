#include <iostream>

#include "util.hpp"


int main(int argc, char const *argv[]) {
    
    initRand();

    for (uint8_t i = 0; i < 100; i++) {
        std::cout << (int)getRand(-2, 2) << std::endl;
    }
    

    return 0;
}
