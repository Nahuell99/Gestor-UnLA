#ifndef PROFESOR_H_INCLUDED
#define PROFESOR_H_INCLUDED

struct structProfesor
{
    char nombre[20];
    char apellido[20];
    int edad;
    int dni;
};
typedef struct structProfesor *Profesor;
Profesor cargarProfesor(char nombreNuevo[20], char apellidoNuevo[20], int dniNuevo, int edadNuevo);
Profesor cargarProfesorTeclado();
void mostrarProfesor(Profesor p);
void destruirProfesor(Profesor p);
char *getNombreP(Profesor p);
char *getApellidoP(Profesor p);
int getDniP(Profesor p);
int getEdadP(Profesor p);
void setNombreP(Profesor p, char nombreNuevo[20]);
void setApellidoP(Profesor p, char apellidoNuevo[20]);
void setDniP(Profesor p, int dniNuevo);
void setEdadP(Profesor p, int edadNuevo);

#endif // PROFESOR_H_INCLUDED
