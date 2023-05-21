#include <stdio.h>
#include <stdlib.h>
#include "../carga_muestra_lib/carga_muestra.h"
#define ESC 27
#include <conio.h>
/**
Hacer una función que cuente y retorne la cantidad de estudiantes de un género determinado
(se envía por parámetro) que tiene un arreglo de alumnos.

*/
///prototipado
void F_o_M(stAlumno alumno[DIM],int validos);


int main()
{
    system("COLOR B");
    stAlumno alumno[DIM];
    int validos=0;

    validos=cargar_alumnos(alumno);
    F_o_M(alumno,validos);


    return 0;
}



void F_o_M_cont(stAlumno alumno[DIM],int validos)
{
    int i=0,j=0, cont=0,contF=0;
    char o=0;
    while(i<validos)
    {
        if(alumno[i].genero == 'm')
        {
            cont+=1;
        }
        i++;
    }

    j=0;
    while(j<validos)
    {
        if(alumno[j].genero == 'f')
        {
            contF+=1;
        }
        j++;
    }
    while(o!= ESC)
    {
        printf("Seleccione 1 oara la cantidad femeninas  o 2 para masculinos o ESCAPE para finalizar\n");
        fflush(stdin);
        o=getch();
                switch(o)
        {

        case '1':
            printf("Alumnos femeninas son: %d \n",contF);

            break;
        case '2':
            printf("Alumnas masculinos son: %d \n",cont);
            break;

        case 27:
            printf("Codigo Finalizado");
            break;
        default:
            printf("Selecciono un dato invalido \n");
            printf("Presione cualquier tecla para continuar o ESCAPE para salir \n");
            fflush(stdin);
            o=getch();
            if(o==ESC)
            {
                printf("CODIGO FINALIZADO \n");
                break;
            }

        }
    }
}
