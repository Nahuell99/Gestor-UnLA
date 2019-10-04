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

void destruirMateria(Materia m)
{
    free(m);
}
Materia crearMateria()
{
    Materia m = malloc(sizeof(struct structMateria));
    m->cantidadEstudiantes=0;
    m->cantidadProfesor=0;
    printf("ingrese el nombre se la materia:\n");
    scanf("%s",m->nombre);
    int opcion;
    printf("Debe inscribir por lo menos a uno de dos profesores:\n");
    agregarProfesor(m,cargarProfesorTeclado());
    printf("\nDesea cargar el segundo profesor ahora?:\n1-SI\n2-NO\n");
    scanf("%d",&opcion);
    if(opcion==1)
    {
        agregarProfesor(m,cargarProfesorTeclado());
    }
    printf("\nDesea inscribir a los alumnos?\n1-SI\n2-NO\n");
    scanf("%d",&opcion);
    if(opcion==1)
    {
        agregarEstudiante(m,cargarEstudianteTeclado());
        printf("\nDesea inscribir otro alumno?\n1-SI\n2-NO\n");
        scanf("%d",&opcion);
        while(opcion==1&&((m->cantidadEstudiantes)>50))
        {
            agregarEstudiante(m,cargarEstudianteTeclado());
            printf("Desea inscribir otro alumno?\n1-SI\n2-NO");
            scanf("%d",&opcion);
        }
        if(m->cantidadEstudiantes>50)
        {
            printf("La materia a llegado a su maximo de alumnos inscriptos (50).");
        }
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
void mostrarMateria(Materia m)
{
    printf("%s profesor:%s",m->nombre,m->profesores[0]->nombre);
}
char *getNombreM(Materia m)
{
    return m->nombre;
}
void setNombreM(Materia m,char nombreNuevo[20])
{
    strcpy(m->nombre,nombreNuevo);
}
