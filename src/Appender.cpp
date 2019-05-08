#include "Appender.h"
using std::string;
using ULAppender::Appender;

struct ULAppender::Appender{
	int param;
};

Appender* ULAppender::CreateFileAppender(string pathFile){
	return 0;
}

Appender* ULAppender::CreateConsoleAppender(){
	return 0;
}

void ULAppender::Write(Appender* appender, string message){

}

void ULAppender::Destroy(Appender* appender){
	delete appender;
}
