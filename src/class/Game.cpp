// ================================================================================
// Includes
// ================================================================================
#include "Game.hpp"

#include <string>
#include <algorithm>

#include "Animal.hpp"
#include "Lion.hpp"
#include "Loup.hpp"
#include "Ours.hpp"
#include "Pierre.hpp"

// ================================================================================
// Define
// ================================================================================
// 24 because we have 4 species and 25 isn't a multiple of 4
#define DISTRIB_PLATEAU 24 // Pourcent, le plateau est de 10x10 donc 100 cases donc 24 = 24% de 100

#define LION_INDEX 0
#define LOUP_INDEX 1
#define OURS_INDEX 2
#define PIERRE_INDEX 3
#define NB_SPECIES 4
#define NB_INDIVIDUAL_BY_SPECIES DISTRIB_PLATEAU / NB_SPECIES

// ESC = \x1B, erase screen = ESC[2J
#define ESCAPE_CODE_ERASE "\x1B[0J"
// ESC[H
#define ESPACE_CODE_CURSOR_RESET "\x1B[H"

// ================================================================================
// Types (Struct, enum, ...)
// ================================================================================

const std::map<std::string, std::string> g_Animal_IconFromName = {
    {NAME_LION, "🦁"},
    {NAME_LOUP, "🐺"},
    {NAME_OURS, "🐻"},
    {NAME_PIERRE, "🪨"}};

// ================================================================================
// Prototype
// ================================================================================
Animal *createRandAnimal(void);
Animal *createAnimal(uint8_t animalIndex);

// ================================================================================
// Class def
// ================================================================================

/**
 * @brief Construct a new Game object
 * Initialize Game by default
 */
Game::Game()
{
    this->board = vector<vector<vector<Animal *>>>(MAX_Y, vector<vector<Animal *>>(MAX_X, vector<Animal *>(0)));
    this->resetGame();
};

Game::~Game() {

}

bool Game::run(void) {

    bool continue_run = true;

    // Deplace
    this->deplaceAll();

    // Combat
    this->resolveConflict();

    // Print Board
    this->printBoardGame();
    
    // Check if player want to continue
    cout << "Press Enter to continue, q to exit" << endl;
    int c_raw;
    do {
        c_raw = (char)getchar();
        if (c_raw == 'q') {
            continue_run = false;
        }
    } while (c_raw != '\n' && c_raw != EOF);
    
    return continue_run;
}

void Game::deplaceAll(void) {
    vector<Animal*>* tile;
    Animal* toMove;

    // Deplace in board
    for (uint32_t y = 0; y < MAX_Y; y++) {
        for (uint32_t x = 0; x < MAX_X; x++) {
            tile = &this->board.at(y).at(x);
            for (uint32_t i = 0; i < tile->size(); i++) {
                tile->at(i)->deplace(MAX_X, MAX_Y);
            }
        }
    }

    // Change position of each animal
    for (uint32_t y = 0; y < MAX_Y; y++) {
        for (uint32_t x = 0; x < MAX_X; x++) {
            tile = &this->board.at(y).at(x);
            // For each anima on this tile
            for (uint32_t i = 0; i < tile->size(); i++) {
                if (tile->at(i)->getX() == x && tile->at(i)->getY() == y) {
                    // If animal already at correct postion, we pass him
                    continue;
                }

                toMove = tile->at(i);
                tile->erase(tile->begin() + i);   // Erase animal from his old tile

                this->board.at(toMove->getY()).at(toMove->getX()).push_back(toMove);
                i--;
            }
        }
    }
}

void Game::resetGame(void)
{
    Animal *temp;

    // Where DISTRIB_PLATEAU is the percentage of animal on the board
    uint32_t nb_animals = (DISTRIB_PLATEAU * NB_CASES) / 100;

    int animX;
    int animY;

    cout << "Reset Game" << endl;

    for (uint32_t i = 0; i < nb_animals; i++)
    {
        temp = createAnimal(i % NB_SPECIES); // Create equal population size
        animX = temp->getX();
        animY = temp->getY();
        this->board.at(animY).at(animX).push_back(temp);
        cout << "[resetGame] add " << temp->getName() << " to x : " << animX << " y : " << animY << endl;
    }
}

/**
 * @brief Displays the board in a terminal
 *
 */
