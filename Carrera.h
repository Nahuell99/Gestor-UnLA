#ifndef CARRERA_H_INCLUDED
#define CARRERA_H_INCLUDED

struct structCarrera
{
    char nombre[20];
    char titular[20];
    int cantidadMaterias;
    Materia materias[40];
};
typedef struct structCarrera* Carrera;
Carrera crearCarrera();
Carrera crearCarreraAuto(char nombre[20],char titular[20]);
void agregarMateria(Carrera c,Materia m);
void destruirCarrera(Carrera c);
void mostrarCarrera(Carrera c);
char *getNombreC(Carrera c);
char *getTitularC(Carrera c);
void setNombreC(Carrera c, char nombreNuevo[20]);
void setTitularC(Carrera c, char titularNueva[20]);

#endif // CARRERA_H_INCLUDED
