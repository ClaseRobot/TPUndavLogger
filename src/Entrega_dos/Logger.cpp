#include "Logger.h"

#include "../Entrega_uno/DateTime.h"
#include "LogLevel.h"
#include <string>

using std::string;
using ULAppender::Appender;
using ULDateTime::DateTimeFormat;
using namespace ULLogger;

struct Nodo {
    Appender* item;
    Nodo* siguiente;
};

struct Lista {
    Nodo* nodo;
};

struct ULLogger::Logger {
    DateTimeFormat dateFormat;
    Lista* listaAppenders;
};

Nodo* CrearNodo(Appender* item, Nodo* proximo);

Lista* CrearLista(Nodo* primerElemento);

Nodo* ObtenerUltimoNodo(Lista* lista);

Nodo* CrearNodo(Appender* item, Nodo* proximo) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->item = item;
    nuevoNodo->siguiente = proximo;
    return nuevoNodo;
}

Lista* CrearLista(Nodo* primerElemento) {
    Lista* nuevaLista = new Lista;
    nuevaLista->nodo = primerElemento;
    return nuevaLista;
}

Nodo* ObtenerUltimoNodo(Lista* lista) {
    Nodo* iterador = lista->nodo;
    while (iterador->siguiente != NULL)
    {
        iterador = iterador->siguiente;
    }
    return iterador;
}

Logger *ULLogger::Create(DateTimeFormat dateTimeFormat = ULDateTime::DDMMYYYY_hhmmss) {
    ULLogger::Logger *newLogger = new Logger;
    newLogger->dateFormat = dateTimeFormat;
    newLogger->listaAppenders = CrearLista(NULL);
    return newLogger;
}

void ULLogger::SetDateTimeFormat(Logger *logger, DateTimeFormat dateTimeFormat) {
    logger->dateFormat = dateTimeFormat;
}

DateTimeFormat ULLogger::GetDateTimeFormat(const Logger *logger) {
    return logger->dateFormat;
}

/*
	 * Precondicion: @logger construido con la primitiva CreateLogger.
	 * @appender construido con alguna de sus primitivas de construccion.
	 * Postcondicion: Si no existe el @appender, lo agrega en @logger y le asocia el @level al mismo @appender.
	 * Si ya existe el @appender, lo elimina y lo reemplaza.
	 * Dos appender de tipo consola siempre son iguales. Dos appender de tipo archivo son iguales si tienen el mimsmo path file.
	 */
void ULLogger::AddAppender(Logger* logger, Appender* appender, LogLevel level) {
    if (logger->listaAppenders->nodo == NULL)
    {
        logger->listaAppenders->nodo = CrearNodo(appender, NULL);
        //Falta asignarle el loglevel
    } else {
        Nodo *ultimoNodo = ObtenerUltimoNodo(logger->listaAppenders);
        ultimoNodo->item = appender;
        ultimoNodo->siguiente = NULL;
    }
}

// Postcondicion : Si el @appender existe en @logger lo elimina(ya no se puede logear mas en ese appender).
// *Si el @appender no existe, no se realiza ninguna accion
void ULLogger::RemoveAppender(Logger *logger, Appender *appender) {
    if (logger->listaAppenders->nodo->item != NULL)
    {

    }
}

/*
	 * Precondicion: @logger construido con la primitiva CreateLogger
	 * Postcondicion: Si el @logger no tiene appenders no realiza acci�n.
	 * Si hay appenders chequea en cada appender si el 'Log level' asociado al appender es distinto de 'OFF'
	 * entonces escribe en el appender el mensaje dado por parametro en @message.
	 * El formato del 'log' que escribe el logger en cada appender debe ser: "[datetime] [FATAL]: @message"
	 * donde [datetime] es la fecha y hora actual en el formato configurado
	 */
void ULLogger::LogFatalMessage(Logger *logger, string message) {
    if (logger->listaAppenders->nodo->item != NULL)
    {
        if (logger->listaAppenders->nodo->item->logLevel == 'OFF')
        {
            logger->listaAppenders->nodo->item->message = message;
        }
    }
}

void ULLogger::LogErrorMessage(Logger *logger, string message) {
    if (logger->listaAppenders->nodo->item != NULL)
    {
        if (logger->listaAppenders->nodo->item->logLevel == 'ERROR')
        {
            logger->listaAppenders->nodo->item->message = message;
        }
        if (logger->listaAppenders->nodo->item->logLevel == 'WARN')
        {
            logger->listaAppenders->nodo->item->message = message;
        }
        if (logger->listaAppenders->nodo->item->logLevel == 'INFO')
        {
            logger->listaAppenders->nodo->item->message = message;
        }
        if (logger->listaAppenders->nodo->item->logLevel == 'DEBUG')
        {
            logger->listaAppenders->nodo->item->message = message;
        }
        if (logger->listaAppenders->nodo->item->logLevel == 'TRACE')
        {
            logger->listaAppenders->nodo->item->message = message;
        }
    }
}

void ULLogger::LogWarningMessage(Logger *logger, string message) {

}

void ULLogger::LogInfoMessage(Logger *logger, string message) {

}

void ULLogger::LogDebugMessage(Logger *logger, string message) {

}

void ULLogger::LogTraceMessage(Logger *logger, string message) {

}

void ULLogger::Destroy(Logger *logger) {
    delete logger;
}
