/*
 * Email.cpp
 *
 *  Created on: 28 abr. 2019
 *      Author: santiago
 */
#include "Email.h";
using EmailUndav::Email;

Email* EmailUndav::CrearMail(char* asunto){
	return 0;
}

Email* EmailUndav::CrearMail(char* asunto, char* texto){
	return 0;
}

Email* EmailUndav::CrearMail(char* asunto, char* texto, char** destinatarios, int cantidadDestinatarios){
	return 0;
}

void EmailUndav::AgregarDestinatario(Email* email, char* destinatario){
}

void EmailUndav::CambiarAsunto(Email* email, char* asunto){
}

void EmailUndav::CambiarMensaje(Email* email, char* asunto){
}

void EmailUndav::DestruirEmail(Email* email){
}

void EmailUndav::MostrarEmail(const Email* email){
}

