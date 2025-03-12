#ifndef _PIERRE_H_
#define _PIERRE_H_

#include "Animal.hpp"

class Pierre : public Animal
{

    private:

    public:
        void setAttaque();

        void deplace(int maxX, int maxY);
};

#endif;