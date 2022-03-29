#include "RangeandReadings.h"
#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int convertBinarytoDecimal(const int* binaryValue,int sizeofArray)
{
	int bit_value = 1;
	int Decimal_value = 0;

	for(int i=sizeofArray-1;i>0;i--)
	{
		if(binaryValue[i] != 0)
		{
			Decimal_value = Decimal_value + bit_value ; 
		} 
		bit_value = bit_value*2;
	}

	return Decimal_value;
}

float convertDecimaltoAnalogue(int Decimal_value, int maximum_limit)
{
	return maximum_limit * (Decimal_value/ (pow(2,12)-2));
}

void roundoffAnalogValue(float Analog_value,int* addr_roundedoffValue)
{
	*addr_roundedoffValue = Analog_value + 0.5;
}

void printonConsole()
{
	cout<<"value is grater than the capacity of ADC, go for higher bit ADC"<<endl;
}
int convertDigitalToAnalog(const int* binaryValue,int sizeofArray, int maximum_limit,
						   void (*funp_printonConsole)(),int (*funp_convertBinarytoDecimal)(const int*,int))
{
	float Analog_value = 0;
	int roundedoff_value;
	int Decimal_value = funp_convertBinarytoDecimal(binaryValue,sizeofArray);

	if(Decimal_value < 4095)
	{
		Analog_value = convertDecimaltoAnalogue(Decimal_value,maximum_limit);
		roundoffAnalogValue(Analog_value,&roundedoff_value);
	}
	else
	{
		funp_printonConsole;
	}
	return roundedoff_value;
}

bool isChargingSessionWithintherange(int index,const int* chargingSession, const int* range)
{
	return (chargingSession[index]>=range[0]) && (chargingSession[index]<=range[1]);
}

int determineNoOfReadingsfromRange(const int* range,const int* chargingSession, int no_of_ChargingSession)
{
	int readings=0;

	for(int index=0;index<no_of_ChargingSession;index++)
	{
		if(isChargingSessionWithintherange(index,chargingSession,range))
		{
			readings++;
		}
	}

	return readings;
}

void loopOverInnerindex(int Inner_index, int Outer_Index,int no_of_ChargingSession, int* l_chargingSession)
{
	int temporary_element;
	while(Inner_index<no_of_ChargingSession)
	{
		if(l_chargingSession[Inner_index]<l_chargingSession[Outer_Index])
		{
			temporary_element=l_chargingSession[Inner_index];
			l_chargingSession[Inner_index]=l_chargingSession[Outer_Index];
			l_chargingSession[Outer_Index]=temporary_element;
		}
		Inner_index++;
	}
}

void arrangeChargingSesssioninAscendingOrder(int* l_chargingSession,int no_of_ChargingSession)
{
	int temporary_element ,Outer_index;

	//Algorithm to arrange charging session in Ascending Order
	for(Outer_index=0;Outer_index<no_of_ChargingSession;Outer_index++)
	{		
		loopOverInnerindex(Outer_index+1,Outer_index,no_of_ChargingSession,l_chargingSession);
	}
}

int sliceRangeandgetNoOfRangefromChargingSession(const int* chargingSession, int no_of_ChargingSession,int (*l_range)[2], int IntervalForRange)
{
	int lower_limit = chargingSession[0];
	int upper_limit = chargingSession[no_of_ChargingSession-1];
	int no_of_range=0;
	int index=0;

	// Algorithm to slice the range
	while(lower_limit<=upper_limit)
	{
		l_range[no_of_range][0]= lower_limit;
		l_range[no_of_range][1]= lower_limit + IntervalForRange;
		while(!(chargingSession[index]>(lower_limit + IntervalForRange)))
		{
			index++;
		}
		lower_limit = chargingSession[index];
		no_of_range++;
	}

	return no_of_range;
}

string getRangeandReadingsinChargingSession(int* chargingSession,int no_of_ChargingSession, int IntervalForRange)
{
	int range[100][2]={};
	int row_index;
	string RANGES_READINGS = {};
	arrangeChargingSesssioninAscendingOrder(chargingSession,no_of_ChargingSession);
	int no_of_rows=sliceRangeandgetNoOfRangefromChargingSession(chargingSession,no_of_ChargingSession,range,IntervalForRange);

	for(row_index=0;row_index<no_of_rows;row_index++)
	{
		int  reading = determineNoOfReadingsfromRange(range[row_index],chargingSession, no_of_ChargingSession);
		RANGES_READINGS = RANGES_READINGS + to_string(range[row_index][0])+"-"+to_string(range[row_index][1])+","+" "+to_string(reading); //printing in csv format
		
		if(row_index!=no_of_rows-1)//no need to add line once you have reached last slice of range
		{
			RANGES_READINGS = RANGES_READINGS+"\n";
		}
	}

	return RANGES_READINGS;
}
