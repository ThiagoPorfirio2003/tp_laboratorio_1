#include "LinkedList.h"
#include "Passenger.h"

int controller_verificarSerCodigoDeVuelo(char* cadenaAlfanumerica);

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

int controller_loadOnePassengerData(int* id,char* nombre, char* apellido, float* precio, int* tipoPasajero, char* codigoVuelo, int* statusFlight);
int controller_addPassenger(LinkedList* pArrayListPassenger, int *contadorId);

int controller_findPassengerById(int idAEncontrar, int cantidadPasajeros, LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger);

int controller_removePassenger(LinkedList* pArrayListPassenger);

//int controller_MostrarUnPasajero(LinkedList* pArrayListPassenger, int indiceUbicacionPasajero);
int controller_MostrarUnPasajero(Passenger* pPasajeroAMostrar);
int controller_ListPassenger(LinkedList* pArrayListPassenger, char* mensajeDeError);

int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);


