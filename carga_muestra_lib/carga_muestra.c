#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define DIM 10
#define ESC 27
#include "carga_muestra.h"


///funciones

stAlumno cargar_1_alumno(){


stAlumno alumno1;
char opcion=0;
printf("Ingrese nombre \n");
fflush(stdin);
gets(alumno1.nombre);
printf("Ingrese matricula \n");
scanf("%d",&alumno1.matricula);
printf("Ingrese genero\n");
fflush(stdin);
opcion= getch();
alumno1.genero=opcion;

while(alumno1.genero != 'm' && alumno1.genero != 'f'){
    printf("Ingrese un genero no valido(M / F): ");
    fflush(stdin);
   opcion= getch();
alumno1.genero=opcion;

}
system("cls");
return alumno1;
}

int cargar_alumnos(stAlumno alumno[DIM]){


char o=0;
int i=0;
while(i<DIM && o!=ESC){

alumno[i]=cargar_1_alumno();
i++;
printf("Presione ESCAPE para finalizar con la carga o cualquier tecla para continuar \n");
fflush(stdin);
o=getch();

}
return i;
}

void mostrar_alumnos(stAlumno alumnos[DIM],int validos){
int i=0;
while(i<validos){
printf("Nombre: %s \n",alumnos[i].nombre);
printf("Matricula: %d \n",alumnos[i].matricula);

if(alumnos[i].genero == 'f'){
printf("Alumno femenino\n");
}
else if(alumnos[i].genero == 'm'){
    printf("Alumno masculino \n");
}
printf("------------------\n");
i++;
}
}


