#ifndef MINIGAME_H
#define MINIGAME_H
#include <string>
#include <iostream>

class Minigame {
protected:
    std::string name;

public:
    Minigame(const std::string& Nname) : name(Nname) {}
    virtual int play(int bet) = 0; 
    virtual void Rules() const = 0; 
    virtual ~Minigame() {} 

    std::string getName() const { return name; }
};

#endif