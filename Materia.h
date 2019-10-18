#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED

struct structMateria
{
    char nombre[20];
    int cantidadEstudiantes;
    int cantidadProfesor;
    Estudiante estudiantes[50];
    Profesor profesores[2];
};
typedef struct structMateria *Materia;
Materia crearMateria();
Materia cargarMateriaAuto(char nom[20]);
void agregarEstudiante(Materia m, Estudiante e);
void agregarProfesor(Materia m, Profesor p);
void destruirMateria(Materia m);
void mostrarMateria(Materia m);
char *getNombreM(Materia m);
void setNombreM(Materia m, char nombreNuevo[20]);

#endif // MATERIA_H_INCLUDED
