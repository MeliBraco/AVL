#include <stdio.h>
#include <stdlib.h>

struct arbol{

    int dato;
    struct arbol *izquierdo;
    struct arbol *derecho;
};

int insertar(struct arbol ** , int);

void mostrar(struct arbol *);

int alturaArbol(struct arbol *);



