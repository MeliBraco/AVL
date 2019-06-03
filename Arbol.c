#include <stdio.h>
#include <stdlib.h>
#include "Default.h"
#include "BalancearArbol.c"

/*
    AVL Arbol binario balanceado en donde todos sus nodos cumplen con la siguiente
    condidcion: el elemento izquierdo es menor y el elemento derecho es mayor al nodo
    raiz. Partiendolo en subArboles

*/


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

    balancearAVL(miArbol);

    return 1;
}

int buscar(struct arbol *MiArbol, int dato){

    //devuelve  si existe el dato y 0 en caso contrario

    if(MiArbol == NULL){

        return 0;
    }
    if(MiArbol->dato == dato){

        return 1;
    }
    if(MiArbol->dato < dato){

        return buscar(MiArbol->derecho, dato);
    }
    else{
        return buscar(MiArbol->izquierdo, dato);
    }
}

void recorrerPre(struct arbol *miArbol){

    //metodo para recorrer el arbol en pre-order: visitar raiz->izq->der

    if(miArbol !=NULL){

        printf(" \t%d ",miArbol->dato);

        recorrerPre(miArbol->izquierdo);

        recorrerPre(miArbol->derecho);
    }
}

void recorrerPos(struct arbol *miArbol){

    //metodo para recorrer el arbol en pos-order: visitar izq->der->raiz

    if(miArbol !=NULL){

        recorrerPos(miArbol->izquierdo);

        recorrerPos(miArbol->derecho);

        printf(" \t%d ",miArbol->dato);
    }
}

void recorrerIn(struct arbol *miArbol){

    //metodo para recorrer el arbol en in-order: visitar izq->raiz->der

    if(miArbol !=NULL){
        recorrerIn(miArbol->izquierdo);

        printf(" \t%d ",miArbol->dato);

        recorrerIn(miArbol->derecho);
    }
}

int  eliminar ( struct arbol ** miArbol, int dato) {

    struct   arbol ** aux = NULL ;

    if (miArbol == NULL ) {
        printf("No existe el dato en el arbol, no se puede eliminar");
        return  0 ;
    }

    if ((* miArbol) -> dato == dato) {

        if ((* miArbol) -> derecho == NULL ) {
            (* miArbol) = (* miArbol) -> izquierdo ;
            printf("El dato se ha eliminado correctamente");
            balancearAVL (miArbol);
        }
        else  if ((* miArbol) -> izquierdo == NULL ) {
            (* miArbol) = (* miArbol) -> derecho ;
            printf("El dato se ha eliminado correctamente");
            balancearAVL (miArbol);
        }
        else {
            aux = miArbol;

            reordenar (& ((* miArbol) -> izquierdo ), aux);
            printf("El dato se ha eliminado correctamente");
            balancearAVL (& ((* miArbol) -> izquierdo ));
        }
    }
    else  if ((* miArbol) -> dato <dato) {
        if ((* miArbol) -> derecho == NULL ) {
            printf("No existe el dato en el arbol, no se puede eliminar");
            return  0 ;
        }
        return  eliminar (& ((* miArbol) -> derecho ), dato);
    }
    else {
        if ((* miArbol) -> izquierdo == NULL ) {
            printf("No existe el dato en el arbol, no se puede eliminar");
            return  0 ;
        }
        return  eliminar (& ((* miArbol) -> izquierdo ), dato);
    }

    return  1 ;
}

int reordenar(struct arbol **miArbol, struct arbol **aux_arbol) {

    if ((*miArbol)->derecho == NULL){

        (*aux_arbol)->dato = (*miArbol)->dato;

        *miArbol = (*miArbol)->izquierdo;
    }else
        reordenar(&(*miArbol)->derecho, aux_arbol);
    return 1;
}