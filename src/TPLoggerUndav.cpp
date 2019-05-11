#include <iostream>
#include "Appender.h"
#include "DateTime.h"

using namespace std;
using ULAppender::Appender;
using ULDateTime::DateTime;


void WriteLog(Appender* appender, string message);

int main() {
	Appender* consoleAppender = ULAppender::CreateConsoleAppender();
	Appender* fileAppender = ULAppender::CreateFileAppender("salidaLogger.txt");
	for(char number = '0'; number <= '9'; ++number){
		string numberLine = "Linea ";
		numberLine.push_back(number);
		WriteLog(consoleAppender, numberLine + " - Salida por Consola");
		WriteLog(fileAppender, numberLine + " - Salida por Archivo");
	}

	Destroy(consoleAppender);
	Destroy(fileAppender);
	return 0;
}

void WriteLog(Appender* appender, string message){
	DateTime* now = ULDateTime::Now();
	string nowFormatted = ULDateTime::ToFormat(now, ULDateTime::DDMMYYYY_hhmmss);
	ULAppender::Write(appender, nowFormatted + " - " + message);
	ULDateTime::Destroy(now);
}
