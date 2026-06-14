#ifndef POU_H
#define POU_H
#include "stats.h"
#include <string>
using namespace std;


class Pou{
    private:
    Stats stats; // stats of pou 

    public:
        bool can_work(); // returns false if addiction_level is high 
};

#endif //POU_H