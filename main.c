#include <stdio.h>
#include "Arbol.c"

void menuRecorrer(struct arbol *un_arbol) {

    int opciones;
    do{
        printf("\n1- Recorrer en Pre-Orden"
               "\n2- Recorrer en In-Orden"
               "\n3- Recorrer en Pos-Orden"
               "\n4- Volver atras");
        scanf("%d", opciones);

        switch(opciones) {
            case 1:
                recorrerPre(un_arbol);
                break;
            case 2:
                recorrerIn(un_arbol);
                break;
            case 3:
                recorrerPos(un_arbol);
                break;
        }
    }while(opciones != 4);

}

void menu(struct arbol *un_arbol) {

    int opciones;

    int dato;

    un_arbol = NULL;

    do {
        printf("\nMENU"
               "\n1- Agregar nodo"
               "\n2- Eliminar nodo "
               "\n3- Recorrer el arbol"
               "\n4- Buscar dato"
               "\n5- Demo"
               "\n6- Salir \n "
               "\nIngrese una Opcion:");

        scanf("%d", &opciones);

        switch (opciones) {

            case 1:

                printf("\nIngrese el valor del dato a agregar: ");

                scanf("%d", &dato);
                insertar( &un_arbol, dato);
                //printf("%d insertado correctamente", dato);

                break;

            case 2:
                //Elimina un dato
                //eliminar( &un_arbol, dato);
                break;

            case 3:;
                menuRecorrer(un_arbol);
                break;
            case 4:
                printf("\nIngrese el dato a buscar:");
                scanf("%d", dato);
                buscar(un_arbol, dato);
                break;

            case 5:
                //modo demo
                insertar(&un_arbol, 12);
                insertar(&un_arbol, 7);
                insertar(&un_arbol, 21);
                insertar(&un_arbol, 2);
                insertar(&un_arbol, 9);
                insertar(&un_arbol, 99);
                insertar(&un_arbol, 13);
                printf("Recorre en Pre-Orden");
                recorrerPre(un_arbol);
                printf("\n");
                printf("Recorre en In-Orden");
                recorrerIn(un_arbol);
                printf("\n");
                printf("Recorre en Pos-Orden");
                recorrerPos(un_arbol);
                break;

            case 6:

                break;

            default:
                printf("Opcion Incorrecta. \n por favor ingrese un numero del 1 al 6 \n");
        }

    } while (opciones != 6);
}

int main() {

    struct arbol *un_arbol = NULL;

    menu(un_arbol);

    return 0;
}
