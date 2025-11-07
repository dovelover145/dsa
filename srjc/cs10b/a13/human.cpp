#include <iostream>
#include <string>
#include "human.h"
#include "creature.h"
using namespace std;

namespace cs_creature {
    Human::Human() : Creature() {
    }

    Human::Human(int inStrength, int inHitpoints) : Creature(inStrength, inHitpoints) {
    }

    string Human::getSpecies() const {
        return "Human";
    }
        
    /*
    int Human::getDamage() const {
        int damage;
        damage = Creature::getDamage();
        cout << getSpecies() << " attacks for " << damage << " points!" << endl;
        return damage;
    }
    */
}
