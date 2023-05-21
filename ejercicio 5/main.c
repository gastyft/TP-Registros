#include <stdio.h>
#include <stdlib.h>
#include "../carga_muestra_lib/carga_muestra.h"
#include <conio.h>
#include "../Firma/Firma.h"
#define ESC 27
#define DIM 10




///Mostrar segun quiera usuario, los alumnos masculinos o las alumnas femeninas

///prototipado
void F_o_M(stAlumno alumno[DIM],int validos);

int main()
{
    system("COLOR B");
    stAlumno alumno[DIM];
    int validos=0;

    validos = cargar_alumnos(alumno);
    F_o_M(alumno,validos);



    return 0;
}


///funciones


void F_o_M(stAlumno alumno[DIM],int validos)
{
    int i=0,j=0;
    char o=0;

    while(o!= ESC)
    {

        printf("Ingrese si quiere ver alumnos Femeninos con 1 o Masculinos con 2 o PRESS ESC para finalizar \n ");
        fflush(stdin);

        o=getch();
        switch(o)
        {

        case '1':
            i=0;
            while(i<validos)
            {
                if(alumno[i].genero == 'm')
                {
                    printf("Nombre: %s \n",alumno[i].nombre);
                    printf("Matricula: %d \n",alumno[i].matricula);
                    printf("Genero: Masculino \n");
                    printf("--------------------\n");
                }
                i++;
            }


            break;
        case '2':

            j=0;
            while(j<validos)
            {
                if(alumno[j].genero == 'f')
                {
                    printf("Nombre: %s \n",alumno[j].nombre);
                    printf("Matricula: %d \n",alumno[j].matricula);
                    printf("Genero: Femenino \n");
                    printf("-------------------  \n");
                }
                j++;
            }

            break;
        case 27:
            printf("Codigo Finalizado \n");
            firma();
            break;
        default:
            printf("Selecciono un numero invalido. Presione cualquier tecla para continuar o ESCAPE para finalizar \n");
            fflush(stdin);
            o=getch();
            if(o==ESC)
            {
                printf("Codigo Finalizado \n");
                firma();
                break;
            }

        }
    }

}
