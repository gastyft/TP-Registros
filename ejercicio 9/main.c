#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../carga_muestra_lib/carga_muestra.h"
#include "../Firma/Firma.h"
#define ESC 27


/**
Hacer una función principal que pruebe el funcionamiento de todos los incisos anteriores, con
un menú de opciones para poder ejecutar todas las funciones requeridas. Tengan presente la
correcta declaración y el ámbito de variables.
*/


///prototipado
int posicionMenor(stAlumno alumno[DIM], int cantVal, int pos);

stAlumno ordenacionSeleccion(stAlumno alumno[DIM], int cantVal);

stAlumno insercion(stAlumno alumno[DIM],int *validos);
void F_o_M_cont(stAlumno alumno[DIM],int validos);


void F_o_M(stAlumno alumno[DIM],int validos);

void menu(stAlumno alumnos[DIM],int *validos, int pos);





int main()
{

    system("COLOR B");
    int validos=0,pos=0;
    stAlumno alumno[DIM];
    menu(alumno,&validos,pos);

firma();
}



///funciones
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




void menu(stAlumno alumnos[DIM],int *validos,int pos){
char op=0;

while(op!= ESC){
    printf("Seleccione opcion \n");
    printf("1- para cargar \n");
    printf("2- para mostrar \n");
    printf("4- ordenacion seleccion \n");
    printf("5- muestra alumnos por genero \n");
    printf("6-insercion de un nuevo alumno en un arreglo ordenado\n");
    printf("7- no disponible por el momento \n");
    printf("8-Cuenta cantidad Femeninos o masculinos \n");
    printf("PRESIONE ESCAPE PARA FINALIZAR \n");

fflush(stdin);
op=getch();

switch(op){
case '1':
    *validos=cargar_alumnos(alumnos);
    break;
case '2':
    mostrar_alumnos(alumnos,*validos);
    break;
case '4':
    ordenacionSeleccion(alumnos,*validos);
    mostrar_alumnos(alumnos,*validos);
    break;
case '5':
    F_o_M(alumnos,*validos);
    break;
case '6':
    posicionMenor(alumnos,*validos,pos);
    insercion(alumnos,validos);
    mostrar_alumnos(alumnos,*validos);
    break;
case '8':
    F_o_M_cont(alumnos,*validos);
    break;

case 27:
    printf("CODIGO FINALIZADO\n");
    break;



default:
    printf("Opcion incorrecta presione cualquier tecla para continuar o ESCAPE para finalizar \n");

    printf("Seleccione opcion \n");
    printf("1- para cargar \n");
    printf("2- para mostrar \n");
    printf("4- ordenacion seleccion \n");
    printf("5- muestra alumnos por genero \n");
    printf("6-insercion de un nuevo alumno en un arreglo ordenado\n");
    printf("7- no disponible por el momento \n");
    printf("8-Cuenta cantidad Femeninos o masculinos \n");

    fflush(stdin);
    op=getch();

    if(op == ESC){
        printf("CODIGO FINALIZADO del default\n");
        break;
    }

}







}



}
