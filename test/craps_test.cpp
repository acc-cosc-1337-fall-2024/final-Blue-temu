#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"

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