#include <stdio.h>
#include <stdlib.h>
#include "Default.h"
#include "BalancearArbol.c"

int insertar(struct arbol **miArbol, int dato){

    //evaluo si esta vacio

    if(*miArbol == NULL)
    {
        //reservo espacio de mememoria correspondiente al tipo de estructura

        *miArbol = (struct arbol *)malloc(sizeof(struct arbol));

        if(*miArbol == NULL){

            return 0;
    }
        (*miArbol)->dato = dato;

        (*miArbol)->izquierdo = NULL;

        (*miArbol)->derecho = NULL;
    }
    else{

        //inserto el dato de manera recursiva, quedandome con un sub arbol

        if((*miArbol)->dato < dato){

            insertar(&((*miArbol)->derecho), dato);
        }
        else{
            insertar(&((*miArbol)->izquierdo), dato);
        }
    }

    return 1;
}

void eliminar(struct arbol *miArbol, int dato) {
    //metodo para eliminar un nodo del arbol
}

void recorrerPre(struct arbol *miArbol){
    //metodo para recorrer el arbol en pre-order
}

void recorrerPos(struct arbol *miArbol){
    //metodo para recorrer el arbol en pos-order
}

void recorrerIn(struct arbol *miArbol){
    //metodo para recorrer el arbol en in-order
}

void buscar(struct arbol *miArbol, int dato){
    //tiene que buscar un dato en el arbol
}

void mostrar(struct arbol *miArbol) {
    //muestro el dato de manera recursiva
    if(miArbol == NULL){

        return;
    }
    printf(" \t%d ", miArbol->dato);

    mostrar(miArbol->derecho);

    mostrar(miArbol->izquierdo);
}
