#include <stdio.h>
#include <stdlib.h>

struct arbol{

    int dato;
    struct arbol *izquierdo;
    struct arbol *derecho;
};

int insertar(struct arbol ** , int);

void mostrar(struct arbol *);

int eliminar(struct arbol * , int);

void recorrerPre(struct arbol *);

void recorrerPos(struct arbol *);

void recorrerIn(struct arbol *);

int alturaArbol(struct arbol *);

int buscar(struct arbol *, int);

