/**

                Las bibliotecas genéricas que usé en este parcial o TP se encuentran
        en una carpeta llamada "bibliotecas - Julian Cerizola" dentro de la carpeta
        de este mismo proyecto.

*/
//////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////////////////////////////////
#include "ABM.h"
//////////////////////////////////////////////////////////////
#define TITULO_PRUEBA   "Parcial Orquestas" /** Reemplazamos 'Parcial de prueba' por el nombre que le queramos dar a nuestro parcial o TP */
#define ALUMNO          "Julian Cerizola"   /** Reemplazamos 'Julian Cerizola' por el nombre del alumno que esté entregando esta prueba */
#define DIVISION        "1ro E - UTN FRA"   /** Reemplazamos '1ro E - UTN FRA' por la division del alumno en cuestión */
//////////////////////////////////////////////////////////////

int main()
{
    printf("\t   Bienvenide!\n\n\t%s\n\t%s\n\t%s <3\n\n",TITULO_PRUEBA,ALUMNO,DIVISION); // Notar que hay un corazón <3
    mostrarMenu('n',1)
    return 0;
}

