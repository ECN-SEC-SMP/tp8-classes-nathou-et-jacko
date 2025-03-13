#include <iostream>

#include <exception>
#include <stdexcept>
#include <assert.h>
#include "util.hpp"
#include "class/Game.hpp"
#include "class/Attaque.hpp"
#include "class/Pierre.hpp"
#include "class/Lion.hpp"
#include "class/Loup.hpp"
#include "class/Ours.hpp"
#include "class/Animal.hpp"

void testAttaque_constru(void);
void testAttaque_resoudreAttaque(void);
void testClass_Attaque(void);

void testAnimal_attaque(void);
void testAnimal_setVivant(void);
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

    cout << "Run" << endl;
    while(game.run());
    cout << "End Run" << endl;

    // Tests
    // testClass_Lion();
    // testClass_Ours();
    // testClass_Loup();
    // testClass_Pierre();
    // testClass_Animal();
    // testClass_Attaque();
    return 0;
}

void testLion_constru(void)
{

    Lion lion_1 = Lion(10, 10);
    Lion lion_2 = Lion(10, 10, 1, 1);

    assert(lion_1.getName() == "Lion");
    assert(lion_1.getVivant() == 1);
    assert(lion_2.getName() == "Lion");
    assert(lion_2.getVivant() == 1);

    cout << "  - constructeur Lion\t : OK" << endl;
}
void testLion_setAttaquee(void)
{
    Lion lion = Lion(1, 1);
    for (int i = 0; i < 100; i++)
    {
        lion.setAttaque();
        AttackType attaque = lion.getAttaque().getTypeAttaque();
        assert(attaque == AttackType::PAPER || attaque == AttackType::CISOR);
    }
    cout << "  - setAttaque Lion\t : OK" << endl;
}
void testLion_deplace(void)
{
    Lion lion = Lion(MAX_X, MAX_Y);
    int prevX = lion.getX();
    int prevY = lion.getY();
    for (int i = 0; i < 100; i++)
    {
        lion.deplace(MAX_X, MAX_Y); // Deplace le lion

        // Vérifie l'intervale de X et Y
        assert(lion.getX() < MAX_X);
        assert(lion.getY() < MAX_Y);
        assert(lion.getX() >= 0);
        assert(lion.getY() >= 0);

        // Vérifie qu'il y a bien eu déplacement
        assert(lion.getX() != prevX);
        assert(lion.getY() != prevY);

        prevX = lion.getX();
        prevY = lion.getY();
    }

    cout << "  - deplace Lion\t : OK" << endl;
}
void testClass_Lion(void)
{
    cout << "** Test de la Class Lion **" << endl;

    testLion_constru();
    testLion_setAttaquee();
    testLion_deplace();

    cout << endl
         << endl;
}

void testOurs_constru(void)
{

    Ours ours_1 = Ours(10, 10);
    Ours ours_2 = Ours(10, 10, 1, 1);

    assert(ours_1.getName() == "Ours");
    assert(ours_1.getVivant() == 1);
    assert(ours_2.getName() == "Ours");
    assert(ours_2.getVivant() == 1);

    cout << "  - constructeur Ours\t : OK" << endl;
}
void testOurs_setAttaquee(void)
{
    Ours ours = Ours(1, 1);
    for (int i = 0; i < 100; i++)
    {
        ours.setAttaque();
        AttackType attaque = ours.getAttaque().getTypeAttaque();
        assert(attaque == AttackType::PAPER);
    }
    cout << "  - setAttaque Ours\t : OK" << endl;
}
void testOurs_deplace(void)
{
    Ours ours = Ours(MAX_X, MAX_Y);
    int prevX = ours.getX();
    int prevY = ours.getY();
    for (int i = 0; i < 100; i++)
    {
        ours.deplace(MAX_X, MAX_Y); // Deplace l'ours

        // Vérifie l'intervale de X et Y
        assert(ours.getX() < MAX_X);
        assert(ours.getY() < MAX_Y);
        assert(ours.getX() >= 0);
        assert(ours.getY() >= 0);

        // Vérifie qu'il y a bien eu déplacement
        assert(ours.getX() != prevX);
        assert(ours.getY() != prevY);

        prevX = ours.getX();
        prevY = ours.getY();
    }

    cout << "  - deplace Ours\t : OK" << endl;
}
void testClass_Ours(void)
{
    cout << "** Test de la Class Ours **" << endl;

    testOurs_constru();
    testOurs_setAttaquee();
    testOurs_deplace();

    cout << endl
         << endl;
}

