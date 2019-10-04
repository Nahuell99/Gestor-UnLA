#ifndef DEPARTAMENTO_H_INCLUDED
#define DEPARTAMENTO_H_INCLUDED

struct structDepartamento
{
    char nombre[60];
    char titular[20];
    int cantidadCarreras;
    Carrera carreras[10];
};
typedef struct structDepartamento* Departamento;
Departamento crearDepartamentos(int i);
Departamento agregarCarrera(Departamento d);
void destruirDepartamento(Departamento d);
void mostrarDepartamento(Departamento d);
char *getNombreD(Departamento d);
char *getTitularD(Departamento d);
void setNombreD(Departamento d,char nombreNuevo[20]);
void setTitularD(Departamento d,char titularNueva[20]);


#endif // DEPARTAMENTO_H_INCLUDED
