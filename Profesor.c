#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MenuFunciones.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "Materia.h"
#include "Carrera.h"
#include "Departamento.h"
#include "Universidad.h"

Profesor cargarProfesor(char nombreNuevo[20], char apellidoNuevo[20], int dniNuevo, int edadNuevo)
{
    Profesor p = malloc(sizeof(struct structProfesor));
    strcpy(p->nombre,nombreNuevo);
    strcpy(p->apellido,apellidoNuevo);
    p->dni=dniNuevo;
    p->edad=edadNuevo;
    return p;
}
Profesor cargarProfesorTeclado()
{
    int dniN,edadN;
    char nomN[20],apeN[20];
    printf("Ingrese el dni nuevo:\n");
    scanf("%d",&dniN);
    printf("Ingrese el nombre nuevo:\n");
    scanf("%s",nomN);
    printf("Ingrese el apellido nuevo:\n");
    scanf("%s",apeN);
    printf("Ingrese la edad nueva:\n");
    scanf("%d",&edadN);
    return cargarProfesor(nomN,apeN,dniN,edadN);
}
void mostrarProfesor(Profesor p)
{
    printf("%s %s -- %d -- %d",p->nombre,p->apellido,p->dni,p->edad);
}
void destruirProfesor(Profesor p)
{
    free(p);
}
char *getNombreP(Profesor p)
{
    return p->nombre;
}
char *getApellidoP(Profesor p)
{
    return p->apellido;
}
int getDniP(Profesor p)
{
    return p->dni;
}
int getEdadP(Profesor p)
{
    return p->edad;
}
void setNombreP(Profesor p, char nombreNuevo[20])
{
    strcpy(p->nombre,nombreNuevo);
}
void setApellidoP(Profesor p, char apellidoNuevo[20])
{
    strcpy(p->apellido,apellidoNuevo);
}
void setDniP(Profesor p, int dniNuevo)
{
    p->dni=dniNuevo;
}
void setEdadP(Profesor p, int edadNuevo)
{
    p->edad=edadNuevo;
}
