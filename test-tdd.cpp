#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "RangeandReadings.h"

TEST_CASE("") {

  int chargingSession[] = {4,5}
  REQUIRE(getRangeandReadingsinChargingSession(chargingSession) == "4-5, 2");

}
