/*
 * apoyoTp1.h
 *
 *  Created on: 8 abr. 2022
 *      Author: thiag
 */

#ifndef APOYOTP1_H_
#define APOYOTP1_H_

void opcionTres(float precioEmpresa, float* uDescuento, float vDescuento, float* uInteres, float vInteres, float* uBitcoin, float vBitcoin, float* uKilometros, float vKilometros);

void opcionCuatroAerolineas(float precio, float mDescuento, float mIntereses, float mBitcoin, float mKilometros);
void opcionCuatroAerolineasVacio(void);
void opcionCuatroLatam(float precio, float mDescuento, float mIntereses, float mBitcoin, float mKilometros);
void opcionCuatroLatamVacio(void);
void opcionCincoArelineas(float precioFijo, float* uDescuentoFijo, float vDescuentoFijo, float* uInteresFijo, float vInteresFijo, float* uBitcoinFijo, float vBitcoinFijo, float* uKilometrosFijo, float vKilometrosFijo);
void opcionCincoLatam(float precioFijo, float* uDescuentoFijo, float vDescuentoFijo, float* uInteresFijo, float vInteresFijo, float* uBitcoinFijo, float vBitcoinFijo, float* uKilometrosFijo, float vKilometrosFijo);


#endif /* APOYOTP1_H_ */
