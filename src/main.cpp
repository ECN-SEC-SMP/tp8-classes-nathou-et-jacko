#include <iostream>

#include <assert.h>
#include "util.hpp"
#include "class/Game.hpp"
#include "class/Attaque.hpp"
#include "class/Pierre.hpp"
#include "class/Lion.hpp"
#include "class/Loup.hpp"
#include "class/Ours.hpp"


void testAttaque_constru(void);
void testAttaque_getTypeAttaque(void);
void testAttaque_resoudreAttaque(void);
void testAttaque_getNomAttaque(void);
void testClass_Attaque(void);

void testAnimal_constru(void);
void testAnimal_getAttaque(void);
void testAnimal_attaque(void);
void testAnimal_getX(void);
void testClass_Animal(void);

void testPierre_constru(void);
void testPierre_setAttaquee(void);
void testPierre_deplace(void);
void testClass_Pierre(void);

void testLoup_constru(void);
void testLoup_setAttaquee(void);
void testLoup_deplace(void);
void testClass_Loup(void);

void testOurs_constru(void);
void testOurs_setAttaquee(void);
void testOurs_deplace(void);
void testClass_Ours(void);

void testLion_constru(void);
void testLion_setAttaquee(void);
void testLion_deplace(void);
void testClass_Lion(void);

int main(int argc, char const *argv[])
{

    initRand();

    Game game = Game();

    game.printBoardGame();

    
    // Tests
    testClass_Lion();

    return 0;
}

void testLion_constru(void) {

    Lion lion_1 = Lion(10, 10);
    Lion lion_2 = Lion(10, 10, 1, 1);

    assert(lion_1.getName() == "Lion");
    assert(lion_1.getVivant() == 1);
    assert(lion_2.getName() == "Lion");
    assert(lion_2.getVivant() == 1);

    cout << "  - constructeur Lion\t : OK" << endl;

}
void testLion_setAttaquee(void) {
    

    cout << "  - setAttaque Lion\t : OK" << endl;

}
void testLion_deplace(void) {
    cout << "  - deplace Lion\t : OK" << endl;

}
void testClass_Lion(void) {
    cout << "** Test de la Class Lion **" << endl;

    testLion_constru();
    testLion_setAttaquee();
    testLion_deplace();

    cout << endl << endl;

}
