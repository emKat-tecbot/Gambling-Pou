#include "pou.h"
#include "Pouxception.h"
#include <iostream>
#include <string>
#include "stats.h"
using namespace std;

class Pou{
    private:
    Stats stats;
    string name;
    public:
        bool can_work(){
            return stats.getAddiction() < 80;
        };
        void update_happy(int amount){
            stats.setHappy(amount);
        };
        void update_hunger(int amount){
            stats.setHunger(amount);
        };
        void update_energy(int amount){
            stats.setEnergy(amount);
        };
        void update_hygiene(int amount){
            stats.setHygiene(amount);
        };
        void update_addiction(int amount){
            stats.setAddiction(amount);
        };
        string getName(){return name;};
        bool isDead(){
            return (stats.getHappy() == 0 || stats.getHunger() == 100 || stats.getEnergy() == 0);
        };
        bool Won(){
            return (stats.getHappy() >= 100 && stats.getHunger() <= 0 && stats.getEnergy() >= 100);
        };
        void setName(string newname){name = newname;};
};