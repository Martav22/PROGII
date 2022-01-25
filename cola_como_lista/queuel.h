/*
*Nombre del modulo: queuel.h

*Descripcion: En este modulo se definen las primitivas
de queue como estructura de datos una lista.

*Autor: Marta Vaquerizo

*Fecha: 26/03/2019
*Modulos usados: types.h

*Mejoras pendientes: El programa funciona como se esperaba
*/

#ifndef QUEUEL_H
#define QUEUEL_H
#include "types.h"

typedef struct _Queue Queue;
typedef void (*destroy_element_function_type)(void*);
typedef void *(*copy_element_function_type)(const void*);
typedef int (*print_element_function_type)(FILE *, const void*);
typedef int (*cmp_element_function_type)(const void*, const void*);

/**------------------------------------------------------------------
Inicializa la cola: reserva memoria para ella e inicializa todos sus elementos a NULL.
------------------------------------------------------------------*/
Queue* queue_ini(destroy_element_function_type f1, copy_element_function_type f2, print_element_function_type f3, cmp_element_function_type f4);
/**------------------------------------------------------------------
Libera la cola, liberando todos sus elementos.
------------------------------------------------------------------*/
void queue_destroy(Queue *q);
/**------------------------------------------------------------------
Comprueba si la cola está vacía.
------------------------------------------------------------------*/
Bool queue_isEmpty(const Queue *q);
/**------------------------------------------------------------------
Comprueba si la cola está llena.
------------------------------------------------------------------*/
Bool queue_isFull(const Queue* q);
/**------------------------------------------------------------------
Inserta un nuevo nodo en la cola, reservando memoria nueva para él y haciendo una copia del elemento recibido.
------------------------------------------------------------------*/
Status queue_insert(Queue *q, const void* pElem);
/**------------------------------------------------------------------
Extrae un elemento de la cola. Devuelve directamente el puntero al elemento (no hace copia).
------------------------------------------------------------------*/
void * queue_extract(Queue *q);
/**------------------------------------------------------------------
Devuelve el número de elementos de la cola.
------------------------------------------------------------------*/
int queue_size(const Queue *q);
/**------------------------------------------------------------------
Imprime toda la cola, devolviendo el número de caracteres escritos.
------------------------------------------------------------------*/
int queue_print(FILE *pf, const Queue *q);

#endif /*QUEUE_H*/