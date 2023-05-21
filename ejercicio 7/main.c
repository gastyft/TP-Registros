#include <stdio.h>
#include <stdlib.h>
#include "../carga_muestra_lib/carga_muestra.h"
#include "../Firma/Firma.h"
#include<conio.h>
#include <string.h>

///Hacer una función que ordene el arreglo de alumnos por medio del método de inserción. El
///criterio de ordenación es el nombre.


///prototipado

stAlumno insercion(stAlumno alumno[DIM], int validos);
stAlumno ordenacionInsercion(stAlumno alumno[DIM], int cantVal);

int main()
{
    system("COLOR B");
    stAlumno alumnos[DIM];
    int validos=0;
    validos = cargar_alumnos(alumnos);

ordenacionInsercion(alumnos,validos);
    mostrar_alumnos(alumnos,validos);
    return 0;
}

///funciones
stAlumno insercion(stAlumno alumno[DIM], int validos){
{
    int i= validos; //ultima pos valida izq
    stAlumno alumn;
    alumn= alumno[i];
    while(i >= 0){
   if ( strcmp( alumn.nombre, alumno[i].nombre)>0){
/** strcmp Comparar dos cadenas para saber si son iguales o no, devuelve un valor entero
(0,> 0 ó < 0), cero si son iguales y mayor o menor que cero dependiendo del orden de comparación de los strings.

*/

        alumno[i+1] = alumno[i];


    }
    i--;
    alumno[i+1] = alumn;
     alumn= alumno[i];
}
}
return alumno[DIM];
}

stAlumno ordenacionInsercion(stAlumno alumno[DIM], int cantVal){
    int u=0;
    while (u < cantVal - 1){
     //llega hasta la posición del anteúltimo elemento del arreglo.
        insercion(alumno, cantVal);
        u++;
    }
return alumno[DIM];
}




