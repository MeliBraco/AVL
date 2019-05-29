#include <stdio.h>
#include "Arbol.c"

int main() {

    struct arbol *un_arbol = NULL;

    insertar(&un_arbol, 4);

    insertar(&un_arbol, 1);

    mostrar(un_arbol);


    return 0;
}

void menu(struct arbol *un_arbol) {

    int opciones;

    int dato;

    do {
        printf("\nMENU"
               "\n1- Agregar nodo"
               "\n2- Eliminar nodo "
               "\n3- Mostrar arbol"
               "\n4- Recorrer el arbol"
               "\n5- Buscar dato"
               "\n6- Salir \n "
               "\nIngrese una Opcion:");

        scanf("%d", &opciones);

        switch (opciones) {

            case 1:

                printf("\nIngrese el valor del dato a agregar: ");

                scanf("%d", &dato);
                //insertar( *un_arbol, dato);
                break;

            case 2:
                //Elimina un dato
                break;

            case 3:
                mostrar(un_arbol);
                break;

            case 4:
                //debe tener para seleccionar la opcion de pre pos o in order y recorrerlo
                break;

            case 5:
                //Estaba en la consigna, no entiendo que tiene que devolver,
                //supongo que mas datos o meta (la pos en el arbol, el nivel de profundidad, si es hoja (ultimo nodo))
                break;

            case 6:

                break;

            default:
                printf("Opcion Incorrecta. \n por favor ingrese un numero del 1 al 6 \n");
        }

    } while (opciones != 6);
}

