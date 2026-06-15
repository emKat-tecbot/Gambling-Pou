#include "stats.h"
#include "Pouxception.h"
#include <iostream>

Stats::Stats()
    : happy(50), hunger(50), energy(50),
      hygiene(50), addiction(15), mood("HAPPY") {}

int Stats::barrier(int value)const{
    if (value < 0)   return 0;
    if (value > 100) return 100;
    return value;
}

// getters
int Stats::getHappy(){ return happy; }
int Stats::getHunger(){ return hunger; }
int Stats::getEnergy(){ return energy; }
int Stats::getHygiene(){ return hygiene; }
int Stats::getAddiction(){ return addiction; }
std::string Stats::getMood(){ return mood; }

// setters
void Stats::setHappy(int amount) {
    if (happy <= 0)
        throw Pouxception("Your Pou got depressed!");
    happy = barrier(happy + amount);
}

void Stats::setHunger(int amount) {
    if (hunger >= 100)
        throw Pouxception("Your Pou is starving!");
    hunger = barrier(hunger + amount);
}

void Stats::setEnergy(int amount) {
    if (energy <= 0)
        throw Pouxception("Your Pou is very tired!");
    energy = barrier(energy + amount);
}

void Stats::setHygiene(int amount) {
    if (hygiene <= 0)
        throw Pouxception("Your Pou is stinky!");
    hygiene = barrier(hygiene + amount);
}

void Stats::setAddiction(int amount) {
    addiction = barrier(addiction + amount);
}

void Stats::setMood() {
    if      (happy <= 30)     mood = "SAD";
    else if (hunger >= 70)    mood = "HUNGRY";
    else if (energy <= 30)    mood = "TIRED";
    else if (hygiene <= 30)   mood = "DIRTY";
    else if (addiction >= 70) mood = "ADDICTED";
    else                      mood = "HAPPY";
}