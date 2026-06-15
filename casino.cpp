#include "casino.h"
#include "Slot_Machine.h"
#include "Pou.h"
#include "high_or_lowMG.h"
#include "Pouxception.h"
#include <iostream>

class Casino {
private:
    std::vector<std::unique_ptr<Minigame>> games;
    Pou* pou;
public:
    Casino(Pou* pou){// so that the casino actions point to main pou and affect his addiction
        games.push_back(make_unique<Slot_Machine>()); //game 1
        games.push_back(make_unique<High_or_Low>()); //game 2
    };
    void showGames() const{
        for(int i = 0; i < (int)games.size();i++){
            cout << "CASINO GAMES" << endl;
            cout << i+1 << ". " << games[i]->getName()<< endl;
        };
    };
    bool playGame(int index, int bet){
        if(index < 0 || index > games.size())
            throw Pouxception("Whoops! we dont have that one sorry\n");
        pou->update_addiction(10);
        bool won = games[index]->play(bet);
        if(won){
            pou->update_happy(15);
            pou->update_addiction(10);
        }else{
            pou->update_happy(-15);
            pou->update_addiction(5);
        };
        return won;
    };
};