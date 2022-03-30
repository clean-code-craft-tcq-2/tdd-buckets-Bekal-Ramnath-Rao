#include<stdio.h>
#include<string>

using namespace std;

string getRangeandReadingsinChargingSession(int*, int, int);
int convertDigitalToAnalog(const int*,int,int,int,void (*)(),int (*)(const int*,int),float (*)(int,int,int));
void printonConsole();
int convertBinarytoDecimal(const int* ,int);
int convertDigitalToAnalog_chargingAnddischarging(const int*,int,int,void (*)(),int (*)(const int*,int));