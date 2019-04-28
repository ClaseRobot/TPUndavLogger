/*
 * Email.h
 *
 *  Created on: 28 abr. 2019
 *      Author: santiago
 */

#ifndef EMAIL_H_
#define EMAIL_H_

namespace EmailUndav {
	struct Email{
		char* asunto;
		char* mensaje;
		char** emailDestinatarios;
		int cantidadDestinatarios;
	};

	// Precondiciones: @asunto es una cadena de caracteres
	// Postcondiciones: Devuelve una instancia valida de Email
	Email* CrearMail(char* asunto);

	// Precondiciones: @asunto y @texto es una cadena de caracteres
	// Postcondiciones: Devuelve una instancia valida de Email
	Email* CrearMail(char* asunto, char* texto);

	// Precondiciones: @asunto, @texto es una cadena de caracteres. @destinatarios tiene una cantidad de filas igual a @cantidadDestinatarios
	// Postcondiciones: Devuelve una instancia valida de Email
	Email* CrearMail(char* asunto, char* texto, char** destinatarios, int cantidadDestinatarios);

	// Precondicion: @email es una instancia valida. @destinatario es una cadena de caracteres
	// Postcondicion: Agrega @destinatario a @email.
	void AgregarDestinatario(Email* email, char* destinatario);

	// Precondicion: @email es una instancia valida. @asunto es una cadena de caracteres
	// Postcondicion: Reemplaza el asunto de @email por @asunto
	void CambiarAsunto(Email* email, char* asunto);

	// Precondicion: @email es una instancia valida. @mensaje es una cadena de caracteres
	// Postcondicion: Reemplaza el mensaje de @email por @mensaje
	void CambiarMensaje(Email* email, char* mensaje);

	// Precondicion: @email es una instancia valida.
	// Postcondicion: Muestra todos los datos del email por salida estandard
	void MostrarEmail(const Email* email);

	// Precondicion: @email es una instancia valida. @asunto es una cadena de caracteres
	// Postcondicion: Libera todos los recursos asociados a @email
	void DestruirEmail(Email* email);

}

#endif /* EMAIL_H_ */
