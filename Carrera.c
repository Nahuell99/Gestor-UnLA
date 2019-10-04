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

Carrera crearCarrera();
Carrera agregarMateria(Carrera c);
void destruirCarrera(Carrera c)
{
    free(c);
}
void mostrarCarrera(Carrera c)
{
    printf("%s ** titular:%s",c->nombre,c->titular);
}
char *getNombreC(Carrera c)
{
    return c->nombre;
}
char *getTitularC(Carrera c)
{
    return c->titular;
}
void setNombreC(Carrera c, char nombreNuevo[20])
{
    strcpy(c->nombre,nombreNuevo);
}
void setTitularC(Carrera c, char titularNueva[20])
{
    strcpy(c->titular,titularNueva);
}
