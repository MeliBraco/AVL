#include <stdio.h>

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