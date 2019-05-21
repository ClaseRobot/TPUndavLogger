#include <iostream>
#include "Appender.h"
#include "DateTime.h"

using namespace std;
using namespace ULDateTime;

int main() {
	DateTime* nuevoDate = Now();
	DateTimeFormat formato1 = YYYYMMDD_HHmmss;
	string test1 = ToFormat(nuevoDate, formato1);

	DateTimeFormat formato2 = YYYYMMDD_hhmmss;
	string test2 = ToFormat(nuevoDate, formato2);

	DateTimeFormat formato3 = DDMMYYYY_hhmmss;
	string test3 = ToFormat(nuevoDate, formato3);

	DateTimeFormat formato4 = DDMMYYYY_HHmmss;
	string test4 = ToFormat(nuevoDate, formato4);

	DateTimeFormat formato5 = YYYYMMDDHHmmss;
	string test5 = ToFormat(nuevoDate, formato5);

	DateTimeFormat formato6 = YYMD_Hms;
	string test6 = ToFormat(nuevoDate, formato6);

	DateTimeFormat formato7 = YYMD_hms;
	string test7 = ToFormat(nuevoDate, formato7);

	DateTimeFormat formato8 = DMYY_hms;
	string test8 = ToFormat(nuevoDate, formato8);

	DateTimeFormat formato9 = DMYY_Hms;
	string test9 = ToFormat(nuevoDate, formato9);

	cout<<test1<<endl;
	cout<<test2<<endl;
	cout<<test3<<endl;
	cout<<test4<<endl;
	cout<<test5<<endl;
	cout<<test6<<endl;
	cout<<test7<<endl;
	cout<<test8<<endl;
	cout<<test9<<endl;
}
