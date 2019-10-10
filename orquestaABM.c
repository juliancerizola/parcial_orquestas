//////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////////////////////////////////
#include "orquestaABM.h"
//#include "entidadInformes.h"
//////////////////////////////////////////////////////////////

int inicializar(eOrquesta array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>0)
    {
        for(;tamanio>0;tamanio--)
        {
            array[tamanio-1].isEmpty=1;
        }
        retorno=0;
    }

    return retorno;
}

int buscarEmpty(eOrquesta array[], int tamanio, int* posicion, int isEmptyBuscado) /** Si isEmptyBuscado==1 busca isEmpty==1, si isEmptyBuscado==0 busca isEmpty==0 */
{
    int retorno=-1;

    if(array!=NULL && tamanio>=0 && posicion!=NULL)
    {
        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==isEmptyBuscado)
            {
                *posicion=i;
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}

int buscarPorId(eOrquesta array[], int tamanio, int id, int* posicion)
{
    int retorno=-1;

    if(array!= NULL && tamanio>=0)
    {
        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            } else if(array[i].id==id) {
                *posicion=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int alta(eOrquesta array[], int tamanio, int* idRecibido)
{
    int retorno=-1;

    if(array!=NULL && tamanio>0)
    {
        if(buscarEmpty(array,tamanio,idRecibido,1)==-1)
        {
            printf("No hay lugares vacios\n");
        }
        else
        {
            array[*idRecibido].isEmpty=0;

            /** Ingresamos las funciones correspondientes a nuestro caso en particular */

            utn_getName(" Ingrese nombre: "," ERROR\n",1,TEXT_SIZE,1,array[*idRecibido].nombre);
            utn_getTexto(" Ingrese lugar: "," ERROR\n",1,TEXT_SIZE,1,array[*idRecibido].lugar);
            //utn_getFloat(" Ingrese float1: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[*idRecibido].float1);
            //utn_getFloat(" Ingrese float2: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[*idRecibido].float2);
            utn_getUnsignedInt(" Ingrese tipo: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[*idRecibido].tipo);
            //utn_getUnsignedInt(" Ingrese int2: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[*idRecibido].int2);

            array[*idRecibido].id=*idRecibido+1;
            retorno=0;
        }
    }
    return retorno;
}

int modificar(eOrquesta array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>0)
    {

        int posicion;
        int id;
        int accion;

        utn_getUnsignedInt(" ID del ENTIDAD a modificar: "," ERROR\n",1,sizeof(int),1,tamanio,1,&id); // Modificar 'ENTIDAD'
        if(buscarPorId(array,tamanio,id,&posicion)==-0)
        {
            /** Creamos un menu correspondiente a nuestro caso en particular */


            do
            {

                //printf(" 1) STRING1: %s\n 2) STRING2: %s\n 3) FLOAT1: %f\n 4) FLOAT2: %f\n 5) INT1: %d\n 6) INT2: %d\n",
                //array[posicion].string1,array[posicion].string2,array[posicion].float1,array[posicion].float2,array[posicion].int1,array[posicion].int2);
                printf("  1) Nombre: %s\n  2) Lugar:: %s\n  3) Tipo: %d\n", array[posicion].nombre, array[posicion].lugar, array[posicion].tipo);

                utn_getUnsignedInt("  Ingrese el numero de la variable que desea modificar: "," ERROR\n",1,2,1,9,2,&accion);
                switch(accion)
                {
                    case 1:
                        utn_getName(" Ingrese nombre nuevo: "," ERROR\n",1,TEXT_SIZE,1,array[posicion].nombre);
                        break;
                    case 2:
                        utn_getTexto(" Ingrese lugar nuevo: "," ERROR\n",1,TEXT_SIZE,1,array[posicion].lugar);
                        break;
                    case 3:
                    utn_getUnsignedInt("\n Ingrese tipo nuevo: "," ERROR\n",1,TEXT_SIZE,1,1000,2,&array[posicion].tipo);
                        break;/*
                    case 4:
                        utn_getFloat(" Ingrese float2: "," ERROR\n",1,TEXT_SIZE,0,1,1,&array[posicion].float2);
                        break;
                    case 5:
                        utn_getUnsignedInt("\n Ingrese int1 nuevo: "," ERROR\n",1,TEXT_SIZE,1,1000,2,&array[posicion].int1);
                        break;
                    case 6:
                        utn_getUnsignedInt("\n Ingrese int2 nuevo: "," ERROR\n",1,TEXT_SIZE,1,1000,2,&array[posicion].int2);
                        break;*/
                    case 9:
                        break;
                    default:
                        printf("\n ERROR - Accion no valida (entre 1 y 3 o 9 para salir)\n\n");
                }
            }
            while(accion!=1&&accion!=2&&accion!=3&&accion!=9);

            retorno=0;
        }
        else
        {
            msj(-5);
        }
    }
    return retorno;
}

int baja(eOrquesta array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>0)
    {
        int posicion;
        int id;

        utn_getUnsignedInt(" ID a dar de baja: "," ERROR\n",1,sizeof(int),1,tamanio,1,&id);

        if(buscarPorId(array,tamanio,id,&posicion)==-1)
        {
            printf(" No existe este ID\n");
        }
        else
        {
            /** Realizamos una baja logica en cada una de nuestras respectivas variables */

            strncpy(array[posicion].nombre,"",TEXT_SIZE);
            strncpy(array[posicion].lugar,"",TEXT_SIZE);
            array[posicion].tipo=0;
            /*array[posicion].int2=0;
            array[posicion].float1=0;
            array[posicion].float2=0;*/

            array[posicion].id=0;
            array[posicion].isEmpty=1;

            retorno=0;
        }
    }
    return retorno;
}


