#include "listaSimple.h"
#include <string.h>

nodo* inicLista(){
    return NULL;
}

nodo* crearNodo(stPersona dato){
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo){
    if(lista==NULL){
        lista = nuevoNodo;
    }else{
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}

nodo* agregarAlPrincipioPro(nodo *lista, nodo* nuevoNodo){
    nuevoNodo->siguiente = lista;
    lista=nuevoNodo;
    return lista;
}

void agregarAlPrincipioPD(nodo **lista, nodo* nuevoNodo){
    nuevoNodo->siguiente = (*lista);
    (*lista)=nuevoNodo;
}

void muestraNodo(nodo *nodo){
    printf("\n nodo: %p - nodo->siguiente: %p",  nodo, nodo->siguiente);
    muestraUnaPersona(nodo->dato);
}

void muestraLista(nodo* lista){
    nodo* seg = lista;
    while(seg){  /// while(lista!=NULL)
        muestraNodo(seg);
        seg = seg->siguiente;
    }
}

void muestraListaRecursiva(nodo* lista){
    if(lista){
        muestraNodo(lista);
        muestraListaRecursiva(lista->siguiente);
    }
}

int sumaListaRecursivaConFiltro(nodo* lista)
{
    int rta;
    if(!lista){
        rta=0;
    }else if ((atoi(lista->dato.dni) > 18) && (atoi(lista->dato.dni)%2 == 0)){
        rta=lista->dato.edad+sumaListaRecursivaConFiltro(lista->siguiente);
    }

    return rta;
}

nodo* buscarUltimo(nodo* lista){
    nodo* seg = lista;
    while(seg->siguiente!=NULL){
        seg = seg->siguiente;
    }

    return seg;
}

void buscarUltimoPD(nodo** lista){
    nodo* seg = (*lista);
    while(seg->siguiente!=NULL){
        seg = seg->siguiente;
    }
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevo){
    if(lista==NULL){
        lista = nuevo;
    }else{
        nodo* ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevo;
    }
    return lista;
}

nodo* borrarLista(nodo* lista){
    nodo* proximo;
    nodo* seg = lista;
    while(seg){
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
    }
    return seg;
}
/*
nodo* agregarEnOrdenDNI(nodo* lista, nodo* nuevo){
    if(lista==NULL){
        lista=nuevo;
    }else{
        if(atoi(nuevo->dato.persona.dni)<atoi(lista->dato.persona.dni)){
            lista=agregarAlPrincipio(lista, nuevo);
        }else{
            nodo* ante = lista;
            nodo* seg = lista->siguiente;
            while(seg && (atoi(nuevo->dato.persona.dni)>atoi(seg->dato.persona.dni))){
                ante = seg;
                seg = seg->siguiente;
            }
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }
    return lista;
}

nodo* borrarNodo(nodo* lista, char apellido[]){
    nodo* seg;
    nodo* ante;
    if(lista && strcmp(lista->dato.persona.apellido, apellido)==0){
        nodo* aux = lista;
        lista = lista->siguiente;
        free(aux);
    }else{
        seg = lista;
        while(seg && strcmp(lista->dato.persona.apellido, apellido)!=0){
            ante = seg;
            seg = seg->siguiente;
        }
        if(seg){
            ante->siguiente = seg->siguiente;
            free(seg);
        }
    }
    return lista;
}
*/
nodo* eliminarUltimoNodo(nodo* lista){
    nodo* aux = lista;
    nodo* ante;
    while(aux->siguiente){    /// es igual a while(aux->siguiente != NULL)
        ante = aux;
        aux=aux->siguiente;
    }
    free(aux);
    ante->siguiente=NULL;
    return lista;
}

nodo* eliminarPrimerNodo(nodo* lista){
    nodo* aux=lista;
    lista=lista->siguiente;
    free(aux);
    return lista;
}

int cuentaLista(nodo* lista){
    nodo* seg=lista;
    int cont=0;
    while(seg){
        cont++;
        seg = seg->siguiente;
    }
    return cont;
}

stPersona verPrimero(nodo* lista){
    return lista->dato;
}

nodo* agregarEnOrdenApellido(nodo* lista, nodo* nuevo){
    if(lista==NULL){
        lista=nuevo;
    }else{
        if(strcmpi(lista->dato.apellido, nuevo->dato.apellido)>0){
            lista=agregarAlPrincipio(lista, nuevo);
        }else{
            nodo* ante = lista;
            nodo* seg = lista->siguiente;
            while(seg && (strcmpi(lista->dato.apellido, nuevo->dato.apellido)<0)){
                ante = seg;
                seg = seg->siguiente;
            }
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }
    return lista;
}
