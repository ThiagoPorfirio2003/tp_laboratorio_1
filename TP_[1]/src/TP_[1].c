/*

 */
#include <stdio.h>
#include <stdlib.h>
#include "calcular.h"
#include "validar.h"
#include "entrada.h"
#include "apoyoTP_[1].h"

int main(void) {
	setbuf(stdout,NULL);

	int opcionMenu;
	int kilometros;
	int precioLatamForzado;
	int precioAerolineasForzado;
	int kilometrosForzado;
	int banderaOpcionUno;
	int banderaOpcionDos;
	int banderaOpcionTres;
	int contador;
	int i;
	float precioAerolineas;
	float precioLatam;
	float precioVuelo;
	float descuento;
	float aumento;
	float valorBitcoin;
	float precioDescuentoAerolineas;
	float precioAumentoAerolineas;
	float precioBitcoinAerolineas;
	float precioUnitarioAerolineas;
	float precioDescuentoLatam;
	float precioAumentoLatam;
	float precioBitcoinLatam;
	float precioUnitarioLatam;
	float diferenciaPrecio;

	kilometros = 0;
	descuento = 10;
	aumento = 25;
	valorBitcoin = 4606954.55;

	banderaOpcionUno = 0;
	banderaOpcionDos = 0;
	banderaOpcionTres = 0;
	contador = 0;

	precioLatamForzado = 159339;
	precioAerolineasForzado = 162965;
	kilometrosForzado = 7090;


	do{
		menu(contador, banderaOpcionUno, banderaOpcionDos, kilometros, precioAerolineas, precioLatam);

		opcionMenu = eInt();
		opcionMenu = vIntMeIgual(opcionMenu, 6);

		switch(opcionMenu)
		{
			case 1:
				printf("\nKilometros");
				kilometros = eInt();
				kilometros = vIntMaIgual(kilometros, 1);
				banderaOpcionUno = 1;
				contador++;
				break;

			case 2:
				for(i=0;i<2;i++)
				{
					printf("\nPrecio vuelo ");
					if(i==0)
					{
						printf("Aerolineas");
					}
					else
					{
						printf("Latam");
					}

					precioVuelo = eFloat();
					precioVuelo = vFloatMaIgual(precioVuelo, 1);

					if(i==0)
					{
						precioAerolineas = precioVuelo;

					}
					else
					{
						precioLatam = precioVuelo;
					}
				}

				contador++;
				banderaOpcionDos = 1;
				break;

			case 3:
				if(banderaOpcionUno == 1 && banderaOpcionDos ==1)
				{
					if(precioAerolineas > 0)
					{
						opcionTres(precioAerolineas, &precioDescuentoAerolineas, descuento, &precioAumentoAerolineas, aumento, &precioBitcoinAerolineas, valorBitcoin, &precioUnitarioAerolineas, kilometros);
					}
					if(precioLatam > 0)
					{
						opcionTres(precioLatam, &precioDescuentoLatam, descuento, &precioAumentoLatam, aumento, &precioBitcoinLatam, valorBitcoin, &precioUnitarioLatam, kilometros);
					}

					diferenciaPrecio = precioAerolineas - precioLatam;
					if(diferenciaPrecio <0)
					{
						diferenciaPrecio*=-1;
					}
					banderaOpcionTres = 1;
				}
				else
				{
					printf("\nPara usar la opcion 3 requiere de haber elegido la opcion 1 y/o 2 previamente, elija una de esas: \n\n");
				}

				break;

			case 4:
				if(banderaOpcionTres ==1)
				{
					printf("\nKMs Ingresados: %d", kilometros);

						opcionCuatroAerolineas(precioAerolineas, precioDescuentoAerolineas, precioAumentoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas);
						opcionCuatroLatam(precioLatam, precioDescuentoLatam, precioAumentoLatam, precioBitcoinLatam, precioUnitarioLatam);

					printf("\n\nLa diferencia de precio es: %.2f \n\n", diferenciaPrecio);

					banderaOpcionUno = 0;
					banderaOpcionDos = 0;
					banderaOpcionTres = 0;
					contador = 0;
				}
				else
				{
					printf("\nPara usar la opcion 4 requiere de haber elegido la opcion 3 previamente, elija otra opcion: \n");
				}

				break;

			case 5:
				if(contador == 0)
				{
					printf("\nKMs ingresados: %d km", kilometrosForzado);
					opcionTres(precioAerolineasForzado, &precioDescuentoAerolineas, descuento, &precioAumentoAerolineas, aumento, &precioBitcoinAerolineas, valorBitcoin, &precioUnitarioAerolineas, kilometrosForzado);
					opcionCuatroAerolineas(precioAerolineasForzado, precioDescuentoAerolineas, precioAumentoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas);

					opcionTres(precioLatamForzado, &precioDescuentoLatam, descuento, &precioAumentoLatam, aumento, &precioBitcoinLatam, valorBitcoin, &precioUnitarioLatam, kilometrosForzado);
					opcionCuatroLatam(precioLatamForzado, precioDescuentoLatam, precioAumentoLatam, precioBitcoinLatam, precioUnitarioLatam);

					diferenciaPrecio = restaD(precioAerolineasForzado, precioLatamForzado);

					contador++;

					printf("\n\nLa diferencia de precio es: %.2f \n", diferenciaPrecio);
				}

				else
				{
					printf("\nComo ya hay datos cargados no se puede seleccionar la opcion 5, elija otra opcion: \n\n");
				}
				break;

			default:
				break;
		}

	}while(opcionMenu<6);

	printf("\n\nGracias por usar nuestro servicio");

	return EXIT_SUCCESS;
}

