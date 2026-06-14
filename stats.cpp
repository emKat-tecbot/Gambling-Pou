#include "stats.h"
#include "Pouxception.h"
#include <string>
#include <iostream>
using namespace std;

class Stats {
    private:
        int happy; //goes from 0 to 100, if it reaches 0, pou dies, affected by gambling
        int hunger; //goes from 0 to 100, if it reaches 100, pou dies
        int energy; //goes from 0 to 100, if it reaches 0, pou dies
        int hygiene; //goes from 0 to 100, if it reaches 0, pou dies
        int addiction; // goes from 0 to 100, if it reaches 100, pou refuses to work and player is forced to keep gambling
        string mood; // [HAPPY, HUNGRY, TIRED, DIRTY, ADDICTED, SAD]

    public:
        Stats(): happy(50), hunger(50), energy(50), hygiene(50), addiction(0), mood("HAPPY") {};
        int barrier(int value)const{
            if (value < 0)
                return 0;
            else if (value > 100)
                return 100;
            return value;
        };
        // getters
        int getHappy(){return barrier(happy);};
        int getHunger(){return barrier(hunger);};
        int getEnergy(){return barrier(energy);};
        int getHygiene(){return barrier(hygiene);};
        int getAddiction(){return barrier(addiction);};
        string getMood(){return mood;};
        // setters
        void setHappy(int amount){
            if (happy <= 0)
                throw Pouxception("Your pou got depressed!\n");
            happy = barrier(happy + amount);
        };
        void setHunger(int amount){
            if (hunger >= 100)
                throw Pouxception("Your pou starving!\n");
            hunger = barrier(hunger + amount);
        };
        void setEnergy(int amount){
            if (energy <= 0)
                throw Pouxception("Your pou is veeery tired!\n");
            energy = barrier(energy + amount);
        };
        void setHygiene(int amount){
            if (hygiene <= 0)
                throw Pouxception("Your pou is stinky\n");
            hygiene = barrier(hygiene + amount);
        };
        void setAddiction(int amount){
            addiction = barrier(addiction + amount);
        };
        void setMood(){
            if (happy <= 30)
                mood = "SAD";
            else if (hunger >= 70)
                mood = "HUNGRY";
            else if (energy <= 30)
                mood = "TIRED";
            else if (hygiene <= 30)
                mood = "DIRTY";
            else if (addiction >= 70)
                mood = "ADDICTED";
            else
                mood = "HAPPY";
        };
};