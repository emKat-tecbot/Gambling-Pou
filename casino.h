#ifndef CASINO_H
#define CASINO_H
#include <vector>
#include <memory>
#include "minigames.h"

class Pou;

class Casino {
private:
    std::vector<std::unique_ptr<Minigame>> games;
    Pou* pou;

public:
    Casino(Pou* pou);
    void showGames() const;
    int playGame(int index, int bet);
};

#endif