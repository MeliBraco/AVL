#include <stdio.h>
#include "Arbol.c"

int main(){

    struct arbol *un_arbol = NULL;

    insertar(&un_arbol , 4);

    insertar(&un_arbol , 1);

    mostrar(un_arbol);

    return 0;
}
