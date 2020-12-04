#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "persona.h"

typedef struct _nodo{
    stPersona dato;
    struct _nodo *siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo(stPersona dato);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo);
nodo* agregarAlPrincipioPro(nodo *lista, nodo* nuevoNodo);
void agregarAlPrincipioPD(nodo **lista, nodo* nuevoNodo);
void muestraNodo(nodo *nodo);
void muestraLista(nodo* lista);
void muestraListaRecursiva(nodo* lista);
int sumaListaRecursivaConFiltro(nodo* lista);
nodo* buscarUltimo(nodo* lista);
nodo* agregarAlFinal(nodo* lista, nodo* nuevo);
nodo* borrarLista(nodo* lista);
nodo* agregarEnOrdenDNI(nodo* lista, nodo* nuevo);
nodo* borrarNodo(nodo* lista, char apellido[]);
nodo* eliminarPrimerNodo(nodo* lista);
int cuentaLista(nodo* lista);
stPersona verPrimero(nodo* lista);
nodo* agregarEnOrdenApellido(nodo* lista, nodo* nuevo);

#endif // LISTA_H_INCLUDED
