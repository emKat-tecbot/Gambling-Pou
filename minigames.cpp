#ifndef MINIGAME_H
#define MINIGAME_H
#include <string>
#include <iostream>

class Minigame {
protected:
    std::string name;

public:
    Minigame(const std::string& name)
        : name(name){}

    virtual int play(int bet) = 0;       // pure virtual — forces child to implement
    virtual void Rules() const = 0;      // pure virtual — forces child to implement
    virtual ~Minigame() {}               // virtual destructor — required for polymorphism

    // getters
    std::string getName() const { return name; }
};

#endif