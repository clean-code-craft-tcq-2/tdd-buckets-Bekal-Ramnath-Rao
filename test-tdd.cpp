#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "RangeandReadings.h"

TEST_CASE("Check range and readings from charging session") {

  int chargingSession1[] = {4,5};
  int size_of_charginSession1 = sizeof(chargingSession1)/sizeof(chargingSession1[0]);
  REQUIRE(getRangeandReadingsinChargingSession(chargingSession1,size_of_charginSession1) == "4-5, 2");
  int chargingSession2[] = {1,1,1,2,2,3,3,3,3,4,4,4};
  int size_of_charginSession2 = sizeof(chargingSession2)/sizeof(chargingSession2[0]);
  REQUIRE(getRangeandReadingsinChargingSession(chargingSession2,size_of_charginSession2) == "1-2, 5\n3-4, 7");
}
