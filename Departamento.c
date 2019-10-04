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

Departamento crearDepartamentos(int i)
{
    Departamento d = malloc(sizeof(struct structDepartamento));
    switch(i)
    {
    case 0:
        strcpy(d->nombre,"Departamento de Desarrollo Productivo y Tecnologico");
        strcpy(d->titular,"Dr. Pablo Narvaja");
        d->cantidadCarreras=0;
        case 1:
        strcpy(d->nombre,"Departamento de Planificación y Políticas Públicas");
        strcpy(d->titular,"Dr. Francisco Pestanha");
        d->cantidadCarreras=0;
        break;
        case 2:
        strcpy(d->nombre,"Departamento de Humanidades y Artes");
        strcpy(d->titular,"Mtro. Daniel Bozzani");
        d->cantidadCarreras=0;
        break;
        case 3:
        strcpy(d->nombre,"Departamento de Salud Comunitaria");
        strcpy(d->titular,"Lic. Ramón Alvarez");
        d->cantidadCarreras=0;
        break;
    }
return d;
}
void destruirDepartamento(Departamento d)
{
    free(d);
};
void mostrarDepartamento(Departamento d)
{
    printf("%s\n",d->nombre);
};
char *getNombreD(Departamento d)
{
    return d->nombre;
};
char *getTitularD(Departamento d)
{
    return d->titular;
};
void setNombreD(Departamento d,char nombreNuevo[20])
{
    strcpy(d->nombre,nombreNuevo);
};
void setTitularD(Departamento d,char titularNueva[20])
{
    strcpy(d->titular,titularNueva);
};
