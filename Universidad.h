#ifndef UNIVERSIDAD_H_INCLUDED
#define UNIVERSIDAD_H_INCLUDED

struct structUniversidad;
struct structUniversidad
{
    char nombre[30];
    char fundacion[30];
    char rector[20];
    Departamento departamentos[4];
};
typedef struct structUniversidad* Universidad;
Universidad crearUniversidad();
void mostrarUniversidad(Universidad u);
char *getNombreU(Universidad u);
char *getDireccionU(Universidad u);
char *getRectorU(Universidad u);

#endif // UNIVERSIDAD_H_INCLUDED