void testLoup_constru(void)
{

    Loup loup_1 = Loup(10, 10);
    Loup loup_2 = Loup(10, 10, 1, 1);

    assert(loup_1.getName() == "Loup");
    assert(loup_1.getVivant() == 1);
    assert(loup_2.getName() == "Loup");
    assert(loup_2.getVivant() == 1);

    cout << "  - constructeur Loup\t : OK" << endl;
}
void testLoup_setAttaquee(void)
{
    Loup loup = Loup(1, 1);
    for (int i = 0; i < 100; i++)
    {
        loup.setAttaque();
        AttackType attaque = loup.getAttaque().getTypeAttaque();
        assert(attaque == AttackType::PAPER || attaque == AttackType::ROCK || attaque == AttackType::CISOR);
    }
    cout << "  - setAttaque Loup\t : OK" << endl;
}
void testLoup_deplace(void)
{
    Loup loup = Loup(MAX_X, MAX_Y);
    int prevX = loup.getX();
    int prevY = loup.getY();
    for (int i = 0; i < 100; i++)
    {
        loup.deplace(MAX_X, MAX_Y); // Deplace le loup

        // Vérifie l'intervale de X et Y
        assert(loup.getX() < MAX_X);
        assert(loup.getY() < MAX_Y);
        assert(loup.getX() >= 0);
        assert(loup.getY() >= 0);

        // Vérifie qu'il y a bien eu déplacement
        assert(loup.getX() != prevX);
        assert(loup.getY() != prevY);

        prevX = loup.getX();
        prevY = loup.getY();
    }

    cout << "  - deplace Loup\t : OK" << endl;
}
void testClass_Loup(void)
{
    cout << "** Test de la Class Loup **" << endl;

    testLoup_constru();
    testLoup_setAttaquee();
    testLoup_deplace();

    cout << endl
         << endl;
}

void testPierre_constru(void)
{

    Pierre pierre_1 = Pierre(10, 10);
    Pierre pierre_2 = Pierre(10, 10, 1, 1);

    assert(pierre_1.getName() == "Pierre");
    assert(pierre_1.getVivant() == 0);
    assert(pierre_2.getName() == "Pierre");
    assert(pierre_2.getVivant() == 0);

    cout << "  - constructeur Pierre\t : OK" << endl;
}
void testPierre_setAttaquee(void)
{
    Pierre pierre = Pierre(1, 1);
    for (int i = 0; i < 100; i++)
    {
        pierre.setAttaque();
        AttackType attaque = pierre.getAttaque().getTypeAttaque();
        assert(attaque == AttackType::ROCK);
    }
    cout << "  - setAttaque Pierre\t : OK" << endl;
}
void testPierre_deplace(void)
{
    Pierre pierre = Pierre(MAX_X, MAX_Y);
    int prevX = pierre.getX();
    int prevY = pierre.getY();
    for (int i = 0; i < 100; i++)
    {
        pierre.deplace(MAX_X, MAX_Y); // Deplace la pierre

        // Vérifie l'intervale de X et Y
        assert(pierre.getX() < MAX_X);
        assert(pierre.getY() < MAX_Y);
        assert(pierre.getX() >= 0);
        assert(pierre.getY() >= 0);

        // Vérifie qu'elle n'a pas bougé
        assert(pierre.getX() == prevX);
        assert(pierre.getY() == prevY);

        prevX = pierre.getX();
        prevY = pierre.getY();
    }

    cout << "  - deplace Pierre\t : OK" << endl;
}
void testClass_Pierre(void)
{
    cout << "** Test de la Class Pierre **" << endl;

    testPierre_constru();
    testPierre_setAttaquee();
    testPierre_deplace();

    cout << endl
         << endl;
}

