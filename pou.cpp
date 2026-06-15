#include "pou.h"
#include "Pouxception.h"
#include <iostream>

Pou::Pou() : name("Pou") {}

void Pou::setName(std::string newName) { name = newName; }
std::string Pou::getName(){ return name; }

void Pou::update_happy(int amount){ stats.setHappy(amount); }
void Pou::update_hunger(int amount){ stats.setHunger(amount); }
void Pou::update_energy(int amount){ stats.setEnergy(amount); }
void Pou::update_addiction(int amount) { stats.setAddiction(amount); }

bool Pou::can_work(){
    return stats.getAddiction() < 80;
}

bool Pou::isDead(){
    return (stats.getHappy() == 0 ||
            stats.getHunger() == 100 ||
            stats.getEnergy() == 0);
}

bool Pou::Won(){
    return (stats.getHappy() >= 90 &&
            stats.getAddiction() <= 10);
}

ostream& operator<<(std::ostream& os, Pou& p) {
    os << "Pou: "     << p.getName()
    << " Happiness: " << p.stats.getHappy()
    << " Hunger: "    << p.stats.getHunger()
    << " Addiction: " << p.stats.getAddiction()
    << " Mood: "      << p.stats.getMood();
    return os;
}