#ifndef GAME_ROUNDS_H
#define GAME_ROUNDS_H
#include "Pou.h"
#include "player.h"
#include "casino.h"
#include <vector>
#include <memory>

class GameRound{
    private:
        std::unique_ptr<Pou> pou;
        std::unique_ptr<Player> player;
        std::unique_ptr<Casino> casino;
        int turn;
    public:
        GameRound();
        void start();
        void showMenu() const;
        void showStatus() const;
        void processChoice(int choice);
};

#endif //GAME_ROUNDS