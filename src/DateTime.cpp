#include <string>
#include <cstddef>
#include <time.h>
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

//PreCondicion: el timpo debe ser un puntero hacia una estructura tm valida
//PostCondicion: Se devolvera una estructura DateTime parseada a partir de tm
DateTime* CreateTM(tm* tiempo);

DateTime* ULDateTime::Now(){
	tm* tiempoLocal;
	time_t tiempo = time(0);
	tiempoLocal = localtime(&tiempo);
	return CreateTM(tiempoLocal);
}

DateTime* ULDateTime::UTCNow(){
	tm* tiempoUTC;
	time_t tiempo = time(0);
	tiempoUTC = gmtime(&tiempo);
	return CreateTM(tiempoUTC);
}

DateTime* ULDateTime::Create(unsigned int year = 2019, unsigned int month = 1, unsigned int day = 1, unsigned int hour=0, int minutes=0, int seconds=0){
	DateTime* nuevoDateTime = NULL;
	if((month < 12 && month > 0) && (day < 32 && day > 0) && year > 0){
		if(hour < 24 && minutes < 60 && seconds < 60){
			nuevoDateTime = new DateTime;
			nuevoDateTime->day = day;
			nuevoDateTime->hour = hour;
			nuevoDateTime->minute = minutes;
			nuevoDateTime->month = month;
			nuevoDateTime->seconds = seconds;
			nuevoDateTime->year = year;
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

DateTime* CreateTM(tm* tiempo){
	DateTime* nuevoDateTime = ULDateTime::Create(tiempo->tm_year + 1900,
			tiempo->tm_mon,
			tiempo->tm_mday,
			tiempo->tm_hour,
			tiempo->tm_min,
			tiempo->tm_sec
			);
	return nuevoDateTime;
}
