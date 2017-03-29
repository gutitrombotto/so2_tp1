
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> /* offsetof */

/* Estructura principal: matricula de un estudiante */
typedef struct st_matricula {
   char nombre[32];
   char a_paterno[32];
   char a_materno[32];
   char edad[32];
} Matricula;

/* 
** Opcional: esta enumeracion permite vincular ciertos 
** valores mas descriptivos para hacer referencia a cada 
** uno de los campos de la estructura. En otras palabras 
** en lugar de utilizar el valor:
**    1
**
** utilizamos el valor:
**    A_PATERNO
**
** Ambos valores los utilizamos para procesar el apellido 
** paterno pero por razones mas que obvias es mejor el segundo.
*/
enum e_campos {NOMBRE, A_PATERNO, A_MATERNO, EDAD, NUM_CAMPOS};

/* Nombre o texto a utilizar para cada uno de los campos */
char nombre[NUM_CAMPOS][128] = {
   "nombre", 
   "apellido paterno", 
   "apellido materno", 
   "edad"
};

/* Posicion de inicio (en bytes) de cada uno de los campos */
size_t inicio[NUM_CAMPOS] = {
   offsetof(Matricula, nombre), 
   offsetof(Matricula, a_paterno), 
   offsetof(Matricula, a_materno), 
   offsetof(Matricula, edad)
};

int main(void)
{
   Matricula mat;
   int i;
   
   for (i = 0; i < NUM_CAMPOS; i++){
      printf("Introduce el %s: ", nombre[i]);
      fflush(stdout);
      scanf("%s", (char *) &mat + inicio[i]);
   }
   
   puts("---------------");
   /*
   for (i = 0; i < NUM_CAMPOS; i++)
      printf("%s: %s\n", nombre[i], (char *) &mat + inicio[i]);
   */
   printf("%s\n", mat.nombre);
   return EXIT_SUCCESS;
}