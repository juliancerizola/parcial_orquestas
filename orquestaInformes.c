//////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////////////////////////////////
#include "orquestaInformes.h"
//#include "entidadABM.h"
//#include "utn.h"
//////////////////////////////////////////////////////////////

int msj(int idMensaje)
{
    switch(idMensaje) /** Negativos para errores. 0 Adios*/
    {
        case 1:
            printf(" Hecho!\n\n");
            break;
        case 0:
            printf("\n\n\t   Adios!\n\n");
            break;
        case -1: // Sin entes dados de alta
            printf("\n ERROR - No hay ningun %s dado de alta (opcion 1)\n\n",ENTIDAD);
            break;
        case -2: // Acción no valida
            printf("\n ERROR - Accion no valida (entre 1 y %s)\n\n",QTY_OPCIONES);
            break;
        case -5: // No existe id
            printf("\n No existe este ID\n");
            break;
        case -999: // Error desconocido o generico
            printf("\n ERROR - Algo salio mal!\n\n");
            break;
        default:   // Si se ingresa un idMensaje inexistente se da un salto de linea
            printf("\n");
    }
    return 0;
}

int listar(eOrquesta array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>=0)
    {
        char strTipo[TEXT_SIZE];
        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
            {
                switch(array[i].tipo)
                {
                    case 1:
                        strncpy(strTipo,"Sinfonica",TEXT_SIZE);
                        break;
                    case 2:
                        strncpy(strTipo,"Filarmonica",TEXT_SIZE);
                        break;
                    case 3:
                        strncpy(strTipo,"Camara",TEXT_SIZE);
                        break;
                    default:

                        break;
                }
                //printf("  ID: %d\n  String1: %s\n  String2: %s\n  Int1: %d\n  Int2: %d\n  Float1: %f\n  Float2: %f\n",array[i].id, array[i].string1, array[i].string2, array[i].int1, array[i].int2, array[i].float1, array[i].float2);
                printf("  ID: %d\n  Nombre: %s\n  Lugar: %s\n  Tipo: %s", array[i].id, array[i].nombre, array[i].lugar, strTipo);
            }
        }
        retorno=0;
    }
    return retorno;
}

int listarEncolumnado(eOrquesta array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>=0)
    {
        int columnaMostrada=0;

        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
            {
                if(columnaMostrada==0)
                {
                    //printf("  ID\t\tNombre\t\tLugar\t\tTipo\t\tInt2\t\tFloat1\t\tFloat2\n");
                    printf("  ID\t\tNombre\t\tLugar\t\tTipo\n");
                    columnaMostrada=1;
                }
                //printf("  %d\t\t%s\t\t%s\t\t%d\t\t%d\t\t%f\t\t%f\n",array[i].id, array[i].string1, array[i].string2, array[i].int1, array[i].int2, array[i].float1, array[i].float2);
                printf("  %d\t\t%s\t\t%s\t\t%d\n",array[i].id, array[i].nombre, array[i].lugar, array[i].tipo);
            }
        };
        retorno=0;
    }
    return retorno;
}

