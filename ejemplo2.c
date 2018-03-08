#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 101

typedef int Item;
typedef struct Elemento
{
    Item dato;
    struct Elemento *siguiente;
}Nodo;

void insertaOrden(Nodo** cabeza, Item entrada);
Nodo* crearNodo(Item x);
void recorrer(Nodo* cabeza);
void eliminar(Nodo** cabeza,Item entrada);

void main()
{
    Item d;
    Nodo* cabeza;

    cabeza = NULL;
    srand(time(NULL));
    for(d = rand()%MX; d; )
    {
        insertaOrden(&cabeza,d);
        d = rand()%MX;
    }

    recorrer(cabeza);

    printf("\n Elemento a eliminar: ");
    scanf("%d",&d);
    eliminar(&cabeza,d);
    recorrer(cabeza);
}

void insertaOrden(Nodo** cabeza,Item entrada)
{
    Nodo *nuevo;
    nuevo = crearNodo(entrada);
    nuevo ->siguiente = *cabeza;
    *cabeza = nuevo;
}

Nodo* crearNodo(Item entrada)
{
    Nodo *p;
    p= (Nodo*)malloc(sizeof(Nodo));
    p->dato = entrada;
    p->siguiente = NULL;
    return p;
}

void recorrer(Nodo* cabeza){
    int k;
    printf("\n\t\t Lista Ordenada \n");
    for(k=0;cabeza;cabeza = cabeza->siguiente)
    {
        printf("%d ",cabeza->dato);
        k++;
        printf("%c",(k%12 ?  ' ':'\n'));
    }
    printf("\n\n");
}

void eliminar(Nodo** cabeza,Item entrada){
    Nodo* actual,*anterior;
    int encontrado;

    actual = *cabeza;
    anterior = NULL;

    while((actual!=NULL) && !encontrado){
        encontrado = (actual->dato == entrada);
        if(!encontrado){
            anterior = actual;
            actual = actual->siguiente;
        }
    }

    if(actual != NULL){
        if(actual == *cabeza){
            *cabeza = actual ->siguiente;
        }
        else{
            anterior->siguiente = actual->siguiente;
        }
        free(actual);
    }
    else
    {
        puts("Nodo no eliminado, elemento no esta en la lista \n");
    }
}