/*
	Alumno: Thiago Lisandro Porfirio
	Div: D
	Fecha de entrega: 16/04/2022 23:59
 	DNI: 44020889
 */

#ifndef VALIDAR_H_
#define VALIDAR_H_
/// @fn char vChar(char, char, char)
/// @brief
///
/// @pre
/// @post
/// @param letra
/// @param opcionUno
/// @param opcionDos
/// @return
char vChar(char letra ,char opcionUno, char opcionDos);

/// @brief
///
/// @pre
/// @post
/// @param numero
/// @param limite
/// @return
float vFloatMaIgual(float numero, float limite);
//Valida que un float sea igual o mayor al limite que le ingresemos, en caso de no cumplir ninguna de las condiciones se debera pedir un valor que si lo haga

/// @fn int vIntMaIgual(int, int)
/// @brief
///
/// @pre
/// @post
/// @param numero
/// @param limite
/// @return
int vIntMaIgual(int numero, int limite);
//Valida que un Int sea igual o mayor al limite que le ingresemos, en caso de no cumplir ninguna de las condiciones se debera pedir un valor que si lo haga

/// @fn int vIntMeIgual(int, int)
/// @brief
///
/// @pre
/// @post
/// @param numero
/// @param limite
/// @return
int vIntMeIgual(int numero, int limite);
//Valida que un Int sea igual o menor al limite que le ingresemos, en caso de no cumplir ninguna de las condiciones se debera pedir un valor que si lo haga

/// @brief
///
/// @pre
/// @post
/// @param numero
/// @param minimo
/// @param maximo
/// @return
int vIntRango(int numero, int minimo, int maximo);
//Valida que un Int este dentro de un rango


/// @fn int reIngresar(void)
/// @brief
///
/// @pre
/// @post
/// @return
int reIngresar(void);

#endif /* VALIDAR_H_ */
