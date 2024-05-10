#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify Test random die") {
	Die die;
    
	for (int i = 0; i < 10; ++i) {
        int result = die.roll();
	
	REQUIRE(result >= 1);
	REQUIRE(result <= 6);
    }
}

TEST_CASE("Verify Test simulate rolling dice ") {
	
	Die die1;
    Die die2;
    Roll roll(die1, die2);

    for (int i = 0; i < 10; ++i) {
        roll.roll_dice();
        int value = roll.roll_value();
	
	REQUIRE(value >= 2);
	REQUIRE(value <= 12);
    }
}

TEST_CASE("Verify Test simulate shooting dice ") {
	 Shooter shooter;
    Die die1;
    Die die2;

    for (int i = 0; i < 10; ++i) {
        Roll* roll = shooter.throw_dice(die1, die2);
        int value = roll->roll_value();

	REQUIRE(value >= 2);
	REQUIRE(value <= 12);
    }
}


TEST_CASE("Verify Test ComeOutPhaseTest ")
{
    ComeOutPhase comeOutPhase;
    Die die1, die2;

   for (int i = 0; i < 10; ++i) {
        Roll* roll = new Roll(die1, die2); 
        comeOutPhase.get_outcome(roll);
        roll->roll_dice(); 
        int rolled_value = roll->roll_value(); 

        if (rolled_value == 7 || rolled_value == 11) {
            REQUIRE(comeOutPhase.get_outcome(roll) == RollOutcome::natural);

        } else if (rolled_value == 2 || rolled_value == 3 || rolled_value == 12) {
            REQUIRE(comeOutPhase.get_outcome(roll) == RollOutcome::craps);
            
        } else {
            REQUIRE(comeOutPhase.get_outcome(roll) == RollOutcome::point);
        }
    }
}

TEST_CASE("Verify Test PointPhaseTest ")
{
    int point = 8;
    PointPhase pointPhase(point);
    Die die1, die2;

   for (int i = 0; i < 10; ++i) {
        Roll* roll = new Roll(die1, die2); 
        pointPhase.get_outcome(roll);
        roll->roll_dice(); 
        int rolled_value = roll->roll_value(); 

        if (rolled_value == point) {
            REQUIRE(pointPhase.get_outcome(roll) == RollOutcome::point);

        } else if (rolled_value == 7) {
            REQUIRE(pointPhase.get_outcome(roll) == RollOutcome::seven_out);
            
        } else {
            REQUIRE(pointPhase.get_outcome(roll) == RollOutcome::nopoint);
        }
    }
}