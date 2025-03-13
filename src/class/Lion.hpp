#ifndef _LION_H_
#define _LION_H_

#include "Animal.hpp"

class Lion : public Animal
{

private:
public:
    Lion(int x, int y);
    Lion(int x, int y, int a, int b);
    void setAttaque();

    void deplace(int x, int y);
};

#endif