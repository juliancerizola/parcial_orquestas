//////////////////////////////////////////////////////////////
#define ENTIDAD         "Orquestas"       /** Reemplazamos 'Entidades' por el nombre de nuestro ente (Recomiendo primer letra mayus y en plural) */
#define QTY_ORQUESTAS   50                /** Reemplazamos 1000 por la cantidad de entidades de nuestro array */
//////////////////////////////////////////////////////////////
#define TEXT_SIZE 51
//////////////////////////////////////////////////////////////

typedef struct
{
 int id;
 char nombre[TEXT_SIZE];
 char lugar[TEXT_SIZE];
 //float float1;
 //float float2;
 int tipo;
 //int int2;

 int isEmpty;
} eOrquesta;


int inicializar(eOrquesta array[], int tamanio);
int buscarEmpty(eOrquesta array[], int tamanio, int* posicion, int isEmptyBuscado);
int buscarPorId(eOrquesta array[], int tamanio, int id, int* posicion);
int alta(eOrquesta array[], int tamanio, int* idRecibido);
int modificar(eOrquesta array[], int tamanio);
int baja(eOrquesta array[], int tamanio);


