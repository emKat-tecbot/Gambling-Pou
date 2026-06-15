#include "player.h"
#include "pou.h"
#include "Pouxception.h"
#include <iostream>



class Player {
private:
    string id;
    int money;
    Pou* pou; // Pou determines whether player works and giplayer must take care of pou 
public:
    Player(string id, int money): id(id), money(money) {};
    ~Player();
    void work(){
        if(!pou->can_work())
            throw Pouxception("Pou too addicted to work");
        money += 100; 
        cout << "You worked!\n Money gained: 100\n";
    };
    void care_for_pou(){
        if(money < 50)
            throw Pouxception("Oops! looks like you don't have enough money! \n Why dont you try gambling......or maybe working\n");
        money -= 50;
        cout << "You cared for your pou!\n now you have: " << money << " coins left\n";
        };
    void gamble(){ 
        if (money < 50)
            throw Pouxception("Naa bro youre too poor for the casino, better luck next time\n");
        cout << "Lets gamble!...\n";
    };
    int getMoney(){return(money);};
    string getId(){return(id);};
    friend ostream& operator <<(ostream& os, const Player&p){
        os << "Player: " << p.id
        << "\n Money: $" << p.money;
        return os;
    };
};