int ordenarPorVariable(eOrquesta array[], int tamanio) //Pueden ser mas de una variable
{
    int retorno=-1;

    if(array!=NULL && tamanio>=0)
    {
        int bufferId;
        char bufferString1[TEXT_SIZE];
        char bufferString2[TEXT_SIZE];
        //float bufferFloat1;
        //float bufferFloat2;
        int bufferInt1;
        //int bufferInt2;
        int bufferIsEmpty;

        int j;

        int i;
        for(i=1;i<tamanio;i++)
        {
            bufferId=array[i].id;
            strncpy(bufferString1,array[i].nombre,TEXT_SIZE);
            strncpy(bufferString2,array[i].lugar,TEXT_SIZE);
            //bufferFloat1=array[i].float1;
            //bufferFloat2=array[i].float2;
            bufferInt1=array[i].tipo;
            //bufferInt2=array[i].int2;
            bufferIsEmpty=array[i].isEmpty;

            j=i-1;

            while ((j >= 0) && strcmp(bufferString1,array[j].nombre)<0 && bufferInt1<array[j].tipo)   //Si tiene mas de un criterio se lo agrego, Ej.  && bufferInt1<array[j].int1
            {                                                                      //buffer < campo ascendente   buffer > campo descendente
                array[j + 1].id=array[j].id;
                strncpy(array[j + 1].nombre,array[j].nombre,TEXT_SIZE);
                strncpy(array[j + 1].lugar,array[j].lugar,TEXT_SIZE);
                //array[j + 1].float1=array[j].float1;
                //array[j + 1].float2=array[j].float2;
                array[j + 1].tipo=array[j].tipo;
                //array[j + 1].int2=array[j].int2;
                array[j + 1].isEmpty=array[j].isEmpty;

                j--;
            }
            array[j + 1].id=bufferId;
            strncpy(array[j + 1].nombre,bufferString1,TEXT_SIZE);
            strncpy(array[j + 1].lugar,bufferString2,TEXT_SIZE);
            //array[j + 1].float1=bufferFloat1;
            //array[j + 1].float1=bufferFloat1;
            array[j + 1].tipo=bufferInt1;
            //array[j + 1].tipo=bufferInt1;
            //array[j + 1].isEmpty=bufferIsEmpty;
        }
        retorno=0;
    }
    return retorno;
}

int promediarVariable(eOrquesta array[], int tamanio, float* pPromedio)
{
    /** Reemplazar Int1 por nuestra variable a promediar (si es float hay que cambiar también los %d por %f en los printf */

    int retorno=-1;

    if(array!=NULL && tamanio>=0)
    {
        int suma=0;
        int cantidad=0;
        float promedio=0;

        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
            {
                cantidad++;
                suma+=array[i].tipo;

            }
        }

        promedio=suma/cantidad;
        *pPromedio=promedio;

        printf("  El total de Int1 es: %d\n  La cantidad de Int1 es: %d\n  El promedio de Int1 es: %f\n",suma,cantidad,promedio);

        retorno=0;
    }
    return retorno;
}

int compararVariablesConPromedio(eOrquesta array[], int tamanio)
{
        /** Reemplazar Int1 por nuestra variable a promediar (si es float hay que cambiar también los %d por %f en los printf */

    int retorno=-1;

    if(array!=NULL && tamanio>=0)
    {
        float promedio=0;
        int menor=0;
        int igual=0;
        int mayor=0;

        if((promediarVariable(array,tamanio,&promedio))==0)
        {
            int i;
            for(i=0;i<tamanio;i++)
            {
                if(array[i].isEmpty==1)
                {
                    continue;
                }
                else
                {
                    if(array[i].tipo>promedio)
                    {
                        menor++;
                    }
                    else if(array[i].tipo==promedio)
                    {
                        igual++;
                    }
                    else if(array[i].tipo<promedio)
                    {
                        mayor++;
                    }
                }
            }
            printf("  La cantidad de Int1 menor al promedio es: %d\n  La cantidad de Int1 igual al promedio es: %d\n  La cantidad de Int1 mayor al promedio es: %d\n",menor,igual,mayor);
            retorno=0;
        }
    }
    return retorno;
}

/** FUNCION GENÉRICA

            Estaba harto de escribir siempre lo mismo en las funciones asi que
        esta funcion comentada la utilizo para realizar copy-paste y crear funciones nuevas
        ya con la validacion, el for y el retorno hechos.


int funcionGenerica(eEntidad array[], int tamanio)
{
    int retorno=-1;

    if(array!=NULL && tamanio>=0)
    {
        int i;
        for(i=0;i<tamanio;i++)
        {
            if(array[i].isEmpty==1)
            {
                continue;
            }
            else
            {


            }
        }
        retorno=0;
    }
    return retorno;
}

*/

