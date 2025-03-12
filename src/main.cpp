#include <iostream>

#include "util.hpp"
#include "Attaque.hpp"


int main(int argc, char const *argv[]) {
    
    initRand();

    Attaque att;

    for (uint8_t i = 0; i < 100; i++) {
        att = Attaque();
        std::cout << i << ". " << att.getNomAttaque() << std::endl;
    }
    
    

    return 0;
}
