#ifndef GAME_ROUNDS_H
#define GAME_ROUNDS_H
#include "Pou.h"
#include "player.h"
#include "casino.h"
#include "stats.h"
#include <vector>
#include <memory>

class GameRound{
    private:
        unique_ptr<Pou> pou;
        unique_ptr<Player> player;
        unique_ptr<Casino> casino;
        unique_ptr<Stats> stats;
        int turn;
    public:
        GameRound();
        void start();
        void showMenu() const;
        void showStatus() const;
        void processChoice(int choice);
};

#endif //GAME_ROUNDS