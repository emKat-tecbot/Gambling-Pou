#ifndef MINIGAME_H
#define MINIGAME_H
#include <string>

class Minigame{
    private:
        std:: string name;
        int bet;
    public:
        virtual int play(int bet)=0; // pure virtual function (empty function because child clases will have threire own vertion)
        virtual ~Minigame(){}; // virtual destructor to ensure proper cleanup of derived classes
        virtual void Rules()=0;
        //getter
        std::string getName();
};
#endif // MINIGAME_H