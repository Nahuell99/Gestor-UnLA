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

Materia cargarMateriaAuto(char nom[20])
{
    Materia m = malloc(sizeof(struct structMateria));
    strcpy(m->nombre,nom);
    m->cantidadEstudiantes=0;
    m->cantidadProfesor=0;
    agregarProfesor(m,cargarProfesor("Luis","Millan",95326549,50));
    agregarEstudiante(m,cargarEstudiante("Aleix","Ruman", 55676999, 30) );
    agregarEstudiante(m,cargarEstudiante("Jorge", "Saenz", 57337316, 40) );
    agregarEstudiante(m,cargarEstudiante("Alberto", "Benitez", 55953219, 25) );
    agregarEstudiante(m,cargarEstudiante("Raul", "Gomez", 54509427, 24) );
    agregarEstudiante(m,cargarEstudiante("Oscar", "Mendoza", 50905655, 28) );
    agregarEstudiante(m,cargarEstudiante("Eric", "Carrasco", 59575756, 35) );
    agregarEstudiante(m,cargarEstudiante("Joel", "Mora", 49456797, 45) );
    agregarEstudiante(m,cargarEstudiante("Alexis", "Sanchez", 47526862, 21) );
    agregarEstudiante(m,cargarEstudiante("Franco", "Malla", 65594013, 19) );
    agregarEstudiante(m,cargarEstudiante("Nahuel", "Ponce", 42231767, 20) );
    agregarEstudiante(m,cargarEstudiante("Jorge", "Piranelo", 42048957, 26) );
    agregarEstudiante(m,cargarEstudiante("Marito", "Baracus", 58852667, 19) );
    agregarEstudiante(m,cargarEstudiante("John", "Whick", 42327927, 27) );
    agregarEstudiante(m,cargarEstudiante("Enrique", "Pinty", 60441112, 26) );
    agregarEstudiante(m,cargarEstudiante("Tomas", "Roca", 48479537, 24) );
    agregarEstudiante(m,cargarEstudiante("Carlos","Martin", 63445622, 29) );
    agregarEstudiante(m,cargarEstudiante("Thiago","Corta", 42450321, 22) );
    agregarEstudiante(m,cargarEstudiante("Tito","Merlo", 52719718, 31) );
    return m;
}
Materia crearMateria()
{
    Materia m = malloc(sizeof(struct structMateria));
    m->cantidadEstudiantes=0;
    m->cantidadProfesor=0;
    printf(" ingrese el nombre se la materia:\n");
    fflush(stdin);
    gets(m->nombre);
    int opcion;
    printf(" Debe inscribir por lo menos a uno de dos profesores\n");
    system("pause");
    system("cls");
    agregarProfesor(m,cargarProfesorTeclado());
    printf("\n Desea cargar el segundo profesor ahora?:\n1-SI\n2-NO\n");
    scanf("%d",&opcion);
    if(opcion==1)
    {
        system("cls");
        agregarProfesor(m,cargarProfesorTeclado());
    }
    return m;
}
void agregarEstudiante(Materia m, Estudiante e)
{
    m->estudiantes[m->cantidadEstudiantes]=e;
    m->cantidadEstudiantes=(m->cantidadEstudiantes)+1;
}
void agregarProfesor(Materia m, Profesor p)
{
    m->profesores[m->cantidadProfesor]=p;
    m->cantidadProfesor=(m->cantidadProfesor)+1;
}
void destruirMateria(Materia m)
{
    free(m);
}
void mostrarMateria(Materia m)
{
    printf("Materia: %s -- Profesor titular:%s\n",m->nombre,m->profesores[0]->nombre);
}
char *getNombreM(Materia m)
{
    return m->nombre;
}
void setNombreM(Materia m,char nombreNuevo[20])
{
    strcpy(m->nombre,nombreNuevo);
}
