#ifndef BALROG_H
#define BALROG_H

#include <iostream>
#include <string>
#include "demon.h"

namespace cs_creature {
    class Balrog : public Demon {
        public:
            Balrog();
            Balrog(int inStrength, int inHitpoints);
            std::string getSpecies() const;
            int getDamage() const;
    };
}

#endif