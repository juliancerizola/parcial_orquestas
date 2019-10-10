//////////////////////////////////////////////////////////////
#include "orquestaABM.h"
//////////////////////////////////////////////////////////////
#define QTY_OPCIONES    9                   /** Reemplazamos 5 por la cantidad de opciones de nuestro ABM */
//////////////////////////////////////////////////////////////

int msj(int idMensaje);
int listar(eOrquesta array[], int tamanio);
int listarEncolumnado(eOrquesta array[], int tamanio);
int promediarVariable(eOrquesta array[], int tamanio, float* pPromedio);
int compararVariablesConPromedio(eOrquesta array[], int tamanio);

