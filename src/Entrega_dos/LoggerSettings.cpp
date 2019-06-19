#include "./LoggerSettings.h"
#include "../Entrega_uno/DateTime.h"
#include "./AppenderSettings.h"
#include <string>

using std::to_string;
using ULDateTime::DateTimeFormat;
using ULAppenderSettings::AppenderSettings;
using ULLoggerSettings::LoggerSettings;

struct Nodo{
	ULAppenderSettings::AppenderSettings* item;
	Nodo* siguiente;
};

struct Lista{
	Nodo* primero;
};

struct ULLoggerSettings::LoggerSettings{
	DateTimeFormat DateFormat;
	Lista* listaAppenderSettings;
};

Nodo* CrearNodo(AppenderSettings* item, Nodo* proximo){
	Nodo* nuevoNodo = new Nodo;
	nuevoNodo->item = item;
	nuevoNodo->siguiente = proximo;
	return nuevoNodo;
}

//Precondicion: primerElemento es una instancia valida de @Nodo
//Postcondicion: Devuelve una instancia valida de @Lista con el primer elemento cargado
Lista* CrearLista(Nodo* primerElemento){
	Lista* nuevaLista = new Lista;
	nuevaLista ->primero = primerElemento;
	return nuevaLista;
}

//Precondicion: item es una instancia de @AppenderSettings valida, y proximo una instancia de @Nodo valido
//PostCondicion: se devolvera una instancia valida de @Nodo
Nodo* ObtenerUltimoNodo(Lista* lista){
	Nodo* iterador = lista->primero;
	while(iterador->siguiente != NULL){
		iterador = iterador->siguiente;
	}
	return iterador;
}

LoggerSettings* Create(DateTimeFormat dateTimeFormat){
	LoggerSettings* nuevoLoggerSettings = new LoggerSettings;
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

string ULLoggerSettings::ToXml(const LoggerSettings* setting){
	string Xml = "";
	Xml += "<logger dateTimeFormat=" + to_string(setting->DateFormat) +  " />";
	Nodo* iterador = setting->listaAppenderSettings->primero;
	while(iterador != NULL){
		Xml += "\n\t<appender logLevel=\""+ to_string(iterador->item->logLevel) + "\"";
		Xml += " type= \""+ to_string(iterador->item->type) + "\" />";
		iterador = iterador->siguiente;
	}
	Xml += "</logger>";
	return Xml;
}

void ULLoggerSettings::Destroy(LoggerSettings* setting){
	Nodo* iterador = setting->listaAppenderSettings->primero;
	Nodo* auxiliar;
	while(iterador != NULL){
		auxiliar = iterador;
		iterador = iterador->siguiente;
		delete auxiliar;
	}
	delete setting;
}
