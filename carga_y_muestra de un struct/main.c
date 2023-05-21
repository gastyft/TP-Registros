#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ESC 27
#define DIM 5

/// ejercicios 1, 2, y 3 del TP ESTRUCTURAS
///Struct
typedef struct
{

    char nombre[30];
    double DNI;
    int EDAD;


} stAlumno;

///Prototipado


stAlumno carga1Alumno();
int carga_alumnos(stAlumno alum[DIM]);
void mostrar1alumno();
void mostrar_todos( stAlumno alumno[DIM],int validos);

int main()
{
    system("COLOR B");
    int validos=0;
    stAlumno alumno[DIM];

    validos = carga_alumnos(alumno);

    mostrar_todos(alumno,validos);
    return 0;
}

stAlumno carga1Alumno()
{

    stAlumno alumno;
    printf("Ingrese nombre\n");
    fflush(stdin);
    gets(alumno.nombre);
    printf("Ingrese DNI\n");
    scanf("%d",alumno.DNI);
    printf("Ingrese EDAD\n");
    scanf("%d",alumno.EDAD);

    return alumno;
}

int carga_alumnos(stAlumno alum[])
{

    int i=0;
    char o=0;

    while(i<DIM && o!=ESC)
    {
        alum[i]=carga1Alumno();
        printf("PRESIONE ESCAPE PARA SALIR  O CUALQUIER TECLA PARA CONTINUAR \n");
        fflush(stdin);
        o=getch();
        i++;



    }
    return i;
}

/*
void mostrar1alumno()
{

stAlumno alumno;
printf("%s \n",alumno.nombre);
printf("%d \n",alumno.DNI);
printf("%d \n",alumno.EDAD);

}
*/
void mostrar_todos(stAlumno alumno[DIM],int validos){

int i=0;

while(i<validos){
    printf("NOMBRE: %s  \n",alumno[i].nombre);
   printf("DNI: %d  \n", alumno[i].DNI);
   printf("EDAD: %i \n",alumno[i].EDAD);
   printf("------------------------------- \n");
    i++;
}

}
