#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>
#include "creature.h"

namespace cs_creature {
    class Human : public Creature {
        public:
            Human();
            Human(int inStrength, int inHitpoints);
            std::string getSpecies() const;
            // int getDamage() const;
    };
}

#endif
