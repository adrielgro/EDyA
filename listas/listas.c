#include <stdio.h>
#include <stdlib.h>

typedef int Item;

struct Elemento
{
    int dato;
    struct Elememento *siguiente;
};

typedef struct Elemento Nodo;

Nodo* crearNodo(Item x)
{
    Nodo *nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = x;
    nuevo->siguiente = NULL;

    return nuevo;
}

Nodo* insertarPrimero(Nodo** cabeza, Item x)
{
    Nodo *nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo -> dato = x;
    nuevo ->siguiente = *cabeza;

    return nuevo;    
}

void inertFinal(Nodo** cabeza, Item entrada)
{
    Nodo *ultimo;
    ultimo = *cabeza;

    if(ultimo == NULL)
    {
        *cabeza = crearNodo(entrada);
    }
    else{
        for(;ultimo->siguiente;){
            ultimo = ultimo->siguiente;
            ultimo->siguiente = crearNodo(entrada);
        }
    }
}

void insertar(Nodo** cabeza, Item testigo, Item entrada){
    Nodo *nuevo, *despues;
    nuevo = crearNodo(entrada);
    if(*cabeza == NULL){
        *cabeza = nuevo;
    }
    else{
        int esta = 0;
        despues = *cabeza;
        while((despues != NULL) && !esta){
            if(despues->dato != testigo){
                despues =despues->siguiente;
            }
            else{
                esta = 1;
            }
        }
        if(esta){
            nuevo->siguiente = despues->siguiente;
            despues ->siguiente = nuevo;
        }
    }
}

Nodo* Localizar(Nodo* cabeza, Item destino){
    Nodo* indice;
    for(indice = cabeza;indice !=NULL;indice =indice->siguiente){
        if(destino == indice->dato){
            return indice;
        }
    }
    return NULL;
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
}