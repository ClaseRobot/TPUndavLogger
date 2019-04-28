#include <string>
#include "DateTime.h"

using std::string;
using ULDateTime::DateTimeFormat;
using ULDateTime::DateTime;

struct ULDateTime::DateTime{

};

DateTime* ULDateTime::Now(){
	return 0;
}

DateTime* ULDateTime::UTCNow(){
	return 0;
}

DateTime* ULDateTime::Create(unsigned int year = 2019, unsigned int month = 1, unsigned int day = 1, unsigned int hour=0, int minutes=0, int seconds=0){
	return 0;
}

unsigned int ULDateTime::GetYear(const DateTime* dateTime){
	return 0;
}

unsigned int ULDateTime::GetMonth(const DateTime* dateTime){
	return 0;
}

unsigned int ULDateTime::GetDay(const DateTime* dateTime){
	return 0;
}

unsigned int ULDateTime::GetHour(const DateTime* dateTime){
	return 0;
}

unsigned int ULDateTime::GetMinutes(const DateTime* dateTime){
	return 0;
}

unsigned int ULDateTime::GetSeconds(const DateTime* dateTime){
	return 0;
}

string ULDateTime::ToFormat(const DateTime* dateTime, DateTimeFormat format){
	return "";
}

void ULDateTime::Destroy(DateTime* dateTime){
}