void testAnimal_attaque(void)
{

    Ours ours_1 = Ours(MAX_X, MAX_Y);
    Pierre pierre_1 = Pierre(MAX_X, MAX_Y);

    pierre_1.setAttaque();
    ours_1.setAttaque();

    assert((ours_1.attaque(pierre_1)));
    assert(!(pierre_1.attaque(ours_1)));

    cout << "  - attaque Animal\t : OK" << endl;
}

void testAnimal_setVivant(void)
{
    Lion lion_1 = Lion(MAX_X, MAX_Y);
    Lion lion_2 = Lion(MAX_X, MAX_Y);

    lion_1.setVivant(0);
    lion_2.setVivant(1);
    assert(lion_1.getVivant() == 0);
    assert(lion_2.getVivant() == 1);

    try
    {
        lion_1.setVivant(-1);
    }
    catch (std::exception e)
    {
        cerr << e.what();
    }
    try
    {
        lion_1.setVivant(2);
    }
    catch (std::exception e)
    {
        cerr << e.what();
    }

    cout << "  - setVivant Animal\t : OK" << endl;
}

void testClass_Animal()
{
    cout << "** Test de la Class Animal **" << endl;

    testAnimal_attaque();
    testAnimal_setVivant();

    cout << endl
         << endl;
}

void testAttaque_constru(void)
{
    Attaque attaque_1 = Attaque();
    Attaque attaque_2 = Attaque(AttackType::ROCK);
    Attaque attaque_3 = Attaque(AttackType::CISOR);
    Attaque attaque_4 = Attaque(AttackType::PAPER);

    // Vérifie le type de l'attaque
    assert(attaque_1.getTypeAttaque() == AttackType::ROCK || attaque_1.getTypeAttaque() == AttackType::CISOR || attaque_1.getTypeAttaque() == AttackType::PAPER);
    assert(attaque_2.getTypeAttaque() == AttackType::ROCK);
    assert(attaque_3.getTypeAttaque() == AttackType::CISOR);
    assert(attaque_4.getTypeAttaque() == AttackType::PAPER);

    // Vérifie le nom de l'attaque
    assert(attaque_1.getNomAttaque() == "Rock" || attaque_1.getNomAttaque() == "Cisor" || attaque_1.getNomAttaque() == "Paper");
    assert(attaque_2.getNomAttaque() == "Rock");
    assert(attaque_3.getNomAttaque() == "Cisor");
    assert(attaque_4.getNomAttaque() == "Paper");

    cout << "  - constructeur Attaque\t : OK" << endl;
}

void testAttaque_resoudreAttaque(void)
{
    Attaque cisor = Attaque(AttackType::CISOR);
    Attaque paper = Attaque(AttackType::PAPER);
    Attaque rock = Attaque(AttackType::ROCK);

    // Vérifie toutes les combinaisons du shifumi
    assert(!cisor.resoudreAttaque(cisor));
    assert(cisor.resoudreAttaque(paper));
    assert(!cisor.resoudreAttaque(rock));

    assert(!paper.resoudreAttaque(cisor));
    assert(!paper.resoudreAttaque(paper));
    assert(paper.resoudreAttaque(rock));

    assert(rock.resoudreAttaque(cisor));
    assert(!rock.resoudreAttaque(paper));
    assert(!rock.resoudreAttaque(rock));

    cout << "  - resoudreAttaque Attaque\t : OK" << endl;
}

void testClass_Attaque(void)
{
    cout << "** Test de la Class Attaque **" << endl;
    testAttaque_constru();
    testAttaque_resoudreAttaque();
}
