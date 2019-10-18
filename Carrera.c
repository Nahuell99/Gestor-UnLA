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

Carrera crearCarreraAuto(char nombre[20],char titular[20])
{
    Carrera c = malloc(sizeof(struct structCarrera));
    strcpy(c->nombre,nombre);
    strcpy(c->titular,titular);
    c->cantidadMaterias=0;
    agregarMateria(c,cargarMateriaAuto("Matematica"));
    return c;
}
Carrera crearCarrera()
{
    Carrera c = malloc(sizeof(struct structCarrera));
    c->cantidadMaterias=0;
    printf(" Ingrese el nombre de la carrera:\n");
    fflush(stdin);
    gets(c->nombre);
    printf(" Ingrese el nombre del titular de la carrera:\n");
    fflush(stdin);
    gets(c->titular);
    return c;
}
void agregarMateria(Carrera c,Materia m)
{
    c->materias[c->cantidadMaterias]=m;
    c->cantidadMaterias=(c->cantidadMaterias)+1;
}
void destruirCarrera(Carrera c)
{
    free(c);
}
void mostrarCarrera(Carrera c)
{
    printf("Carrera:%s -- Titular:%s\n",c->nombre,c->titular);
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
