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

Universidad crearUniversidad()
{
    Universidad u = malloc(sizeof(struct structUniversidad));
    strcpy(u->nombre,"Universidad Nacional de Lanus");
    strcpy(u->fundacion,"7 de junio de 1995");
    strcpy(u->rector,"Dra. Ana Jaramillo");
    u->departamentos[0]=crearDepartamentos(0);
    u->departamentos[1]=crearDepartamentos(1);
    u->departamentos[2]=crearDepartamentos(2);
    u->departamentos[3]=crearDepartamentos(3);
    return u;
};
void mostrarUniversidad(Universidad u)
{
    printf("\n                      %s\n                       Rectora: %s\n                           %s\n",u->nombre,u->rector,u->fundacion);
    system("pause");
    system("cls");
};
char *getNombreU(Universidad u)
{
    return u->nombre;
};
char *getFundacionU(Universidad u)
{
    return u->fundacion;
};
char *getRectorU(Universidad u)
{
    return u->rector;
};
