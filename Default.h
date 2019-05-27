#include <stdio.h>
#include <stdlib.h>

struct arbol{

    int dato;
    struct arbol *izquierdo;
    struct arbol *derecho;
};

//predefino los metodos que voy a utilizar

int insertar(struct arbol ** , int);

void mostrar(struct arbol *);
