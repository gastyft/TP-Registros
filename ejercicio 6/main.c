#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../carga_muestra_lib/carga_muestra.h"
#include "../Firma/Firma.h"
#define ESC 27
#define DIM 10

/**Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato,
conservando el orden.
*/

///protipado
stAlumno insercion(stAlumno alumno[DIM],int *validos);

int main()
{
    system("COLOR B");
    int validos=0;
    stAlumno alumno[DIM];
    validos= cargar_alumnos(alumno);

    insercion(alumno,&validos);
    mostrar_alumnos(alumno,validos);
    firma();
    return 0;
}


///funciones
stAlumno insercion(stAlumno alumno[DIM],int *validos){
int i;

i=*validos+1;
stAlumno newAlumno;
printf("Ingrese alumno \n");
printf("Ingrese nombre \n");
gets(newAlumno.nombre);
printf("Ingrese matricula \n");
scanf("%d",&newAlumno.matricula);
printf("Ingrese genero \n");
fflush(stdin);
scanf("%c",&newAlumno.genero);

    while (i >= 0 && newAlumno.matricula < alumno[i].matricula){
        alumno[i+1] = alumno[i];
        i--;
    }
    alumno[i+1] = newAlumno;


*validos+=1;
    return alumno[DIM];
}







