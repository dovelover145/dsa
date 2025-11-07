#include <iostream>
#include "creature.h"
#include "human.h"
#include "elf.h"
#include "demon.h"
#include "cyberdemon.h"
#include "balrog.h"
using namespace std;
using namespace cs_creature;

void battleArena(Creature &creature1, Creature &creature2);

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Elf e(50,50);
    Balrog b(50,50);
    battleArena(e, b);
    
    Human h(90, 90);
    Cyberdemon c(100, 20);
    battleArena(h, c);
    
    Balrog bal(120, 100);
    Human hum(10, 20);
    battleArena(bal, hum);
    
    Cyberdemon cyb(100, 100);
    Cyberdemon cyb2(100, 100);
    battleArena(cyb, cyb2);
    
    Demon dem(1000, 2000);
    Balrog bal2(1200, 3000);
    battleArena(dem, bal2);
}

void battleArena(Creature &creature1, Creature &creature2) {
    while (creature1.getHitpoints() > 0 && creature2.getHitpoints() > 0) {
        int creature1Damage = creature1.getDamage();
        cout << endl;
        int creature2Damage = creature2.getDamage();
        cout << endl;
        creature1.setHitpoints(creature1.getHitpoints() - creature2Damage);
        creature2.setHitpoints(creature2.getHitpoints() - creature1Damage);
        cout << "The " << creature1.getSpecies() << " has " << creature1.getHitpoints() << " hitpoints remaining and the " << creature2.getSpecies() << " has " << creature2.getHitpoints() << " hitpoints remaining!" << endl << endl;
    }
    
    if (creature1.getHitpoints() < 0 && creature2.getHitpoints() < 0) {
        cout << "The " << creature1.getSpecies() << " and the " << creature2.getSpecies() << " tied!" << endl;
    } else if (creature1.getHitpoints() < 0) {
        cout << "The " << creature2.getSpecies() << " won!" << endl;
    } else if (creature2.getHitpoints() < 0) {
        cout << "The " << creature1.getSpecies() << " won!" << endl;
    }
    cout << endl << endl;
}

/*
Output:
The Elf attacks for 26 points!

The Balrog attacks for 48 points!
Balrog speed attack inflicts 17 additional damage points!

The Elf has -15 hitpoints remaining and the Balrog has 24 hitpoints remaining!

The Balrog won!


The Human attacks for 66 points!

The Cyberdemon attacks for 55 points!

The Human has 35 hitpoints remaining and the Cyberdemon has -46 hitpoints remaining!

The Human won!


The Balrog attacks for 48 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 75 additional damage points!

The Human attacks for 4 points!

The Balrog has 96 hitpoints remaining and the Human has -153 hitpoints remaining!

The Balrog won!


The Cyberdemon attacks for 50 points!

The Cyberdemon attacks for 16 points!

The Cyberdemon has 84 hitpoints remaining and the Cyberdemon has 50 hitpoints remaining!

The Cyberdemon attacks for 81 points!
Demonic attack inflicts 50 additional damage points!

The Cyberdemon attacks for 47 points!
Demonic attack inflicts 50 additional damage points!

The Cyberdemon has -13 hitpoints remaining and the Cyberdemon has -81 hitpoints remaining!

The Cyberdemon and the Cyberdemon tied!


The Demon attacks for 885 points!

The Balrog attacks for 181 points!
Balrog speed attack inflicts 284 additional damage points!

The Demon has 1535 hitpoints remaining and the Balrog has 2115 hitpoints remaining!

The Demon attacks for 960 points!

The Balrog attacks for 619 points!
Balrog speed attack inflicts 130 additional damage points!

The Demon has 786 hitpoints remaining and the Balrog has 1155 hitpoints remaining!

The Demon attacks for 867 points!

The Balrog attacks for 1179 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 778 additional damage points!

The Demon has -1221 hitpoints remaining and the Balrog has 288 hitpoints remaining!

The Balrog won!
*/