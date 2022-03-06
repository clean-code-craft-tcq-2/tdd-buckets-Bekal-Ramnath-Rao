#include "RangeandReadings.h"
#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int determineNoOfReadingsfromRange(const int* range,const int* chargingSession)
{
	int readings=0;
	int size = sizeof(chargingSession)/sizeof(chargingSession[0]);

	for(int i=0;i<size;i++)
	{
		if((chargingSession[i]>=range[0]) && (chargingSession[i]<=range[1]))
		{
			readings++;
		}
	}

	return readings;
}

int findtheupperlimitinChargingSession(const int* chargingSession)
{
	int size = sizeof(chargingSession)/sizeof(chargingSession[0]);
	int upper_limit = chargingSession[0];

	for(int i=0;i<size;i++)
	{
		if(upper_limit<chargingSession[i])
		{
			upper_limit = chargingSession[i];
		}
	}

	return upper_limit;
}

int findthelowerlimitinChargingSession(const int* chargingSession)
{
	int size = sizeof(chargingSession)/sizeof(chargingSession[0]);
	int lower_limit = chargingSession[0];

	for(int i=0;i<size;i++)
	{
		if(lower_limit>chargingSession[i])
		{
			lower_limit = chargingSession[i];
		}
	}

	return lower_limit;
}

void determineRangefromChargingSession(const int* chargingSession, int *l_range)
{
	int lower_limit = findthelowerlimitinChargingSession(chargingSession);
	int upper_limit = findtheupperlimitinChargingSession(chargingSession);

	l_range[0] = {lower_limit};
	l_range[1] = {upper_limit};
}

string getRangeandReadingsinChargingSession(const int* chargingSession)
{
	int range[2];
	determineRangefromChargingSession(chargingSession,range);
	int  reading = determineNoOfReadingsfromRange(range,chargingSession);

	return to_string(range[0])+"-"+to_string(range[1])+","+" "+to_string(reading);
}