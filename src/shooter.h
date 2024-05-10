//
#ifndef SHOOTER_H
#define SHOOTER_H

#include <vector>
#include "roll.h"

class Shooter {
public:
    Roll* throw_dice(Die& die1, Die& die2);
    void display_rolled_values();
    ~Shooter();

private:
    std::vector<Roll*> rolls;
};

#endif