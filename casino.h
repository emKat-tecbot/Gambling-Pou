#ifndef CASINO_H
#define CASINO_H
#include <vector>
#include <string>
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
    bool playGame(int index, int bet);
};

#endif //CASINO_H