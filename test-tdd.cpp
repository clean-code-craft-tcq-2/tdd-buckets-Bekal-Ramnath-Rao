#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "RangeandReadings.h"

TEST_CASE("Check range and readings from charging session") {

  int chargingSession1[] = {4,5};
  int size_of_charginSession1 = sizeof(chargingSession1)/sizeof(chargingSession1[0]);
  REQUIRE(getRangeandReadingsinChargingSession(chargingSession1,size_of_charginSession1,1) == "4-5, 2");
  int chargingSession2[] = {1,1,1,2,2,3,3,3,3,4,4,4};
  int size_of_charginSession2 = sizeof(chargingSession2)/sizeof(chargingSession2[0]);
  REQUIRE(getRangeandReadingsinChargingSession(chargingSession2,size_of_charginSession2,1) == "1-2, 5\n3-4, 7");
  int chargingSession3[] = {1,1,1,2,2,3,3,3,3,4,4,4};
  int size_of_charginSession3 = sizeof(chargingSession3)/sizeof(chargingSession3[0]);
  REQUIRE(getRangeandReadingsinChargingSession(chargingSession3,size_of_charginSession3,2) == "1-3, 9\n4-6, 3");
  int chargingSession4[] = {3, 3, 5, 4, 10, 11, 12};
  int size_of_charginSession4 = sizeof(chargingSession4)/sizeof(chargingSession4[0]);
  REQUIRE(getRangeandReadingsinChargingSession(chargingSession4,size_of_charginSession4,2) == "3-5, 4\n10-12, 3");
}

TEST_CASE("Check conversion digital to Analog"){
  int Digital_value1[12] = {0,1,1,0,1,1,0,0,0,1,1,0} ;
  int size_of_Array = sizeof(Digital_value1)/sizeof(Digital_value1[0]);
  void (*funp_printOnConsole)() = printonConsole;
  int (*funp_convertBinarytoDecimal)(const int*,int) = convertBinarytoDecimal;
  float (*funp_convertDecimaltoAnalog)(int,int,int) = convertDecimaltoAnalog;
  REQUIRE(convertDigitalToAnalog(Digital_value1, size_of_Array, 10,12,funp_printOnConsole,funp_convertBinarytoDecimal,funp_convertDecimaltoAnalog) == 4);
}


TEST_CASE("Check conversion Analog to digital for sensor that calculates charging and discharging current"){
  int Digital_value1[10] = {1,1,1,1,1,0,0,0,0,1} ;
  int size_of_Array = sizeof(Digital_value1)/sizeof(Digital_value1[0]);
  void (*funp_printOnConsole)() = printonConsole;
  int (*funp_convertBinarytoDecimal)(const int*,int) = convertBinarytoDecimal;
  float (*funp_convertDecimaltoAnalog)(int,int,int) = convertDecimaltoAnalog;
  REQUIRE(convertDigitalToAnalog(Digital_value1, size_of_Array, 15,10,funp_printOnConsole,funp_convertBinarytoDecimal,funp_convertDecimaltoAnalog) ==14);
}
