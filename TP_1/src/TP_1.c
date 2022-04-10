/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calcular.h"
#include "validar-entrada.h"
#include "apoyoTp1.h"

int main(void) {
	setbuf(stdout,NULL);

	int opcionMenu;
	int kilometros;
	int repetir;
	int banderaPrecioAerolineas;
	int banderaPrecioLatam;
	int precioLatamForzado;
	int precioAerolineasForzado;
	int kilometrosForzado;
	int banderaOpcionUno;
	int banderaOpcionDos;
	int banderaOpcionTres;
	int contador;
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
	char direccionDinero;

	kilometros = 0;
	descuento = 10;
	aumento = 25;
	valorBitcoin = 4606954.55;
	contador = 0;

	banderaOpcionUno = 0;
	banderaOpcionDos = 0;
	banderaOpcionTres = 0;
	banderaPrecioAerolineas = 0;
	banderaPrecioLatam = 0;


	precioLatamForzado = 159339;
	precioAerolineasForzado = 162965;
	kilometrosForzado = 7090;


	do{
		if(banderaOpcionUno == 1)
		{
			printf("\n");
		}
		printf("1. Ingresar Cantidad de kilometros: (km = " );
		if(banderaOpcionUno == 0)
		{
			printf("x)");
		}
		else
		{
			printf("%d)", kilometros );
		}

		printf("\n\n2. Ingresar Precio de Vuelos: (Aerolineas=");

		if(banderaPrecioAerolineas == 1)
		{
			printf("%.2f", precioAerolineas);
		}
		else
		{
			printf("y");
		}

		if(banderaPrecioLatam == 1)
		{
			printf(", Latam= %.2f)", precioLatam);
		}
		else
		{
			printf(", Latam= z)");
		}

		printf("\n   - Precio vuelo Aerolineas: ");
		printf(	"\n   - Precio vuelo Latam: ");
		printf("\n\n3. Calcular Costos: ");
		printf("\n   a) Tarjeta de debito (Descuento 10%%)");
		printf("\n   b) Tarjeta de credito (interes 25%%)");
		printf("\n   c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)");
		printf("\n   d) Mostrar precio por km (precio unitario)");
		printf("\n   e) Mostrar diferencia de precio ingresada (Latam - Aerol�neas)");
		printf("\n\n4. Informar resultados");
		printf("\n Latam:");
		printf("\n a) Precio con tarjeta de d�bito: r");
		printf("\n b) Precio con tarjeta de cr�dito: r");
		printf("\n c) Precio pagando con bitcoin : r");
		printf("\n d) Precio unitario: r");
		printf("\n Areolineas:");
		printf("\n a) Precio con tarjeta de d�bito: r");
		printf("\n b) Precio con tarjeta de cr�dito: r");
		printf("\n c) Precio pagando con bitcoin : r");
		printf("\n d) Precio unitario: r");
		printf("\n La diferencia de precio es: r");
		printf("\n\n5. Carga forzada de datos");
		printf("\n6.Salir");
		printf("\n\nEscriba el numero de la opcion que desea realizar: ");
		scanf("%d",&opcionMenu);

		opcionMenu = vIntMeIgual(opcionMenu, 6);

		while(opcionMenu == 4 && banderaOpcionTres == 0)
		{
			printf("\nPara usar la opcion 4 requiere de haber elegido la opcion 3 previamente, sera direccionado a esa.\n");
			opcionMenu = 3;
		}

		while(opcionMenu == 3 && banderaOpcionUno == 0 && banderaOpcionDos == 0)
		{
			printf("\nPara usar la opcion 3 requiere de haber elegido la opcion 1 y/o 2 previamente, elija una de esas: ");
			scanf("%d",&opcionMenu);
		}

		while(opcionMenu == 5 && contador>0)
		{
			printf("\nComo ya hay datos cargados no se puede seleccionar la opcion 5, elija otra opcion: ");
			scanf("%d",&opcionMenu);
		}



		switch(opcionMenu)
		{

			case 1:
				kilometros = eInt();
				kilometros = vIntMaIgual(kilometros, 1);
				banderaOpcionUno = 1;
				contador++;
				break;

			case 2:

				do{
					precioVuelo = eFloat();
					precioVuelo = vFloatMa(precioVuelo, 1);


					printf("Si el precio corresponde a Aerolineas presione \"y\", si pertenece a Latam \"z\": ");
					fflush(stdin);
					scanf("%c", &direccionDinero);

					direccionDinero = vChar(direccionDinero, 'y', 'z');

					if(direccionDinero == 'y')
					{
						precioAerolineas = precioVuelo;
						banderaPrecioAerolineas = 1;
					}
					else
					{
						precioLatam = precioVuelo;
						banderaPrecioLatam = 1;
					}

					repetir = reIngresar();

				}while(repetir == 1);

				contador++;
				banderaOpcionDos = 1;
				break;

			case 3:
				if(precioAerolineas > 0)
				{
					opcionTres(precioAerolineas, &precioDescuentoAerolineas, descuento, &precioAumentoAerolineas, aumento, &precioBitcoinAerolineas, valorBitcoin, &precioUnitarioAerolineas, kilometros);
				}
				if(precioLatam > 0)
				{
					opcionTres(precioLatam, &precioDescuentoLatam, descuento, &precioAumentoLatam, aumento, &precioBitcoinLatam, valorBitcoin, &precioUnitarioLatam, kilometros);
				}

				if(banderaPrecioLatam == banderaPrecioAerolineas)
				{
					diferenciaPrecio = precioAerolineas - precioLatam;
					if(diferenciaPrecio <0)
					{
						diferenciaPrecio*=-1;
					}
				}
				contador++;
				banderaOpcionTres = 1;
				break;

			case 4:
				printf("\nKMs Ingresados: %d", kilometros);
				if(banderaPrecioAerolineas==1)
				{
					opcionCuatroAerolineas(precioAerolineas, precioDescuentoAerolineas, precioAumentoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas);
				}
				else
				{
					opcionCuatroAerolineasVacio();
				}

				if(banderaPrecioLatam == 1)
				{
					opcionCuatroLatam(precioLatam, precioDescuentoLatam, precioAumentoLatam, precioBitcoinLatam, precioUnitarioLatam);
				}
				else
				{
					opcionCuatroLatamVacio();
				}

				printf("\n\nLa diferencia de precio es: ");
				if(banderaPrecioLatam == banderaPrecioAerolineas)
				{
					printf(" %.2f \n", diferenciaPrecio);
				}
				else
				{
					printf("No se puede calcular");
				}


				banderaOpcionUno = 0;
				banderaOpcionDos = 0;
				banderaOpcionTres = 0;
				banderaPrecioLatam = 0;
				banderaPrecioAerolineas = 0;
				break;

			case 5:
				printf("\nKMs ingresados: %d km", kilometrosForzado);
				opcionTres(precioAerolineasForzado, &precioDescuentoAerolineas, descuento, &precioAumentoAerolineas, aumento, &precioBitcoinAerolineas, valorBitcoin, &precioUnitarioAerolineas, kilometrosForzado);
				opcionCuatroAerolineas(precioAerolineasForzado, precioDescuentoAerolineas, precioAumentoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas);

				opcionTres(precioLatamForzado, &precioDescuentoLatam, descuento, &precioAumentoLatam, aumento, &precioBitcoinLatam, valorBitcoin, &precioUnitarioLatam, kilometrosForzado);
				opcionCuatroLatam(precioLatamForzado, precioDescuentoLatam, precioAumentoLatam, precioBitcoinLatam, precioUnitarioLatam);

				diferenciaPrecio = restaD(precioAerolineasForzado, precioLatamForzado);

				printf("\n\nLa diferencia de precio es: %.2f ", diferenciaPrecio);
				break;

			default:
				break;
		}
	}while(opcionMenu<6);

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

	return EXIT_SUCCESS;
}

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

