#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo {
   int valor;
   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

// Funciones con listas:
void Insertar(Lista *, int);
void Borrar(Lista *, int);
void BorrarLista(Lista *);
void MostrarLista(Lista);
void Algoritmo(int);

Lista lista = NULL;
    
int main () 
{
    int n=0, op=-1;
    
    do
    {
        printf("\t\tALGORITMO DE JOSEFO - Listas circulares\n\n");    
        printf("cuantos soldados desea agregar?: ");
        scanf("%d", &n);
        
        Algoritmo(n);
        
        printf("\nsi desea salir oprima cero (0), sino oprima 1... ");
        scanf("%d", &op);
        system("CLS");
    }
    while (op!=0);
    return 0;
}

void Algoritmo (int n)
{
    int t=0, x1=0;
    pNodo nodo;
        
    for (int i=1; i<=n; i++)
    {    
        x1=rand()% 50;
        Insertar(&lista, x1);    
    }

    printf("Lista: ");
    MostrarLista(lista);
//    t=rand()% 50;
//    printf("\nSe va a contar en redondo hasta %d \n",x);
    
    while ((lista)->siguiente != lista)//Mientras que haya más de un elemento
    {
        nodo=lista;
        
        for (int x=1; x<x1; x++)
            nodo = nodo->siguiente; //nodo va a ser igual al elemento que hay que eliminiar
        
        printf("\n\nMurio el soldado numero %d \n", nodo->valor);
        Borrar(&lista, nodo->valor);
        printf("En la ronda ya solo quedan: ");
        MostrarLista(lista);        
    }
    printf("\n\nSobrevivio el soldado numero %d\n", lista->valor);
}

void Insertar(Lista *lista, int v)
{
    pNodo nodo;
    
    // Creamos un nodo para el nuvo valor a insertar
    nodo = (pNodo)malloc(sizeof(tipoNodo));
    nodo->valor = v;
    
    // Si la lista está vacía, la lista será el nuevo nodo
    // Si no lo está, insertamos el nuevo nodo a continuación del apuntado
    // por lista
    if(*lista == NULL)
        *lista = nodo;
    else 
        nodo->siguiente = (*lista)->siguiente;
    // En cualquier caso, cerramos la lista circular
    (*lista)->siguiente = nodo;
}

void Borrar(Lista *lista, int v) 
{
   pNodo nodo;
   nodo = *lista;

   // Hacer que lista apunte al nodo anterior al de valor v
   do 
   {
    if((*lista)->siguiente->valor != v)
        *lista = (*lista)->siguiente;
   }
   while ((*lista)->siguiente->valor != v && *lista != nodo);
   
   // Si existe un nodo con el valor v:
   if((*lista)->siguiente->valor == v) 
   {
      if(*lista == (*lista)->siguiente) // Y si la lista sólo tiene un nodo
      {
         free(*lista);// Borrar toda la lista
         *lista = NULL;
      }
      else // Si la lista tiene más de un nodo, borrar el nodo  de valor v
      {
        nodo = (*lista)->siguiente;
        (*lista)->siguiente = nodo->siguiente;
        free(nodo);
      }
   }
}

void BorrarLista(Lista *lista) {
   pNodo nodo;

   // Mientras la lista tenga más de un nodo
   while((*lista)->siguiente != *lista) {
      // Borrar el nodo siguiente al apuntado por lista
      nodo = (*lista)->siguiente;
      (*lista)->siguiente = nodo->siguiente;
      free(nodo);
   }
   // Y borrar el último nodo
   free(*lista);
   *lista = NULL;
}

void MostrarLista(Lista lista) 
{
   pNodo nodo = lista;
   int i=1;

   do 
   {
      printf("-> %d ", nodo->valor);
      nodo = nodo->siguiente;
      i++;
   } 
   while(nodo != lista);
}
