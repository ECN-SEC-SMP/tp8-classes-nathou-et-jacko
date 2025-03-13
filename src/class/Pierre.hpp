#ifndef _PIERRE_H_
#define _PIERRE_H_

#include "Animal.hpp"

class Pierre : public Animal
{

    private:

    public:
        Pierre(int maxX, int maxY);
        Pierre(int maxX, int maxY, int a, int b);
        ~Pierre();
        void setAttaque();

        void deplace(int maxX, int maxY);
};

#endif;