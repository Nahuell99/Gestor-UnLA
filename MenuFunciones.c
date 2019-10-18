#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "MenuFunciones.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "Materia.h"
#include "Carrera.h"
#include "Departamento.h"
#include "Universidad.h"

void bienvenida(Universidad u);
void opciones5(Universidad u);
void opciones6(Universidad u);

void menuEstudiante(Universidad u);
void menuListadoEstudiantes(Universidad u);
void mostrarEstudianteTodos(Universidad u);
void mostrarEstudianteNom(Universidad u);
void mostrarEstudianteApe(Universidad u);
void mostrarEstudianteDni(Universidad u);
void menuBuscadorEstudiante(Universidad u);
void buscadorEstudianteNom(Universidad u);
void buscadorEstudianteApe(Universidad u);
void buscadorEstudianteDni(Universidad u);

Universidad menuCargarEstudiante(Universidad u);

Universidad menuDepartamento(Universidad u);

void bienvenida(Universidad u)
{
    printf("***************************************************************************************************\n");
    printf("****************************Bienvenido al Sistema de Gestios de la Unla****************************\n");
    printf("***************************************************************************************************");
    mostrarUniversidad(u);
}
void opciones1()
{
    printf("***************************************************************************************************\n");
    printf("*****************************--Opciones para gestionar/administrar--*******************************\n");
    printf("***********************************************UnLA************************************************");
    printf("\n A continuacion seleccione un numero correspondiente a la seccion:\n\n");
    printf("  1- Gestionar Estudiantes.\n");
    printf("  2- Cargar Estudiantes.\n");
    printf("  3- Gestion por Departamentos.\n");
    printf("  0- Cerrar programa\n\n");
    printf(" Opcion: ");
}
void opciones2()
{
    system("cls");
    printf("***************************************************************************************************\n");
    printf("************************************CATEGORIA ESTUDIANTES******************************************\n");
    printf("***************************************************************************************************");
    printf("\n A continuacion seleccione un numero correspondiente a la seccion:\n\n");
    printf("  1- Ver listado de estudiantes.\n");
    printf("  2- Buscar estudiante.\n");
    printf("  0- Menu anterior\n\n");
    printf(" Opcion: ");
}
void opciones3()
{
    system("cls");
    printf("***************************************************************************************************\n");
    printf("**************************************CATEGORIA LISTADO********************************************\n");
    printf("***************************************************************************************************");
    printf("\n A continuacion seleccione un numero correspondiente a la seccion:\n\n");
    printf("  1- Ver listado completo.\n");
    printf("  2- Ver ordenado por nombre.\n");
    printf("  3- Ver ordenado por apellido.\n");
    printf("  4- Ver ordenado por DNI.\n");
    printf("  0- Menu anterior\n\n");
    printf(" Opcion: ");
}
void opciones4()
{
    system("cls");
    printf("***************************************************************************************************\n");
    printf("*************************************CATEGORIA BUSQUEDA********************************************\n");
    printf("***************************************************************************************************");
    printf("\n A continuacion seleccione un numero correspondiente a la seccion:\n\n");
    printf("  1- Buscar por nombre.\n");
    printf("  2- Buscar por apellido.\n");
    printf("  3- Buscar por DNI.\n");
    printf("  0- Menu anterior.\n\n");
    printf(" Opcion: ");
}
void opciones5(Universidad u)
{
    system("cls");
    printf("***************************************************************************************************\n");
    printf("***********************************CATEGORIA DEPARTAMENTO******************************************\n");
    printf("***************************************************************************************************");
    printf("\n A continuacion seleccione un numero correspondiente al departamento a gesitonar:\n\n");
    for(int i=0; i<4; i++)
    {
        printf("  %d- ",i);
        mostrarDepartamento(u->departamentos[i]);
    }
    printf("  4- Menu anterior.\n\n");
    printf(" Opcion: ");
}
void opciones6(Universidad u)
{
    system("cls");
    printf("***************************************************************************************************\n");
    printf("*************************************CARGAR ESTUDIANTES********************************************\n");
    printf("***************************************************************************************************");
    printf("\n A continuacion seleccione el departamento al que inscribira el alumno:\n\n");
    for(int i=0; i<4; i++)
    {
        printf("  %d- ",i);
        mostrarDepartamento(u->departamentos[i]);
    }
    printf("  4- Menu anterior.\n\n");
    printf(" Opcion: ");
}
void opciones7(int i)
{
    switch(i)
    {
    case 1:
        printf("***************************************************************************************************\n");
        printf("***********************************CATEGORIA DEPARTAMENTO******************************************\n");
        printf("***************************************************************************************************\n");
        break;
    case 2:
        printf("***************************************************************************************************\n");
        printf("***************************************CARGANDO CARRERA********************************************\n");
        printf("***************************************************************************************************\n");
        break;
    case 3:
        printf("***************************************************************************************************\n");
        printf("**************************************CARGANDO MATERIA*********************************************\n");
        printf("***************************************************************************************************\n");
        break;
    case 4:
        printf("***************************************************************************************************\n");
        printf("*************************************CARGANDO PROFESOR*********************************************\n");
        printf("***************************************************************************************************\n");
        break;
    case 5:
        printf("***************************************************************************************************\n");
        printf("**************************************CATEGORIA MATERIA********************************************\n");
        printf("***************************************************************************************************\n");
        break;
    case 6:
        printf("***************************************************************************************************\n");
        printf("**************************************CATEGORIA CARRERA********************************************\n");
        printf("***************************************************************************************************\n");
        break;
    case 7:
        printf("***************************************************************************************************\n");
        printf("**************************************CARGANDO ESTUDIANTE******************************************\n");
        printf("***************************************************************************************************\n");
        break;
    }
}
int comprobador()
{
    int cod;
    while(!scanf("%d",&cod))
    {
        fflush(stdin);
        printf("Ah ingresado una letra, debe ingresar un numero. \n");
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
            menuBuscadorEstudiante(u);
            break;
        case 0://MENU ANTERIOR
            a=1;
            system("cls");
            break;
        default:
            printf("Opcion incorrecta.");
            Sleep(1400);
            system("cls");
            break;
        }
    }
}   //MENU ESTUDIANTE 1
void menuListadoEstudiantes(Universidad u)
{
    int a=0;
    while(a==0)//MENU LISTADO DE ESTUDIANTES 1.1
    {
        opciones3();
        int cod=comprobador();
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
            break;
        default:
            printf("Opcion incorrecta.");
            Sleep(1400);
            system("cls");
            break;
        }
    }
}
void mostrarEstudianteTodos(Universidad u)
{
    for(int i=0; i<4; i++) //RECORRE LOS 4 DEPARTAMENTOS
    {
        if(u->departamentos[i]->cantidadCarreras>0)//PREGUNTA SI SE CARRGO POR LO MENOS UNA CARRERA (CARRERA?)
        {
            for(int j=0; j<u->departamentos[i]->cantidadCarreras; j++) //SI SE CREO LAS RECORRO (CARRERA )
            {
                if(u->departamentos[i]->carreras[j]->cantidadMaterias>0)//PREGUNTO SI SE CREO POR LO MENOS UNA MATERIA A LA CARRERA (MATERIA?)
                {
                    for(int k=0; k<u->departamentos[i]->carreras[j]->cantidadMaterias; k++) //SI SE CREO LA RECORRO (MATERIA )
                    {
                        if(u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes>0)//PREGUNTO SI LA CARRERA TIENE ALUMNOS INSCRIPTOS
                        {
                            printf("Nombre Aprellido DNI edad\n");
                            for(int l=0; l<u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes; l++)//SI LOS TIENE RECORRO (ALUMNOS)
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
    for(int i=0; i<4; i++) //RECORRO DEPARTAMENTOS
    {
        if(u->departamentos[i]->cantidadCarreras>0)//¿HAY CARRERAS CARGADAS?
        {
            for(int j=0; j<u->departamentos[i]->cantidadCarreras; j++) //RECORRO CARRERAS
            {
                if(u->departamentos[i]->carreras[j]->cantidadMaterias>0)//¿HAY MATERIAS CARGADAS?
                {
                    for(int k=0; k<u->departamentos[i]->carreras[j]->cantidadMaterias; k++) //RECORRO MATIERIAS
                    {
                        if(u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes>0)//¿HAY ESTUDIANTES?
                        {
                            for(int l=0; l<u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes; l++) //RECORRO ESTUDIANTES
                            {
                                EstOrde[contador]=u->departamentos[i]->carreras[j]->materias[k]->estudiantes[l];
                                contador=contador+1;
                            }
                        }
                    }
                }
            }
        }
    }
    int a=0;
    while(a==0)
    {
        a=1;
        for(int i=0; i<contador-1; i++)
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
    for(int i=0; i<contador; i++)
    {
        mostrarEstudiante(EstOrde[i]);
    }
    system("pause");
}
void mostrarEstudianteApe(Universidad u)
{
    Estudiante EstOrde[400];
    Estudiante aux;
    int contador=0;
    for(int i=0; i<4; i++) //RECORRO DEPARTAMENTOS
    {
        if(u->departamentos[i]->cantidadCarreras>0)//¿HAY CARRERAS CARGADAS?
        {
            for(int j=0; j<u->departamentos[i]->cantidadCarreras; j++) //RECORRO CARRERAS
            {
                if(u->departamentos[i]->carreras[j]->cantidadMaterias>0)//¿HAY MATERIAS CARGADAS?
                {
                    for(int k=0; k<u->departamentos[i]->carreras[j]->cantidadMaterias; k++) //RECORRO MATIERIAS
                    {
                        if(u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes>0)//¿HAY ESTUDIANTES?
                        {
                            for(int l=0; l<u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes; l++) //RECORRO ESTUDIANTES
                            {
                                EstOrde[contador]=u->departamentos[i]->carreras[j]->materias[k]->estudiantes[l];
                                contador=contador+1;
                            }
                        }
                    }
                }
            }
        }
    }
    int a=0;
    while(a==0)
    {
        a=1;
        for(int i=0; i<contador-1; i++)
        {
            int res=strcmp(EstOrde[i]->apellido,EstOrde[i+1]->apellido);
            if(res>0)
            {
                a=0;
                aux=EstOrde[i];
                EstOrde[i]=EstOrde[i+1];
                EstOrde[i+1]=aux;
            }
        }
    }
    for(int i=0; i<contador; i++)
    {
        mostrarEstudiante(EstOrde[i]);
    }
    system("pause");
}
void mostrarEstudianteDni(Universidad u)
{
    Estudiante EstOrde[400];
    Estudiante aux;
    int contador=0;
    for(int i=0; i<4; i++) //RECORRO DEPARTAMENTOS
    {
        if(u->departamentos[i]->cantidadCarreras>0)//¿HAY CARRERAS CARGADAS?
        {
            for(int j=0; j<u->departamentos[i]->cantidadCarreras; j++) //RECORRO CARRERAS
            {
                if(u->departamentos[i]->carreras[j]->cantidadMaterias>0)//¿HAY MATERIAS CARGADAS?
                {
                    for(int k=0; k<u->departamentos[i]->carreras[j]->cantidadMaterias; k++) //RECORRO MATIERIAS
                    {
                        if(u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes>0)//¿HAY ESTUDIANTES?
                        {
                            for(int l=0; l<u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes; l++) //RECORRO ESTUDIANTES
                            {
                                EstOrde[contador]=u->departamentos[i]->carreras[j]->materias[k]->estudiantes[l];
                                contador=contador+1;
                            }
                        }
                    }
                }
            }
        }
    }
    int a=0;
    while(a==0)
    {
        a=1;
        for(int i=0; i<contador-1; i++)
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
    for(int i=0; i<contador; i++)
    {
        mostrarEstudiante(EstOrde[i]);
    }
    system("pause");
}
void menuBuscadorEstudiante(Universidad u)
{
    int a=0;
    while(a==0)//MENU BUSCADOR
    {
        opciones4();
        int cod=comprobador();
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
            break;
        default:
            printf("Opcion incorrecta.");
            Sleep(1400);
            system("cls");
            break;
        }
    }
}
Universidad menuCargarEstudiante(Universidad u)
{
    int depar;
    opciones6(u);
    depar=comprobador();
    //SELECCIONAS CARRERA
    if(depar<4)
    {
            if(u->departamentos[depar]->cantidadCarreras>0)
        {
            system("cls");
            opciones7(7);
            printf(" Seleccione a que carrera desea asignarlo:\n");
            int car=0;
            for(int i=0; i<u->departamentos[depar]->cantidadCarreras; i++)
            {
                printf("  %d- ",i);
                mostrarCarrera(u->departamentos[depar]->carreras[i]);
            }
            printf("  %d- Cancelar carga.\n\n",u->departamentos[depar]->cantidadCarreras);
            printf(" Opcion: ");
            car=comprobador();
            if(car<u->departamentos[depar]->cantidadCarreras)
            {
                if(u->departamentos[depar]->carreras[car]->cantidadMaterias>0)
                {
                    //SELECCIONAS MATERIA
                    printf("seleccione a que materia va a inscribirlo:\n");
                    int mate=0;
                    for(int j=0; j<u->departamentos[depar]->carreras[car]->cantidadMaterias; j++)
                    {
                        printf("%d-",j);
                        mostrarMateria(u->departamentos[depar]->carreras[car]->materias[j]);
                    }
                    scanf("%d",&mate);
                    //A LO ELEGIDO LE AGREGO UN ALUMNO
                    agregarEstudiante(u->departamentos[depar]->carreras[car]->materias[mate], cargarEstudianteTeclado() );
                }
                else
                {
                    printf(" No hay ninguna materia cargada en esta carrera.\n");
                    printf(" Ingrese en la opcion 3 del menu principal y agrege una carrera al departamento.\n");
                    system("pause");
                }
            }
            system("cls");

        }
        else
        {
            printf(" No hay ninguna carreca cargada en este departamento.\n");
            system("pause");
            system("cls");
        }
    }
    system("cls");
    return u;
}
Universidad menuDepartamento(Universidad u)
{
    int depar=0;
    while(depar!=4)
    {
        opciones5(u);
        depar=comprobador();//SELECCIONAS DEPARTAMENTO A GESTIONAR
        if(depar<4)
        {
            if(u->departamentos[depar]->cantidadCarreras>0) //EN CASO DE QUE EL DEPARTAMENTO TENGA CARRERAS ASIGNADAS
            {
                system("cls");
                opciones7(1);
                printf("\n Digite la opcion que sea realizar:\n\n");
                for(int i=0; i<u->departamentos[depar]->cantidadCarreras; i++) //MUESTRO QUE CARRERAS TIENE ASIGNADAS
                {
                    printf("  %d- ",i);
                    mostrarCarrera(u->departamentos[depar]->carreras[i]);
                }
                printf("  %d- Cargar nueva carrera\n\n",u->departamentos[depar]->cantidadCarreras); //Y CREO UNA CATEGORIA MAS PARA AGREGAR CARRERA
                printf(" Opcion: ");
                int car;
                car=comprobador();
                if(car<u->departamentos[depar]->cantidadCarreras)//SI SE ELIGE UNA CARRERA SE GESTIONA ESA
                {
                    if(u->departamentos[depar]->carreras[car]->cantidadMaterias>0)//PREGUNTAR SI LA CARRERA TIENE MATERIAS
                    {
                        system("cls");
                        opciones7(6);
                        printf("\n Carrera: %s\n",u->departamentos[depar]->carreras[car]->nombre);
                        printf(" Digite la opcion que sea realizar\n\n");
                        for(int i=0; i<u->departamentos[depar]->carreras[car]->cantidadMaterias; i++) //EB CAASO DE TENER MATERIAS LAS MUESTRO
                        {
                            printf("  %d- ",i);
                            mostrarMateria(u->departamentos[depar]->carreras[car]->materias[i]);
                        }
                        printf("  %d- Cargar nueva materia.\n",u->departamentos[depar]->carreras[car]->cantidadMaterias);
                        printf("  %d- Modificar datos de carrera.\n\n",u->departamentos[depar]->carreras[car]->cantidadMaterias+1);
                        printf(" Opcion: ");
                        int mate;
                        scanf("%d",&mate);//DOGITO ENTRE UNA MATERIA O AGREGAR UNA NUEVA
                        if(mate<u->departamentos[depar]->carreras[car]->cantidadMaterias)//SI SE ELIGIO UNA MATERIA SE LA GESTIONA
                        {
                            system("cls");
                            opciones7(5);
                            printf("\n Carrera: %s",u->departamentos[depar]->carreras[car]->materias[mate]->nombre);
                            printf("\n Alumnos cursando %s: %d\n",u->departamentos[depar]->carreras[car]->materias[mate]->nombre,u->departamentos[depar]->carreras[car]->materias[mate]->cantidadEstudiantes);
                            for(int i=0; i<u->departamentos[depar]->carreras[car]->materias[mate]->cantidadEstudiantes; i++)
                            {
                                mostrarEstudiante(u->departamentos[depar]->carreras[car]->materias[mate]->estudiantes[i]);
                            }
                            printf("\n Desea cargar un estudiante a esta materia?\n  1- Si\n  2- No\n\n");
                            printf(" Opcion: ");
                            int opcion;
                            scanf("%d",&opcion);
                            if(opcion==1)
                            {
                                system("cls");
                                opciones7(7);
                                agregarEstudiante(u->departamentos[depar]->carreras[car]->materias[mate], cargarEstudianteTeclado());
                            }
                        }
                        else//SI ELIGE CARGARLE UNA MATERIA MAS LA CARGO
                        {
                            if(mate>u->departamentos[depar]->carreras[car]->cantidadMaterias)//MODIFICAR CARRERA
                            {
                                char aux[30];
                                printf(" Ingresa el nuevo nombre:\n");
                                fflush(stdin);
                                gets(aux);
                                setNombreC(u->departamentos[depar]->carreras[car],aux);
                                printf(" Ingresa el nuevo titular:\n");
                                fflush(stdin);
                                gets(aux);
                                setTitularC(u->departamentos[depar]->carreras[car],aux);
                            }
                            else//AGREGAR MATERIA NUEVA
                            {
                                agregarMateria(u->departamentos[depar]->carreras[car], crearMateria() );
                            }
                        }
                    }
                    else//EN CASO DE QUE NO MUESTRO OPCION PARA CREAR MATERIAS NUEVAS
                    {
                        printf("\n No hay materias cargadas en esta carrera.\n");
                        printf("\n  1- Cargar materia\n  2- Modificar datos de carrera\n  3- Menu departamentos\n\n");
                        printf(" Opcion: ");
                        int opcion;
                        opcion=comprobador();
                        if(opcion==1)
                        {
                            system("cls");
                            opciones7(3);
                            agregarMateria(u->departamentos[depar]->carreras[car], crearMateria() );
                        }
                        else
                        {
                            if(opcion==2)//ESTA OPCION ES PARA MODIFICAR LOS DATOS
                            {
                                char aux[30];
                                printf(" Ingresa el nuevo nombre:\n");
                                fflush(stdin);
                                gets(aux);
                                setNombreC(u->departamentos[depar]->carreras[car],aux);
                                printf(" Ingresa el nuevo titular:\n");
                                fflush(stdin);
                                gets(aux);
                                setTitularC(u->departamentos[depar]->carreras[car],aux);
                            }
                        }
                    }
                }
                else //SI SE ELIGE OTRA OPCION
                {
                    agregarCarrera(u->departamentos[depar], crearCarrera() );
                }

            }
            else //EN CASO DE QUE EL DEPARTAMENTO NOO TENGA CARRERAS ASIGNADAS
            {
                printf("\n No hay carreras cargadas en el %s.\n",u->departamentos[depar]->nombre);
                printf(" Desea cargar una carrera al departamento?\n\n  1- Si\n  2- No\n\n");
                printf(" Opcion: ");
                int opcion;
                opcion=comprobador();
                if(opcion==1)
                {
                    system("cls");
                    opciones7(2);
                    agregarCarrera(u->departamentos[depar], crearCarrera() );
                }
            }
        }
    }
    system("cls");
    return u;
}
void buscadorEstudianteNom(Universidad u)
{
    char dato[30];
    int comprobar=0;
    int res;
    printf("\nIngrese el nombre del estudiante que este buscando:\n");
    fflush(stdin);
    gets(dato);
    for(int i=0; i<4; i++) //RECORRO DEPARTAMENTOS
    {
        if(u->departamentos[i]->cantidadCarreras>0)//¿HAY CARRERAS CARGADAS?
        {
            for(int j=0; j<u->departamentos[i]->cantidadCarreras; j++) //RECORRO CARRERAS
            {
                if(u->departamentos[i]->carreras[j]->cantidadMaterias>0)//¿HAY MATERIAS CARGADAS?
                {
                    for(int k=0; k<u->departamentos[i]->carreras[j]->cantidadMaterias; k++) //RECORRO MATIERIAS
                    {
                        if(u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes>0)//¿HAY ESTUDIANTES?
                        {
                            for(int l=0; l<u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes; l++) //RECORRO ESTUDIANTES
                            {
                                res=strcmp(u->departamentos[i]->carreras[j]->materias[k]->estudiantes[l]->nombre,dato);
                                if(res==0)
                                {
                                    comprobar=1;
                                    mostrarEstudiante(u->departamentos[i]->carreras[j]->materias[k]->estudiantes[l]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(comprobar==0)
    {
        printf("No se a allado alumno con ese nombre ingresado.\n");
        system("pause");
    }
}
void buscadorEstudianteApe(Universidad u)
{
    char dato[30];
    int comprobar=0;
    int res;
    printf("\nIngrese el apellido del estudiante que este buscando:\n");
    fflush(stdin);
    gets(dato);
    for(int i=0; i<4; i++) //RECORRO DEPARTAMENTOS
    {
        if(u->departamentos[i]->cantidadCarreras>0)//¿HAY CARRERAS CARGADAS?
        {
            for(int j=0; j<u->departamentos[i]->cantidadCarreras; j++) //RECORRO CARRERAS
            {
                if(u->departamentos[i]->carreras[j]->cantidadMaterias>0)//¿HAY MATERIAS CARGADAS?
                {
                    for(int k=0; k<u->departamentos[i]->carreras[j]->cantidadMaterias; k++) //RECORRO MATIERIAS
                    {
                        if(u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes>0)//¿HAY ESTUDIANTES?
                        {
                            for(int l=0; l<u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes; l++) //RECORRO ESTUDIANTES
                            {
                                res=strcmp(u->departamentos[i]->carreras[j]->materias[k]->estudiantes[l]->apellido,dato);
                                if(res==0)
                                {
                                    comprobar=1;
                                    mostrarEstudiante(u->departamentos[i]->carreras[j]->materias[k]->estudiantes[l]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(comprobar==0)
    {
        printf("No se a allado alumno con ese apellido ingresado.\n");
        system("pause");
    }
}
void buscadorEstudianteDni(Universidad u)
{
    int dato;
    int comprobar=0;
    int res;
    printf("\nIngrese el dni del estudiante que este buscando:\n");
    fflush(stdin);
    dato=comprobador();
    for(int i=0; i<4; i++) //RECORRO DEPARTAMENTOS
    {
        if(u->departamentos[i]->cantidadCarreras>0)//¿HAY CARRERAS CARGADAS?
        {
            for(int j=0; j<u->departamentos[i]->cantidadCarreras; j++) //RECORRO CARRERAS
            {
                if(u->departamentos[i]->carreras[j]->cantidadMaterias>0)//¿HAY MATERIAS CARGADAS?
                {
                    for(int k=0; k<u->departamentos[i]->carreras[j]->cantidadMaterias; k++) //RECORRO MATIERIAS
                    {
                        if(u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes>0)//¿HAY ESTUDIANTES?
                        {
                            for(int l=0; l<u->departamentos[i]->carreras[j]->materias[k]->cantidadEstudiantes; l++) //RECORRO ESTUDIANTES
                            {
                                if(u->departamentos[i]->carreras[j]->materias[k]->estudiantes[l]->dni==dato)
                                {
                                    comprobar=1;
                                    mostrarEstudiante(u->departamentos[i]->carreras[j]->materias[k]->estudiantes[l]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(comprobar==0)
    {
        printf("No se a allado alumno con ese dni ingresado.\n");
        system("pause");
    }
}
