//
#include "point_phase.h"

PointPhase::PointPhase(int p) : point(p) {}

RollOutcome PointPhase::get_outcome(Roll* roll) {
    int rolled_value = roll->roll_value();
    if (rolled_value == point) {
        return RollOutcome::point;
    } else if (rolled_value == 7) {
        return RollOutcome::seven_out;
    } else {
        return RollOutcome::nopoint;
    }
}
