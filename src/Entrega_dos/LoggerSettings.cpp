#include "./LoggerSettings.h"
#include "../Entrega_uno/DateTime.h"
#include "./AppenderSettings.h"

using namespace ULLoggerSettings;
using ULDateTime::DateTimeFormat;
using ULAppenderSettings::AppenderSettings;

struct Nodo{
	AppenderSettings* item;
	Nodo* siguiente;
};

struct Lista{
	Nodo* primero;
};

struct ULLoggerSettings::LoggerSettings{
	DateTimeFormat DateFormat;
	Lista* listaAppenderSettings;
};

//Precondicion: item es una instancia de @AppenderSettings valida, y proximo una instancia de @Nodo valido
//PostCondicion: se devolvera una instancia valida de @Nodo
Nodo* CrearNodo(AppenderSettings* item, Nodo* proximo);

//Precondicion: primerElemento es una instancia valida de @Nodo
//Postcondicion: Devuelve una instancia valida de @Lista con el primer elemento cargado
Lista* CrearLista(Nodo* primerElemento);

Nodo* CrearNodo(AppenderSettings* item, Nodo* proximo){
	Nodo* nuevoNodo = new Nodo;
	nuevoNodo->item = item;
	nuevoNodo->siguiente = proximo;
	return nuevoNodo;
}


Lista* CrearLista(Nodo* primerElemento){
	Lista* nuevaLista = new Lista;
	nuevaLista ->primero = primerElemento;
	return nuevaLista;
}

Nodo* ObtenerUltimoNodo(Lista* lista){
	Nodo* iterador = lista->primero;
	while(iterador->siguiente != NULL){
		iterador = iterador->siguiente;
	}
	return iterador;
}

LoggerSettings* Create(DateTimeFormat dateTimeFormat){
	ULLoggerSettings::LoggerSettings* nuevoLoggerSettings = new LoggerSettings;
	nuevoLoggerSettings->DateFormat = dateTimeFormat;
	nuevoLoggerSettings->listaAppenderSettings = CrearLista(NULL);
	return nuevoLoggerSettings;
}

void ULLoggerSettings::AddAppenderSetting(LoggerSettings* setting, AppenderSettings* appenderSetting){
	if(setting->listaAppenderSettings->primero == NULL){
		setting->listaAppenderSettings->primero = CrearNodo(appenderSetting, NULL);
	}
	else{
		Nodo* ultimoNodo = ObtenerUltimoNodo(setting->listaAppenderSettings);
		ultimoNodo->siguiente = CrearNodo(appenderSetting, NULL);
	}
}

void ULLoggerSettings::Destroy(LoggerSettings* setting){
	delete setting;
}
