#include "AppenderSettings.h"

#include <string>
#include "AppenderType.h"
#include "LogLevel.h"

using std::string;
using namespace ULAppenderSettings;

struct ULAppenderSettings::AppenderSettings {
    AppenderType type;
    LogLevel logLevel;
    string message; //esto es para revisar
    string path;
};

AppenderSettings* ULAppenderSettings::CreateAppenderConsoleSetting(LogLevel logLevel) {
    ULAppenderSettings::AppenderSettings *newAppenderSetting = new AppenderSettings;
    newAppenderSetting->type = Console;
    newAppenderSetting->logLevel = logLevel;
    newAppenderSetting->path = 0;
    return newAppenderSetting;
}

AppenderSettings* ULAppenderSettings::CreateAppenderFileSetting(LogLevel logLevel, string pathFile) {
    ULAppenderSettings::AppenderSettings* newAppenderSetting = new AppenderSettings;
    newAppenderSetting->type = File;
    newAppenderSetting->logLevel = logLevel;
    newAppenderSetting->path = pathFile;
    return newAppenderSetting;
}

LogLevel ULAppenderSettings::GetLogLevel(const AppenderSettings* settings) {
    return settings->logLevel;
}

AppenderType ULAppenderSettings::GetAppenderType(const AppenderSettings* settings) {
    return settings->type;
}

string ULAppenderSettings::GetPathFile(const AppenderSettings *settings) {
    return settings->path;
}

void ULAppenderSettings::Destroy(AppenderSettings* settings) {
    delete settings;
}
