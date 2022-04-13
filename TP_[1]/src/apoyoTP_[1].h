/*
 * apoyoTP_[1].h
 *
 *  Created on: 12 abr. 2022
 *      Author: thiag
 */

#ifndef APOYOTP__1__H_
#define APOYOTP__1__H_

void menu(int contador, int banderaOpcionUno, int banderaOpcionDos, int kilometros, float precioAerolineas, float precioLatam);

/// @brief
///
/// @pre
/// @post
/// @param precioEmpresa
/// @param uDescuento
/// @param vDescuento
/// @param uInteres
/// @param vInteres
/// @param uBitcoin
/// @param vBitcoin
/// @param uKilometros
/// @param vKilometros
void opcionTres(float precioEmpresa, float* uDescuento, float vDescuento, float* uInteres, float vInteres, float* uBitcoin, float vBitcoin, float* uKilometros, float vKilometros);

/// @brief
///
/// @pre
/// @post
/// @param precio
/// @param mDescuento
/// @param mIntereses
/// @param mBitcoin
/// @param mKilometros
void opcionCuatroAerolineas(float precio, float mDescuento, float mIntereses, float mBitcoin, float mKilometros);

/// @brief
///
/// @pre
/// @post
void opcionCuatroAerolineasVacio(void);

/// @brief
///
/// @pre
/// @post
/// @param precio
/// @param mDescuento
/// @param mIntereses
/// @param mBitcoin
/// @param mKilometros
void opcionCuatroLatam(float precio, float mDescuento, float mIntereses, float mBitcoin, float mKilometros);

/// @brief
///
/// @pre
/// @post
void opcionCuatroLatamVacio(void);



#endif /* APOYOTP__1__H_ */
