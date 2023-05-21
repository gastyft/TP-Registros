#ifndef CARGA_MUESTRA_H_INCLUDED
#define CARGA_MUESTRA_H_INCLUDED
#define DIM 10
///struct
typedef struct{

char nombre[40];
int matricula;
char genero;


}stAlumno;

///prototipado
stAlumno cargar_1_alumno();
int cargar_alumnos(stAlumno alumno[DIM]);
void mostrar_alumnos(stAlumno alumnos[DIM],int validos);


#endif // CARGA_MUESTRA_H_INCLUDED
