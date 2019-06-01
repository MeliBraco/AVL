#include <stdio.h>

/*
   Con respecto al balanceo la diferencia de altura entre el subArbol derecho
   y el izquierdo es a lo sumo de 1

*/

int alturaArbol(struct arbol *miArbol){

    int alturaizq = 0;

    int alturader = 0;

    if(miArbol == NULL){
        return 0;
    }
    alturaizq = alturaArbol(miArbol->izquierdo);

    alturader = alturaArbol(miArbol->derecho);

    if (alturader > alturaizq)
    {
        return alturader + 1;
    }
    else{
        return alturaizq + 1;
    }
}

int balanceo(struct arbol * miArbol){

    int altura = 0;

    if(miArbol == NULL){

        return 0;
    }

    altura = alturaArbol(miArbol->derecho) - alturaArbol(miArbol->izquierdo);

    return altura;
}

void balancearAVL(struct arbol ** miArbol) {

    int aux = 0;

    //Evalua si el arbol esta vacio
    if(miArbol == NULL){

        return;
    }
    aux = balanceo(*miArbol);

    if(aux > 1){

        if(balanceo((*miArbol)->derecho) >= 1){

            rotarIzquierda(miArbol);
        }
        else{
            rotarDerecha(&((*miArbol)->derecho));

            rotarIzquierda(miArbol);
        }
    }
    else if(aux < -1){

        if(balanceo((*miArbol)->izquierdo) <= -1){

            rotarDerecha(miArbol);
        }
        else{
            rotarIzquierda(&((*miArbol)->izquierdo));

            rotarDerecha(miArbol);
        }
    }
}

int rotarDerecha(struct arbol ** miArbol){

    struct arbol *auxiliar = NULL;

    struct arbol *raiz = NULL;

    struct arbol *raiz_nueva = NULL;

    if(miArbol == NULL){

        return 0;
    }
    raiz = (*miArbol);

    raiz_nueva = (*miArbol) -> izquierdo;

    auxiliar = (*miArbol) -> izquierdo -> derecho;

    (*miArbol) = raiz_nueva;

    raiz_nueva -> derecho = raiz;

    raiz -> izquierdo = auxiliar;

    return 1;
}

int rotarIzquierda(struct arbol ** miArbol){

    struct arbol *auxiliar = NULL;

    struct arbol *raiz = NULL;

    struct arbol *raiz_nueva = NULL;

    if(miArbol == NULL){

        return 0;
    }
    raiz = * miArbol;

    raiz_nueva = (* miArbol) -> derecho;

    auxiliar = (* miArbol) -> derecho -> izquierdo;

    * miArbol = raiz_nueva;

    (* miArbol) -> izquierdo = raiz;

    raiz -> derecho = auxiliar;

    return 1;
}