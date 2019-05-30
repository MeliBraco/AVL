#include <stdio.h>
#include <stdlib.h>
#include "Default.h"
#include "BalancearArbol.c"

int insertar(struct arbol **miArbol, int dato) {

    //evaluo si esta vacio

    if (*miArbol == NULL) {
        //reservo espacio de mememoria correspondiente al tipo de estructura

        *miArbol = (struct arbol *) malloc(sizeof(struct arbol));

        if (*miArbol == NULL) {

            return 0;
        }
        (*miArbol)->dato = dato;

        (*miArbol)->izquierdo = NULL;

        (*miArbol)->derecho = NULL;
    } else {

        //inserto el dato de manera recursiva, quedandome con un sub arbol

        if ((*miArbol)->dato < dato) {

            insertar(&((*miArbol)->derecho), dato);
        } else {
            insertar(&((*miArbol)->izquierdo), dato);
        }
    }
    return 1;
}

int buscar(struct arbol *MiArbol, int dato) {

    //Devuelve uno si existe el dato, en caso contrario devuelve 0

    if (MiArbol == NULL) {

        return 0;
    }
    if (MiArbol->dato == dato) {

        return 1;
    }
    if (MiArbol->dato < dato) {

        return buscar(MiArbol->derecho, dato);
    } else {
        return buscar(MiArbol->izquierdo, dato);
    }
}

int eliminar(struct arbol **miArbol, int dato) {

    struct arbol **aux = NULL;

    if (miArbol == NULL) {
        return 0;
    }

    if ((*miArbol)->dato == dato) {

        if ((*miArbol)->derecho == NULL) {

            (*miArbol) = (*miArbol)->izquierdo;

            //metodo balancear luego de eliminar

        } else if ((*miArbol)->izquierdo == NULL) {

            (*miArbol) = (*miArbol)->derecho;

            //metodo balancear luego de eliminar
        } else {
            aux = miArbol;

            //metodo balancear luego de eliminar
        }
    } else if ((*miArbol)->dato < dato) {

        if ((*miArbol)->derecho == NULL) {
            return 0;
        }
        return eliminar(&((*miArbol)->derecho), dato);

    } else {
        if ((*miArbol)->izquierdo == NULL) {

            return 0;
        }
        return eliminar(&((*miArbol)->izquierdo), dato);
    }

    return 1;
}


void recorrerPre(struct arbol *miArbol) {

    //metodo para recorrer el arbol en pre-order: visitar raiz->izq->der

    if (miArbol != NULL) {

        printf(" \t%d ", miArbol->dato);

        recorrerPre(miArbol->izquierdo);

        recorrerPre(miArbol->derecho);
    }
}

void recorrerPos(struct arbol *miArbol) {

    //metodo para recorrer el arbol en pos-order: visitar izq->der->raiz

    if (miArbol != NULL) {

        recorrerPos(miArbol->izquierdo);

        recorrerPos(miArbol->derecho);

        printf(" \t%d ", miArbol->dato);
    }
}

void recorrerIn(struct arbol *miArbol) {

    //metodo para recorrer el arbol en in-order: visitar izq->raiz->der

    if (miArbol != NULL) {
        recorrerIn(miArbol->izquierdo);

        printf(" \t%d ", miArbol->dato);

        recorrerIn(miArbol->derecho);
    }
}



