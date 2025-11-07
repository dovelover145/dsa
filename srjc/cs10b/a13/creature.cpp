#include <iostream>
#include <string>
#include <cstdlib>
#include "creature.h"
using namespace std;

namespace cs_creature {
    Creature::Creature() {
        strength = 10;
        hitpoints = 10;
    }
        
    Creature::Creature(int inStrength, int inHitpoints) {
        strength = inStrength;
        hitpoints = inHitpoints;
    }

    /*
    string Creature::getSpecies() const {
        return "Creature";
    }
    */

    int Creature::getDamage() const {
        int damage;
        damage = (rand() % strength) + 1;
        cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
        return damage;
    }

    int Creature::getStrength() const {
        return strength;
    }

    int Creature::getHitpoints() const {
        return hitpoints;
    }

    void Creature::setStrength(int inStrength) {
        strength = inStrength;
    }

    void Creature::setHitpoints(int inHitpoints) {
        hitpoints = inHitpoints;
    }
}