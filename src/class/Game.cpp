// ================================================================================
// Includes
// ================================================================================
#include "Game.hpp"

#include <map>
#include <string>

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

#define LION_INDEX      0
#define LOUP_INDEX      1
#define OURS_INDEX      2
#define PIERRE_INDEX    3
#define NB_SPECIES  4
#define NB_INDIVIDUAL_BY_SPECIES DISTRIB_PLATEAU / NB_SPECIES

// ================================================================================
// Types (Struct, enum, ...)
// ================================================================================

const std::map<std::string, std::string> g_Animal_IconFromName = {
    {NAME_LION, "🦁"},
    {NAME_LOUP, "🐺"},
    {NAME_OURS, "🐻"},
    {NAME_PIERRE, "🪨"}
};

// ================================================================================
// Prototype
// ================================================================================
Animal* createRandAnimal(void);
Animal* createAnimal(uint8_t animalIndex);

// ================================================================================
// Class def
// ================================================================================

/**
 * @brief Construct a new Game object
 * Initialize Game by default
 */
Game::Game() {
    this->board = vector<vector<vector<Animal *>>>(MAX_Y, vector<vector<Animal *>>(MAX_X, vector<Animal*>(0)));
    this->resetGame();
};

bool run(void) {

}

/**
 * @brief Check if the Game is empty
 *
 * @return true
 * @return false
 */
bool Game::isEmpty()
{
    for (vector<vector<Animal *>> vect : this->board)
    {
        for (vector<Animal*> animalVect : vect)
        {
            // If there is at least on animal on a case
            if (animalVect.size() != NULL) {
                return false;
            }
        }
    }
    return true;
}

Game::~Game() {
    Animal* anim_temp;

    for (vector<vector<Animal *>> vect : this->board) {
        for (vector<Animal*> animalVect : vect) {
            while (animalVect.size() > 0) {
                anim_temp = animalVect.back();  // Get element
                animalVect.pop_back();  // Remove from vector
                delete anim_temp;   // Delete memory
            }
        }
    }
    
}

void Game::resetGame(void) {
    Animal* temp;

    // Where DISTRIB_PLATEAU is the percentage of animal on the board
    uint32_t nb_animals = (DISTRIB_PLATEAU * NB_CASES) / 100;

    int animX;
    int animY;

    cout << "Reset Game" << endl;

    for (uint32_t i = 0; i < nb_animals; i++) {
        temp = createAnimal(i%NB_SPECIES);  // Create equal population size
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
    cout << "print board game" << endl;
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
            if (animalVect.size() == 1) {
                cout << g_Animal_IconFromName.at(animalVect.at(0)->getName());
            } else if (animalVect.size() > 1) {
                cout << "💥";
            }else {
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

// ================================================================================
// Fonctions
// ================================================================================

/**
 * @brief Create a Animal object depending on animalIndex
 * 
 * @param animalIndex 
 * @return Animal* 
 */
Animal* createAnimal(uint8_t animalIndex) {
    Animal* temp = nullptr;

    switch (animalIndex) {
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
Animal* createRandAnimal(void) {
    Animal* temp = nullptr;

    uint8_t rand;
    rand = getRand(LION_INDEX, PIERRE_INDEX); // Lion and Pierre beacause they are the first and last define

    temp = createAnimal(rand);

    return temp;
}