#include <iostream>
#include "Appender.h"
using std::string;
using std::cout;
using std::endl;
using ULAppender::Appender;

enum Type{file, console};

struct ULAppender::Appender{
	Type type;
	string pathfile;
};

Appender* ULAppender::CreateFileAppender(string pathFile){
	Appender* newFile = NULL;
	bool validPathFile = (pathFile != "");
	if(validPathFile){
		newFile = new Appender;
		newFile->type = Type::file;
		newFile->pathfile = pathFile;
	}
	return newFile;
}

Appender* ULAppender::CreateConsoleAppender(){
	Appender* messageConsole = new Appender;
	messageConsole->type = Type::console;
	messageConsole->pathfile = "console aplication";
	return messageConsole;
}

void ULAppender::Write(Appender* appender, string message){
	if(appender->type == Type::console){
		std::cout<<message<<std::endl;
	}

}

void ULAppender::Destroy(Appender* appender){
	delete appender;
}
