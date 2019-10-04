#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "MenuFunciones.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "Materia.h"
#include "Carrera.h"
#include "Departamento.h"
#include "Universidad.h"

int main()
{
    Universidad universidad=crearUniversidad();
    bienvenida(universidad);
    int a=0;
    while(a==0)//MENU PRINCIPAL
    {
        int cod;
        cod=menuPrincipal();
        switch(cod)
        {
        case 1://GESTIONAR ESTUDIANTES
            menuEstudiante(universidad);
            break;
        case 2://CARGAR ESTUDIANTES
            universidad=menuCargarEstudiante(universidad);
            break;
        case 3://DEPARTAMENTO
            //universidad=menuDepartamento(universidad);
            break;
        case 0://CERRAR PROGRAMA
            printf("Adios.");
            a=1;
        default:
            printf("Opcion incorrecta.");
            Sleep(2400);
            system("cls");
        }
    }
    return 0;
}
