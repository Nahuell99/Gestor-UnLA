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

int comprobador();
void bienvenida(Universidad u);
void menuEstudiante(Universidad u);
void menuListadoEstudiantes(Universidad u);
void menuBuscadorEstudiante(Universidad u);
Universidad menuCargarEstudiante(Universidad u);
Universidad menuDepartamento(Universidad u);
void mostrarEstudianteTodos(Universidad u);
Estudiante generarLitaCompleta(Universidad u);
void mostrarEstudianteNom(Universidad u);
void mostrarEstudianteApe(Universidad u);
void mostrarEstudianteDni(Universidad u);
void buscadorEstudianteNom(Universidad u);
void buscadorEstudianteApe(Universidad u);
void buscadorEstudianteDni(Universidad u);

void bienvenida(Universidad u)
{
    printf("*****************************************************************************\n");
    printf("*****************Bienvenido al Sistema de Gestios de la Unla*****************\n");
    printf("*****************************************************************************");
    mostrarUniversidad(u);
}

void opciones1()
{
    printf("Ingrese el numero de la categoria a gestionar: \n");
    printf("1-Gestionar Estudiantes\n");
    printf("2-Cargar Estudiantes\n");
    printf("3-Gestion por Departamentos\n");
    printf("0-Cerrar programa\n");
}
void opciones2()
{
    system("cls");
    printf("*************************\n");
    printf("**CATEGORIA ESTUDIANTES**\n");
    printf("*************************\n");
    printf("Ingrese la opcion que desea realizar:\n");
    printf("1-Ver listado de estudiantes.\n");
    printf("2-Buscar estudiante.\n");
    printf("0-Menu anterior.\n");
}
void opciones3()
{
    system("cls");
    printf("*************************\n");
    printf("****CATEGORIA LISTADO****\n");
    printf("*************************\n");
    printf("Ingrese la opcion que desea realizar:\n");
    printf("1-Ver listado completo.\n");
    printf("2-Ver ordenado por nombre.\n");
    printf("3-Ver ordenado por apellido.\n");
    printf("4-Ver ordenado por DNI");
    printf("0-Menu anterior.\n");
}
void opciones4()
{
    system("cls");
    printf("*************************\n");
    printf("****CATEGORIA BUSQUEDA***\n");
    printf("*************************\n");
    printf("Ingrese la opcion que desea realizar:\n");
    printf("1-Buscar por nombre.\n");
    printf("2-Buscar por apellido.\n");
    printf("3-Buscar por DNI.\n");
    printf("0-Menu anterior.\n");
}
int comprobador()
{
    int cod;
    while(!scanf("%d",&cod))
    {
        fflush(stdin);
        printf("Ah ingresado una letra, debe ingresar un numero. \n");
        Sleep(1400);
    }
    return cod;
}
int menuPrincipal()
{
    int cod;
    opciones1();
    while(!scanf("%d",&cod))
    {
        fflush(stdin);
        printf("Ah ingresado una letra, debe ingresar un numero. \n");
        Sleep(2400);
        system("cls");
        opciones1();
    }
    return cod;
}
void menuEstudiante(Universidad u)
{
    int a=0;
    while(a==0)//MENU ESTUDIANTE 1
    {
        opciones2();
        int cod=comprobador();
        switch(cod)
        {
        case 1://LISTADO DE ESTUDIANTE 1.1
            menuListadoEstudiantes(u);
            break;
        case 2://BUSCAR ESTUDIANTE  1.2
            system("pause");
            menuBuscadorEstudiante(u);
            break;
        case 0://MENU ANTERIOR
            a=1;
        default:
            printf("Opcion incorrecta.");
            Sleep(2400);
            system("cls");
        }
    }
    return u;
}   //MENU ESTUDIANTE 1
void menuListadoEstudiantes(Universidad u)
{
    int a=0;
    while(a==0)//MENU LISTADO DE ESTUDIANTES 1.1
    {
        opciones3();
        int cod=comprobador();
        system("pause");
        switch(cod)
        {
        case 1://LISTADO COMPLETO 1.1.1
            mostrarEstudianteTodos(u);
            break;
        case 2://POR NOMBRE 1.1.2
            mostrarEstudianteNom(u);
            break;
        case 3://POR APELLIDO 1.1.3
            mostrarEstudianteApe(u);
            break;
        case 4://POR DNI 1.1.4
            mostrarEstudianteDni(u);
            break;
        case 0://MENU ANTERIOR
            a=1;
        default:
            printf("Opcion incorrecta.");
            Sleep(2400);
            system("cls");
        }
    }
}
void menuBuscadorEstudiante(Universidad u)
{
    int a=0;
    while(a==0)//MENU BUSCADOR
    {
        int cod;
        opciones4();
        while(!scanf("%d",&cod))
        {
            fflush(stdin);
            printf("Ah ingresado una letra, debe ingresar un numero. \n");
            Sleep(2400);
            system("cls");
            opciones4();
        }
        switch(cod)
        {
        case 1://BUSCAR POR NOMBRE
            buscadorEstudianteNom(u);
            break;
        case 2://BUSCAR POR APELLIDO
            buscadorEstudianteApe(u);
            break;
        case 3://BUSCAR POR DNI
            buscadorEstudianteDni(u);
            break;
        case 0://MENU ANTERIOR
            a=1;
        default:
            printf("Opcion incorrecta.");
            Sleep(2400);
            system("cls");
        }
    }
}
Universidad menuCargarEstudiante(Universidad u)
{
    printf("Menu de carga de alumno, eliga a cual departamento desea asignarlo:\n");
    //SELECCIONAS DEPARTAMENTO
    int depar;
    int i;
    for(i=0;i<4;i++)
    {
        printf("%d-",i);
        mostrarDepartamento(u->departamentos[i]);
    }
    scanf("%d",&depar);
    //SELECCIONAS CARRERA
    if(u->departamentos[depar]->cantidadCarreras>0)
    {

        printf("seleccione a que carrera desea asignarlo:\n");
        int car=0;
        for(i;i<u->departamentos[depar]->cantidadCarreras;i++)
        {
            system("pause");
            printf("%d-",i);
            mostrarCarrera(u->departamentos[depar]->carreras[i]);
        }
        scanf("%d",&car);
        //SELECCIONAS MATERIA
        printf("seleccione a que materia va a inscribirlo:\n");
        int mate=0;
        for(i;i<u->departamentos[depar]->carreras[car]->cantidadMaterias;i++)
        {
            printf("%d-",i+1);
            system("pause");
            mostrarMateria(u->departamentos[depar]->carreras[car]->materias[i]);
        }
        scanf("%d",&mate);
        mate=mate-1;
        //A LO ELEGIDO LE AGREGO UN ALUMNO
        u->departamentos[depar]->carreras[car]->materias[mate]->estudiantes[u->departamentos[depar]->carreras[car]->materias[mate]->cantidadEstudiantes]=cargarEstudianteTeclado();
        u->departamentos[depar]->carreras[car]->materias[mate]->cantidadEstudiantes=u->departamentos[depar]->carreras[car]->materias[mate]->cantidadEstudiantes+1;
        }
        else
        {
        printf("No hay ninguna carreca cargada en este departamento.\n");
        system("pause");
        }

    return u;
}
/*Universidad menuDepartamento(Universidad u)
{
     printf("Menu de gestion de departamento,selecione uno:\n");
    //SELECCIONAS DEPARTAMENTO
    int depar;
    for(int i=0;i<4;i++)
    {
        printf("%d-",i);
        mostrarDepartamento(u->departamentos[i]);
    }
    scanf("%d",&depar);
    u->departamentos[depar]->carreras[u->departamentos[depar]->cantidadCarreras]=cargarCarrera();
    u->departamentos[depar]->cantidadCarreras=u->departamentos[depar]->cantidadCarreras+1;

    return u;
}*/
void mostrarEstudianteTodos(Universidad u)
{
    int i,j,k,l;
    for(i=0; i<4; i++) //RECORRE LOS 4 DEPARTAMENTOS
    {
        if(u->departamentos[i]->cantidadCarreras>0)//PREGUNTA SI SE CARRGO POR LO MENOS UNA CARRERA (CARRERA?)
        {
            for(j=0; j<u->departamentos[i]->cantidadCarreras; j++) //SI SE CREO LAS RECORRO (CARRERA )
            {
                if(u->departamentos[i]->carreras[j]->cantidadMaterias>0)//PREGUNTO SI SE CREO POR LO MENOS UNA MATERIA A LA CARRERA (MATERIA?)
                {
                    for(k=0; k<u->departamentos[i]->carreras[j]->cantidadMaterias; k++) //SI SE CREO LA RECORRO (MATERIA )
                    {
                        if(u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes>0)//PREGUNTO SI LA CARRERA TIENE ALUMNOS INSCRIPTOS
                        {
                            printf("Nombre Aprellido DNI edad");
                            for(l=0; l<u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes; l++)//SI LOS TIENE RECORRO (ALUMNOS)
                            {
                                mostrarEstudiante(u->departamentos[i]->carreras[j]->materias[k]->estudiantes[l]);
                            }
                        }
                        else
                        {
                            printf("Aun no se ha inscripto ningun alumno a la materia: %s",u->departamentos[i]->carreras[j]->materias[k]->nombre);
                        }
                    }
                }
                else//EN CASO QUE NO MUESTRO ERROR
                {
                    printf("Aun no se han cargado materias dentro de la carrera: %s",u->departamentos[i]->carreras[j]->nombre);
                }
            }
        }
        else//EN CASO QUE NO MUESTRO ERROR
        {
            printf("Aun no has cargado ninguna carrera en el departamento %s.\nSelecciona el menu departamento para cargar uno.\n\n",u->departamentos[i]->nombre);
        }
    }
    system("pause");
}
void mostrarEstudianteNom(Universidad u)
{
    Estudiante EstOrde[400];
    Estudiante aux;
    int contador=0;
    system("pause");
    int i,j,k,l;
    for(i=0;i<4;i++)//RECORRO DEPARTAMENTOS
    {
        for(j=0;j<u->departamentos[i]->cantidadCarreras;j++)//RECORRO CARRERAS
        {
            for(k=0;k<u->departamentos[i]->carreras[j]->cantidadMaterias;k++)//RECORRO MATIERIAS
            {
                for(l=0;l<u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes;j++) //RECORRO ESTUDIANTES
                {
                    EstOrde[contador]=u->departamentos[i]->carreras[j]->materias[k]->estudiantes[l];
                    contador=contador+1;
                }
            }
        }
    }
    int a=0;
    while(a==0)
    {
        a=1;
        int i;
        for(i=0;i<contador-1;i++)
        {
            int res=strcmp(EstOrde[i]->nombre,EstOrde[i+1]->nombre);
            if(res>0)
            {
                a=0;
                aux=EstOrde[i];
                EstOrde[i]=EstOrde[i+1];
                EstOrde[i+1]=aux;
            }
        }
    }
    for(i=0;i<contador;i++)
    {
        mostrarEstudiante(EstOrde[i]);
    }
}
void mostrarEstudianteApe(Universidad u)
{
    Estudiante EstOrde[400];
    Estudiante aux;
    int contador=0;
    int i,j,k,l;
    for(i=0;i<4;i++)//RECORRO DEPARTAMENTOS
    {
        for(j=0;j<u->departamentos[i]->cantidadCarreras;j++)//RECORRO CARRERAS
        {
            for(k=0;k<u->departamentos[i]->carreras[j]->cantidadMaterias;k++)//RECORRO MATIERIAS
            {
                for(l=0;l<u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes;j++) //RECORRO ESTUDIANTES
                {
                    EstOrde[contador]=u->departamentos[i]->carreras[j]->materias[k]->estudiantes[l];
                    contador=contador+1;
                }
            }
        }
    }
    int a=0;
    while(a==0)
    {
        a=1;
        for(i=0;i<contador-1;i++)
        {
            if(strcmp(EstOrde[i]->apellido,EstOrde[i+1]->apellido)>0)
            {
                a=0;
                aux=EstOrde[i];
                EstOrde[i]=EstOrde[i+1];
                EstOrde[i+1]=aux;
            }
        }
    }
    for(i=0;i<contador;i++)
    {
        mostrarEstudiante(EstOrde[i]);
    }
}
void mostrarEstudianteDni(Universidad u)
{
    Estudiante EstOrde[400];
    Estudiante aux;
    int contador=0;
    int i,j,k,l;
    for(i=0;i<4;i++)//RECORRO DEPARTAMENTOS
    {
        for(j=0;j<u->departamentos[i]->cantidadCarreras;j++)//RECORRO CARRERAS
        {
            for(k=0;k<u->departamentos[i]->carreras[j]->cantidadMaterias;k++)//RECORRO MATIERIAS
            {
                for(l=0;l<u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes;j++) //RECORRO ESTUDIANTES
                {
                    EstOrde[contador]=u->departamentos[i]->carreras[j]->materias[k]->estudiantes[l];
                    contador=contador+1;
                }
            }
        }
    }
    int a=0;
    while(a==0)
    {
        a=1;
        for(i=0;i<contador-1;i++)
        {
            if(EstOrde[i]->dni>EstOrde[i+1]->dni)
            {
                a=0;
                aux=EstOrde[i];
                EstOrde[i]=EstOrde[i+1];
                EstOrde[i+1]=aux;
            }
        }
    }
    for(i=0;i<contador;i++)
    {
        mostrarEstudiante(EstOrde[i]);
    }
}
void buscadorEstudianteNom(Universidad u)
{
    Estudiante EstOrde[400];
    Estudiante aux;
    int contador=0;
    system("pause");
    int i,j,k,l;
    for(i=0;i<4;i++)//RECORRO DEPARTAMENTOS
    {
        for(j=0;j<u->departamentos[i]->cantidadCarreras;j++)//RECORRO CARRERAS
        {
            for(k=0;k<u->departamentos[i]->carreras[j]->cantidadMaterias;k++)//RECORRO MATIERIAS
            {
                for(l=0;l<u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes;j++) //RECORRO ESTUDIANTES
                {
                    EstOrde[contador]=u->departamentos[i]->carreras[j]->materias[k]->estudiantes[l];
                    contador=contador+1;
                }
            }
        }
    }
    char dato[30];
    int comprobar=0;
    printf("\nIngrese el nombre del estudiante que este buscando:\n");
    scanf("%s",dato);
    for(i=0;i<contador;i++)
    {
        int res=strcmp(dato,EstOrde[i]->nombre);
        if(res==0)
        {
            comprobar=1;
            mostrarEstudiante(EstOrde[i]);
        }
    }
    if(comprobar==0)
    {
        printf("No se a allado alumno con ese nombre ingresado.\n");
    }
}
void buscadorEstudianteApe(Universidad u)
{
    Estudiante EstOrde[400];
    Estudiante aux;
    int contador=0;
    system("pause");
    int i,j,k,l;
    for(i=0;i<4;i++)//RECORRO DEPARTAMENTOS
    {
        for(j=0;j<u->departamentos[i]->cantidadCarreras;j++)//RECORRO CARRERAS
        {
            for(k=0;k<u->departamentos[i]->carreras[j]->cantidadMaterias;k++)//RECORRO MATIERIAS
            {
                for(l=0;l<u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes;j++) //RECORRO ESTUDIANTES
                {
                    EstOrde[contador]=u->departamentos[i]->carreras[j]->materias[k]->estudiantes[l];
                    contador=contador+1;
                }
            }
        }
    }
    char dato[30];
    int comprobar=0;
    printf("\nIngrese el apéllido del estudiante que este buscando:\n");
    scanf("%s",dato);
    for(i=0;i<contador;i++)
    {
        int res=strcmp(dato,EstOrde[i]->apellido);
        if(res==0)
        {
            comprobar=1;
            mostrarEstudiante(EstOrde[i]);
        }
    }
    if(comprobar==0)
    {
        printf("No se a allado alumno con ese apellido ingresado.\n");
    }
}
void buscadorEstudianteDni(Universidad u)
{
    Estudiante EstOrde[400];
    Estudiante aux;
    int contador=0;
    system("pause");
    int i,j,k,l;
    for(i=0;i<4;i++)//RECORRO DEPARTAMENTOS
    {
        for(j=0;j<u->departamentos[i]->cantidadCarreras;j++)//RECORRO CARRERAS
        {
            for(k=0;k<u->departamentos[i]->carreras[j]->cantidadMaterias;k++)//RECORRO MATIERIAS
            {
                for(l=0;l<u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes;j++) //RECORRO ESTUDIANTES
                {
                    EstOrde[contador]=u->departamentos[i]->carreras[j]->materias[k]->estudiantes[l];
                    contador=contador+1;
                }
            }
        }
    }
    int dato;
    int comprobar=0;
    printf("\nIngrese el DNI del estudiante que este buscando:\n");
    scanf("%d",&dato);
    for(i=0;i<contador;i++)
    {
        if(EstOrde[i]->dni==dato)
        {
            comprobar=1;
            mostrarEstudiante(EstOrde[i]);
        }
    }
    if(comprobar==0)
    {
        printf("No se a allado alumno con ese DNI ingresado.\n");
    }
}
