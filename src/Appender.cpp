#include "Appender.h"
using std::string;
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
	return 0;
}

void ULAppender::Write(Appender* appender, string message){

}

void ULAppender::Destroy(Appender* appender){
	delete appender;
}
