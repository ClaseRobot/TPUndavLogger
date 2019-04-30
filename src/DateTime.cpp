#include <string>
#include <cstddef>
#include "DateTime.h"

using std::string;
using ULDateTime::DateTimeFormat;
using ULDateTime::DateTime;

struct ULDateTime::DateTime{
	unsigned int year;
	unsigned int month;
	unsigned int day;
	unsigned int hour;
	unsigned int minute;
	unsigned int seconds;
};

DateTime* ULDateTime::Now(){
	return 0;
}

DateTime* ULDateTime::UTCNow(){
	return 0;
}

DateTime* ULDateTime::Create(unsigned int year = 2019, unsigned int month = 1, unsigned int day = 1, unsigned int hour=0, int minutes=0, int seconds=0){
	DateTime* nuevoDateTime = NULL;
	if((month < 13 && month > 0) && (day < 32 && day > 0) && year > 0){
		if(hour < 24 && minutes < 60 && seconds < 60){
			nuevoDateTime = new DateTime;
		}
	}
	return nuevoDateTime;
}

unsigned int ULDateTime::GetYear(const DateTime* dateTime){
	return dateTime->year;
}

unsigned int ULDateTime::GetMonth(const DateTime* dateTime){
	return dateTime->month;
}

unsigned int ULDateTime::GetDay(const DateTime* dateTime){
	return dateTime->day;
}

unsigned int ULDateTime::GetHour(const DateTime* dateTime){
	return dateTime->hour;
}

unsigned int ULDateTime::GetMinutes(const DateTime* dateTime){
	return dateTime->minute;
}

unsigned int ULDateTime::GetSeconds(const DateTime* dateTime){
	return dateTime->seconds;
}

string ULDateTime::ToFormat(const DateTime* dateTime, DateTimeFormat format){
	return "";
}

void ULDateTime::Destroy(DateTime* dateTime){
	delete dateTime;
}
