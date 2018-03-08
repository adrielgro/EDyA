#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 99

typedef int Item;
typedef struct Elemento{
    Item dato;
    struct Elmento *siguiente;
}Nodo;

void insertarPrimero(Nodo** cabeza,Item entrada);
Nodo* crearNodo(Item x);

void main(){
    Item d;
    Nodo *cabeza, *ptr;
    int k;

    cabeza = NULL;
    srand(time(NULL));
    /*Ciclo termina cuando tengo 0*/
    for(d = rand()%MX; d ;){
        insertarPrimero(&cabeza,d);
        d = rand()%MX;
    }    

    /*Se recore la lista*/

    for (k=0, ptr = cabeza; ptr; ){
        if(ptr-> dato%2 == 0){
            printf("-%d ",ptr->dato);
            k++;
            printf("%c",(k%12 ?  ' ':'\n'));
        }
        ptr = ptr->siguiente;
    }
    printf("\n\n");
}


Nodo* crearNodo(Item x)
{
    Nodo *p;
    p= (Nodo*)malloc(sizeof(Nodo));
    p->dato = x;
    p->siguiente = NULL;
    return p;
}

void insertarPrimero(Nodo** cabeza, Item x)
{
    Nodo *nuevo;
    nuevo = crearNodo(x);
    nuevo ->siguiente = *cabeza;
    *cabeza = nuevo;
}

