#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"


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