//		if(contador > 0)
//		{
//			printf("\n");
//		}
//		printf("1. Ingresar Cantidad de kilometros: (km = " );
//		if(banderaOpcionUno == 0)
//		{
//			printf("x)");
//		}
//		else
//		{
//			printf("%d)", kilometros );
//		}
//
//		printf("\n\n2. Ingresar Precio de Vuelos: (Aerolineas=");
//
//		if(banderaOpcionDos == 1)
//		{
//			printf("%.2f, Latam= %.2f)", precioAerolineas, precioLatam);
//		}
//		else
//		{
//			printf("y, Latam= z)");
//		}
//
//		printf("\n   - Precio vuelo Aerolineas: ");
//		printf(	"\n   - Precio vuelo Latam: ");
//		printf("\n\n3. Calcular Costos: ");
//		printf("\n   a) Tarjeta de debito (Descuento 10%%)");
//		printf("\n   b) Tarjeta de credito (interes 25%%)");
//		printf("\n   c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)");
//		printf("\n   d) Mostrar precio por km (precio unitario)");
//		printf("\n   e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)");
//		printf("\n\n4. Informar resultados");
//		printf("\n Latam:");
//		printf("\n a) Precio con tarjeta de débito: r");
//		printf("\n b) Precio con tarjeta de crédito: r");
//		printf("\n c) Precio pagando con bitcoin : r");
//		printf("\n d) Precio unitario: r");
//		printf("\n Areolineas:");
//		printf("\n a) Precio con tarjeta de débito: r");
//		printf("\n b) Precio con tarjeta de crédito: r");
//		printf("\n c) Precio pagando con bitcoin : r");
//		printf("\n d) Precio unitario: r");
//		printf("\n La diferencia de precio es: r");
//		printf("\n\n5. Carga forzada de datos");
//		printf("\n6.Salir");
//		printf("\n\n¿Que opcion desea realizar? ");
	/*
	int opcion;
	int kilometros;
	int precioAerolineas;
	int precioLatam;
	float descuento;
	float aumento;
	float precioDescuentoAerolineas;
	float precioAumentoAerolineas;
	float precioBitcoinAerolineas;
	float valorBitcoin;
	float precioUnitarioAerolineas;
	float precioDescuentoLatam;
	float precioAumentoLatam;
	float precioBitcoinLatam;
	float precioUnitarioLatam;
	float diferenciaPrecios;
	int contador;

	contador =0;
	descuento = 10;
	aumento = 25;
	kilometros = 7090;
	precioAerolineas = 162965;
	precioLatam = 159339;
	valorBitcoin = 4606954.55;

	do{
		printf("\n1.Ingresar Cantidad de kilometros"
		"\n2.Ingresar Precio de Vuelos"
		"\n3.Calcular Costos"
		"\n4.Informar resultados"
		"\n5.Carga forzada de datos (Datos precargados)"
		"\n6.Salir"
		"\nEscriba el numero de la opcion que desea realizar: ");
		scanf("%d",&opcion);

		switch(opcion)
		{
			case 1:
				printf("\nIngrese la cantidad de KiloMetros de viaje: ");
				scanf("%d",&kilometros);
				break;

			case 2:
				printf("\nIngrese el precio X vuelo de Aerolineas: ");
			scanf("%d",&precioAerolineas);

			printf("Ingrese el precio X vuelo de Latam: ");
				scanf("%d",&precioLatam);
			break;

		case 3:
			case 5:
				if(precioAerolineas > 0)
				{
					precioDescuentoAerolineas = decremento(precioAerolineas, descuento);
					precioAumentoAerolineas = incremento(precioAerolineas, aumento);
					precioBitcoinAerolineas = division(precioAerolineas, valorBitcoin);
					precioUnitarioAerolineas = division(precioAerolineas, kilometros);
				}
				if(precioLatam > 0)
				{
					precioDescuentoLatam = decremento(precioLatam, descuento);
					precioAumentoLatam = incremento(precioLatam, aumento);
					precioBitcoinLatam = division(precioLatam, valorBitcoin);
					precioUnitarioLatam = division(precioLatam, kilometros);
				}

				break;

			case 4:
				if(kilometros == 0)
				{
					printf("KMs Ingresados: No se puede calcular"
							"\n\nPrecioAerolineas: No se puede calcular"
							"a) Precio con tarjeta de debito: No se puede calcular"
							"\nb) Precio con tarjeta de credito: No se puede calcular"
							"\nc) Precio pagando con bitcoin: No se puede calcular"
							"\nd) Mostrar precio unitario: No se puede calcular"
							"\n\nPrecio Latam: No se puede calcular"
							"a) Precio con tarjeta de debito: No se puede calcular"
							"\nb) Precio con tarjeta de credito: No se puede calcular"
							"\nc) Precio pagando con bitcoin: No se puede calcular"
							"\nd) Mostrar precio unitario: No se puede calcular"
							"\n\nLa diferencia de precio es:  No se puede calcular");
				}
				else
				{
					printf("KMs ingresados: %d",kilometros);
					if(precioAerolineas > 0)
					{
						printf("\n\nPrecio Aerolineas: %d"
								"\na) Precio con tarjeta de debito: %.2f"
								"\nb) Precio con tarjeta de credito: %.2f"
								"\nc) Precio pagando con bitcoin: %.2f"
								"\nd) Mostrar precio unitario: %.2f",precioAerolineas, precioDescuentoAerolineas,precioAumentoAerolineas,precioBitcoinAerolineas,precioUnitarioAerolineas);
						contador++;
					}
					else
					{
						printf("\n\nPrecio Aerolineas: No se puede calcular"
							"\na) Precio con tarjeta de debito: No se puede calcular"
							"\nb) Precio con tarjeta de credito: No se puede calcular"
							"\nc) Precio pagando con bitcoin: No se puede calcular"
							"\nd) Mostrar precio unitario: No se puede calcular");
					}
					if(precioLatam >0)
					{
						printf("\n\nPrecio Latam: %d"
								"\na) Precio con tarjeta de debito: %.2f"
								"\nb) Precio con tarjeta de credito: %.2f"
								"\nc) Precio pagando con bitcoin: %.2f"
								"\nd) Mostrar precio unitario: %.2f", precioLatam, precioDescuentoLatam, precioAumentoLatam, precioBitcoinLatam, precioUnitarioLatam);
						contador++;
					}
					else
					{
						printf("\n\nPrecio Latam: No se puede calcular"
								"\na) Precio con tarjeta de debito: No se puede calcular"
								"\nb) Precio con tarjeta de credito: No se puede calcular"
								"\nc) Precio pagando con bitcoin: No se puede calcular"
								"\nd) Mostrar precio unitario: No se puede calcular");
					}
					if(contador == 2)
					{
						diferenciaPrecios = precioAerolineas - precioLatam;
						if(diferenciaPrecios < 0)
						{
							diferenciaPrecios *=(-1);
						}
						printf("\n\nLa diferencia de precio es: %.2f", diferenciaPrecios);
					}
					else
					{
						printf("\n\nLa diferencia de precio es: No se puede calcular");
					}
				}

				break;

			default:
				break;

		}

	}while(opcion<5); */



/*
 *				printf("\n\nPrecioLatams: %d"
						"a) Precio con tarjeta de debito: %f"
						"\nb) Precio con tarjeta de credito: %f"
						"\nc) Precio pagando con bitcoin: %f"
						"\nd) Mostrar precio unitario: %f"
						"\n\nPrecio Latam: %d"
						"a) Precio con tarjeta de debito: %f"
						"\nb) Precio con tarjeta de credito: %f"
						"\nc) Precio pagando con bitcoin: %f"
						"\nd) Mostrar precio unitario: %f"
						"\n\nLa diferencia de precio es:  ")
 *
 */

