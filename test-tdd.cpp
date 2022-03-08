#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "RangeandReadings.h"

TEST_CASE("Check range and readings from charging session") {

  int chargingSession[] = {4,5};
  int size_of_charginSession = sizeof(chargingSession)/sizeof(chargingSession[0]);
  REQUIRE(getRangeandReadingsinChargingSession(chargingSession,size_of_charginSession) == "4-5, 2");
  chargingSession[] = {1,1,1,2,2,3,3,3,3,4,4,4,4};
  REQUIRE(getRangeandReadingsinChargingSession(chargingSession,size_of_charginSession) == "1-2, 5
                                                                                           3-4, 8");
}
