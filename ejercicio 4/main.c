#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define DIM 10
#include"../Firma/Firma.h"
#include "../carga_muestra_lib/carga_muestra.h"



///Hacer ordenacion por seleccion tomando en cuenta el numero de matricula.

///prototipado
int posicionMenor(stAlumno alumno[DIM], int cantVal, int pos);
stAlumno ordenacionSeleccion(stAlumno alumno[DIM], int cantVal);
int main()
{
    int pos=0;
    system("COLOR B");
    int validos=0;
    stAlumno alumno[DIM];
    validos=cargar_alumnos(alumno);

    posicionMenor(alumno,validos,pos);
    ordenacionSeleccion(alumno,validos);
        mostrar_alumnos(alumno,validos);
firma();
}




int posicionMenor(stAlumno alumno[DIM], int cantVal, int pos){
    int menor = alumno[pos].matricula;
    int posMenor = pos;
    int index = pos + 1;
    while (index < cantVal){
        if(menor > alumno[index].matricula){
            menor = alumno[index].matricula;
            posMenor = index;
        }
        index++;
    }
    return posMenor;
}

stAlumno ordenacionSeleccion(stAlumno alumno[DIM], int cantVal){
    int posMenor;
    int i = 0;
    int aux=0;
    while(i< cantVal - 1){ /// llego hasta la anteúltima posición
        posMenor = posicionMenor(alumno, cantVal, i);
        aux = alumno[posMenor].matricula;
        alumno[posMenor].matricula = alumno[i].matricula;
        alumno[i].matricula = aux;
        i++;
    }
    return alumno[DIM];
}
