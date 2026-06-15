#ifndef SLOT_MACHINE_H
#define SLOT_MACHINE_H
#include "minigames.h"
#include <vector>
#include <string>

class Slot_Machine : public Minigame {
private:
    std::string name;
    const std::vector<std::string> symbols;

public:
    Slot_Machine();
    std::string spin();
    int play(int bet) override;
    void Rules() override;
    std::string getName(){};
};

#endif // SLOT_MACHINE_H