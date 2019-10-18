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

Estudiante cargarEstudiante(char nombreNuevo[20], char apellidoNuevo[20], int dniNuevo, int edadNuevo)
{
    Estudiante e = malloc(sizeof(struct structEstudiante));
    strcpy(e->nombre,nombreNuevo);
    strcpy(e->apellido,apellidoNuevo);
    e->dni=dniNuevo;
    e->edad=edadNuevo;
    return e;
};
Estudiante cargarEstudianteTeclado()
{
    int dniN,edadN;
    char nomN[20],apeN[20];
    printf(" Ingrese el nombre nuevo:\n");
    fflush(stdin);
    gets(nomN);
    printf(" Ingrese el apellido nuevo:\n");
    fflush(stdin);
    gets(apeN);
    printf(" Ingrese el dni nuevo:\n");
    dniN=comprobador();
    printf(" Ingrese la edad nueva:\n");
    edadN=comprobador();
    return cargarEstudiante(nomN,apeN,dniN,edadN);
}
void mostrarEstudiante(Estudiante e)
{
    printf(" %s %s %d %d \n",e->nombre,e->apellido,e->dni,e->edad);
}
void destruirEstudiante(Estudiante e)
{
    free(e);
}
char *getNombreE(Estudiante e)
{
    return e->nombre;
}
char *getApellidoE(Estudiante e)
{
    return e->apellido;
}
int getDniE(Estudiante e)
{
    return e->dni;
}
int getEdadE(Estudiante e)
{
    return e->edad;
}
void setNombreE(Estudiante e, char nombreNuevo[20])
{
    strcpy(e->nombre,nombreNuevo);
}
void setApellidoE(Estudiante e, char apellidoNuevo[20])
{
    strcpy(e->apellido,apellidoNuevo);
}
void setDniE(Estudiante e, int dniNuevo)
{
    e->dni=dniNuevo;
}
void setEdadE(Estudiante e, int edadNuevo)
{
    e->edad=edadNuevo;
}
