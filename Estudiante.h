#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED

struct structEstudiante
{
    char nombre[20];
    char apellido[20];
    int dni;
    int edad;
    int cod;
};
typedef struct structEstudiante* Estudiante;
Estudiante cargarEstudiante(char nombreNuevo[20], char apellidoNuevo[20], int dniNuevo, int edadNuevo);
Estudiante cargarEstudianteTeclado();
void mostrarEstudiante(Estudiante e);
void destruirEstudiante(Estudiante e);
char *getNombreE(Estudiante e);
char *getApellidoE(Estudiante e);
int getDniE(Estudiante e);
int getEdadE(Estudiante e);
void setNombreE(Estudiante e, char nombreNuevo[20]);
void setApellidoE(Estudiante e, char apellidoNuevo[20]);
void setDniE(Estudiante e, int dniNuevo);
void setEdadE(Estudiante e, int edadNuevo);

#endif // ESTUDIANTE_H_INCLUDED
