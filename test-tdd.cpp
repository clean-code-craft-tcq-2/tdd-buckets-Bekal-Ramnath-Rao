#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "RangeandReadings.h"

TEST_CASE("Check range and readings from charging session") {

  int chargingSession[] = {4,5};
  int size_of_charginSession = sizeof(chargingSession)/sizeof(chargingSession[0]);
  REQUIRE(getRangeandReadingsinChargingSession(chargingSession,size_of_charginSession) == "4-5, 2");

}