#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>

namespace cs_creature {
    class Creature {
        private:
            int strength;
            int hitpoints;
        public:
            Creature();
            Creature(int inStrength, int inHitpoints);
            virtual std::string getSpecies() const = 0;
            virtual int getDamage() const;
            int getStrength() const;
            int getHitpoints() const;
            void setStrength(int inStrength);
            void setHitpoints(int inHitpoints);
    };
}

#endif
