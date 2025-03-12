#include "Animal.hpp"


Animal::Animal(int maxX, int maxY) {
    this->x = 0;
    this->y = 0;

}

Animal::Animal(int maxX, int maxY, int a, int b) {
    
    this->x = a;
    this->y = b;
}

string Animal::getName() const {
    return this->name;
}

int Animal::getX() const {
    return this->x;
}

int Animal::getY() const {
    return this->y;
}

bool Animal::getVivant() const {
    return this->living;
}

void Animal::setVivant(bool y) {
    
    if (y != 0 && y != 1) {
        throw invalid_argument("Y doit valoir 0 ou 1.");
    }
    this->y = y;
}

Attaque Animal::getAttaque() const {
    return this->typeAttaque;
}

bool Animal::attaque(Animal &a) {
    Attaque target = a.getAttaque();
    return this->typeAttaque.resoudreAttaque(target);
}
