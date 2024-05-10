//
#include "come_out_phase.h"
#include "roll.h"


RollOutcome ComeOutPhase::get_outcome(Roll* roll) {
     int rolled_value = roll->roll_value();
    if (rolled_value == 7 || rolled_value == 11) {
        return RollOutcome::natural;
    } else if (rolled_value == 2 || rolled_value == 3 || rolled_value == 12) {
        return RollOutcome::craps;
    } else {
        return RollOutcome::point;
    }
}
