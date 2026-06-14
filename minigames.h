#ifndef MINIGAME_H
#define MINIGAME_H

class Minigame{
    private:
    public:
        virtual void play(int bet)=0; // pure virtual function (empty function because child clases will have threire own vertion)
        virtual ~Minigame(){}; // virtual destructor to ensure proper cleanup of derived classes
        virtual void Rules()=0;
};
#endif // MINIGAME_H