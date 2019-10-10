//////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////////////////////////////////
#include "ABM.h"
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////

int mostrarMenu(char arraysDeclaradosEInicializados,int* contadorId)
{

    if(arraysDeclaradosEInicializados=='n') //Validamos que ya no hayan sido declarados e inicializados
    {
        eOrquesta aOrquestas[QTY_ORQUESTAS];    // Creamos nuestro array de entidades cuyo tamaño es QTY_ENTIDADES
        inicializar(aOrquestas,QTY_ORQUESTAS); // Colocamos todos los isEmpty de nuestras entidades en 1

        arraysDeclaradosEInicializados=='s';
    }


    int accion=0;
    utn_getUnsignedInt("  1) Alta de orquesta\n  2) Modificar orquesta\n  3) Baja de orquesta\n  4) Informes de orquestas\n  5) Alta de musico\n  6) Modificar musico\n  7) Baja de musico\n  8) Informes de musicos\n 9) Alta de instrumento\n  10) Modificar instrumento\n  11) Informes de instrumentos\n  12) Salir\n Ingrese el numero de la accion que desea realizar: ","",1,TEXT_SIZE,1,QTY_OPCIONES,0,&accion);
    do
    {
        switch(accion)
        {
            case 1: //  Alta
                printf("\n");

                if((alta(aOrquestas,QTY_ORQUESTAS,&contadorId))==0)
                {
                    msj(1);
                    continue;
                }
                else
                {
                    msj(-999);
                }
                break;


            case 2: // Modificar
                if((buscarEmpty(aOrquestas,QTY_ORQUESTAS,&contadorId,0))==0) /** Validamos que haya un ENTIDAD dado de alta en nuestro array */
                {
                    printf("\n");

                    if((modificar(aOrquestas,QTY_ORQUESTAS))==0)
                    {
                        msj(1);
                        continue;
                    }
                    else
                    {
                        msj(-999);
                    }
                }
                else
                {
                    msj(-1);
                }
                break;


            case 3: // Baja
                if((buscarEmpty(aOrquestas,QTY_ORQUESTAS,&contadorId,0))==0)  /** Validamos que haya un ENTIDAD dado de alta en nuestro array */
                {
                    printf("\n");

                    if((baja(aOrquestas,QTY_ORQUESTAS))==0)
                    {
                        msj(1);
                        continue;
                    }
                    else
                    {
                        msj(-999);
                    }
                }
                else
                {
                    msj(-1);
                }
                break;


            case 4: // Informes
                if((buscarEmpty(aOrquestas,QTY_ORQUESTAS,&contadorId,0))==0)  /** Validamos que haya un ENTIDAD dado de alta en nuestro array */
                {
                    printf("\n");

                    //if((compararVariablesConPromedio(aOrquestas,QTY_ORQUESTAS))==0)  //Funciona aunque no le pasemos el último parametro porque es opcional
                    if((listar(aOrquestas,QTY_ORQUESTAS))==0)
                    {
                        msj(1);
                        continue;
                    }
                    else
                    {
                        msj(-999);
                    }

                }
                else
                {
                    msj(-1);
                }
                break;


            case 12: //Salir
                msj(0);
                break;
            default:

                break;
        }

    }
    while(accion<1||accion>QTY_OPCIONES);
    mostrarMenu('s',contadorId);
    return 0;
}