void Game::printBoardGame()
{
    cout << ESPACE_CODE_CURSOR_RESET;
    cout << ESCAPE_CODE_ERASE;
    cout << "Animals on board : " << this->countAnimals() << endl;
    for (int i = 0; i < MAX_Y; i++)
    {
        cout << "|----";
    }
    cout << "|" << endl;
    for (vector<vector<Animal *>> vect : this->board)
    {
        for (vector<Animal *> animalVect : vect)
        {
            cout << "| ";
            if (animalVect.size() == 1)
            {
                cout << g_Animal_IconFromName.at(animalVect.at(0)->getName());
            }
            else if (animalVect.size() > 1)
            {
                cout << "💥";
            }
            else
            {
                cout << "  ";
            }
            cout << ' ';
        }
        cout << "|" << endl;
        for (int i = 0; i < MAX_Y; i++)
        {
            cout << "|----";
        }
        cout << "|" << endl;
    }
}

int Game::fight(vector<Animal *> fighters, int fighterOne, int fighterTwo)
{
    if (fighterOne < 0 || fighterTwo < 0 || fighterOne >= fighters.size() || fighterTwo >= fighters.size())
    {
        throw invalid_argument("Incorrect parameters");
    }

    int res = 0;
    fighters.at(fighterOne)->setAttaque();
    fighters.at(fighterTwo)->setAttaque();
    if (fighters.at(fighterOne)->getAttaque().getTypeAttaque() == fighters.at(fighterTwo)->getAttaque().getTypeAttaque())
    {
        res = getRand(0, 1);
        // killcam.at(animals.at(toDelete)->getName())++;
    }
    else
    {
        res = fighters.at(fighterOne)->attaque(*fighters.at(fighterTwo)) ? 1 : 0;
        // killcam.at(animals.at(toDelete)->getName())++;
    }
    return res;
}
map<string, int> Game::resolveConflict()
{
    map<string, int> killcam = {
        {NAME_OURS, 0},
        {NAME_LOUP, 0},
        {NAME_LION, 0},
        {NAME_PIERRE, 0}};

    for (vector<vector<Animal *>> line : this->board)
    {

        for (vector<Animal *> animals : line)
        {
            if (animals.size() == 2)
            {
                int toDelete = fight(animals, 0, 1);

                killcam.at(animals.at(toDelete)->getName())++;

                Animal *toKill = animals.at(toDelete);
                animals.erase(animals.begin() + toDelete);
                delete toKill;
            }
            else if (animals.size() > 2)
            {
                int firstFighter = 0;
                int secondFighter = 0;
                while (animals.size() != 1)
                {
                    firstFighter = getRand(0, animals.size() - 1);
                    do
                    {
                        secondFighter = getRand(0, animals.size() - 1);
                    } while (firstFighter == secondFighter);

                    int toDelete = fight(animals, firstFighter, 1);

                    killcam.at(animals.at(toDelete)->getName())++;

                    Animal *toKill = animals.at(toDelete);
                    animals.erase(animals.begin() + toDelete);
                    delete toKill;
                }
            }
        }
    }
    return killcam;
}

uint32_t Game::countAnimals(void) {
    uint32_t count = 0;

    for (uint32_t y = 0; y < MAX_X; y++) {
        for (uint32_t x = 0; x < MAX_Y; x++) {
            count += this->board.at(y).at(x).size();
        }
    }
    
    return count;
}

// ================================================================================
// Fonctions
// ================================================================================

/**
 * @brief Create a Animal object depending on animalIndex
 *
 * @param animalIndex
 * @return Animal*
 */
Animal *createAnimal(uint8_t animalIndex)
{
    Animal *temp = nullptr;

    switch (animalIndex)
    {
    case LION_INDEX:
        temp = new Lion(MAX_X, MAX_Y);
        break;

    case LOUP_INDEX:
        temp = new Loup(MAX_X, MAX_Y);
        break;

    case OURS_INDEX:
        temp = new Ours(MAX_X, MAX_Y);
        break;

    case PIERRE_INDEX:
        temp = new Pierre(MAX_X, MAX_Y);
        break;

    default:
        break;
    }

    return temp;
}

/**
 * @brief Create a Rand Animal object with equi probability
 *
 * @return Animal*
 */
Animal *createRandAnimal(void)
{
    Animal *temp = nullptr;

    uint8_t rand;
    rand = getRand(LION_INDEX, PIERRE_INDEX); // Lion and Pierre beacause they are the first and last define

    temp = createAnimal(rand);

    return temp;
}