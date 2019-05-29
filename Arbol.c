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

int buscar(struct arbol *MiArbol, int dato){

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

int buscarMinimo(struct arbol *miArbol){
    if (miArbol->izquierdo != NULL){
        buscarMinimo(miArbol->izquierdo);
    }else{
        return miArbol->dato;
    }

}

struct arbol* eliminar(struct arbol *miArbol, int datoAeliminar) {
    //metodo para eliminar un nodo del arbol, devuelve 0 si no encontro el dato (para lanzar excepcion)
    //me fijo si el arbol esta vacio
    if (miArbol == NULL){
        return miArbol;
        printf("El arbol esta vacio, no hay nada que eliminar");
    }
    //busco recursivamente el dato
    if (miArbol->dato < datoAeliminar){
        miArbol->izquierdo = eliminar(miArbol->izquierdo, datoAeliminar);
    }
    if (miArbol->dato > datoAeliminar) {
        miArbol->derecho = eliminar(miArbol->derecho, datoAeliminar);
    }
    if (miArbol->dato == datoAeliminar){
        //si no tiene hijos
        if (miArbol->izquierdo == NULL && miArbol->derecho == NULL){
            /*
             la funcion free libera la memora de lo que tiene adentro,
             por lo tanto se eliminan sus punteros
             y los punteros que apuntaban al dato ahora van a NULL
             */
            free(miArbol);
        }// Cuando tiene un solo hijo
        if (miArbol->izquierdo == NULL && miArbol->derecho != NULL) {
            miArbol = miArbol->derecho;
        }
        if (miArbol->izquierdo != NULL && miArbol->derecho == NULL) {
            miArbol = miArbol->izquierdo;
        }//Cuando tiene los dos hijos
        if (miArbol->izquierdo != NULL && miArbol->derecho != NULL) {
            int temp = buscarMinimo(miArbol->derecho);
            miArbol->dato = temp;
            eliminar(miArbol->derecho, temp);
        }


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



