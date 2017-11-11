#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
// #include <windows.h>
#include <math.h>

#define ROJO 'r'
#define NEGRO 'n'
using namespace std;

/*****************************************************/
void posicion (int x, int y)
{
  // HANDLE hConsoleOutput;
  // COORD coord;
  // hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
  // coord.X = x, coord.Y = y;
  // SetConsoleCursorPosition (hConsoleOutput, coord);
}
/*****************************************************/

void color(int c)
{
  // SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),c);
}
/*****************************************************/


struct nodoRBT{
    int nro;
    char color;
    struct nodoRBT *padre;
    struct nodoRBT *izq;
    struct nodoRBT *der;
};

typedef struct nodoRBT *RBT;

/*****************************************************/
RBT buscarARN(RBT nodoRBT, int dato)
{
   RBT actual = nodoRBT;
   if(nodoRBT==NULL){
    cout<<"\n\t��  El arbol esta vacio  ��"<<endl<<endl;
    return NULL;
   }
   while(actual!= NULL)
   {
      if(dato == actual->nro)
      {
        cout<<"\n\tEl numero "<<dato<<" existe en el arbol\n";
        return actual;
      }
      else if(dato < actual->nro)
         actual = actual->izq;
      else if(dato > actual->nro)
         actual = actual->der;
   }
   cout<<"\n\tEl numero "<<dato<<" NO existe en el arbol\n";
   return NULL;
}

/*****************************************************/
void verArbolARN(RBT arbol, int n)
{
     if(arbol==NULL)
        return;
     verArbolARN(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     if(arbol->color==ROJO)color(12);
     else if(arbol->color==NEGRO)color(8);
    cout<< arbol->nro<<endl;

     verArbolARN(arbol->izq, n+1);
     color(15);
}

/*****************************************************/
RBT abuelo(RBT n)
{
	if ((n != NULL) && (n->padre != NULL))
		return n->padre->padre;
	else
		return NULL;
}

/*****************************************************/
RBT tio(RBT n)
{
	RBT a = abuelo(n);
	if (n->padre == a->izq)
		return a->der;
	else
		return a->izq;
}

/*****************************************************/
void rotar_dcha(RBT &r, RBT &nodoRBT) //Rotaci�n simple derecha
{
   RBT padre = nodoRBT->padre;
   RBT A = nodoRBT;
   RBT B = A->izq;
   RBT C = B->der;
   if(padre)
            if(padre->der == A)
                  padre->der = B;
            else
                 padre->izq = B;
   else r = B;

   //ROTAR
   A->izq = C;
   B->der = A;
   A->padre = B;
   if(C)
     C->padre = A;

   B->padre = padre;
}


/*****************************************************/
void rotar_izda(RBT &r, RBT &nodoRBT)
{
   RBT padre = nodoRBT->padre;
   RBT A = nodoRBT;
   RBT B = A->der;
   RBT C = B->izq;
   if(padre){
            if(padre->der == A)
                 padre->der = B;
            else
                 padre->izq = B;
            }
   else  r = B;

   //ROTAR
   A->der = C;
   B->izq = A;
   A->padre = B;
   if(C)
      C->padre = A;
   B->padre = padre;
}



/*           Casos de inserci�n            */
void insercion_caso1(RBT &n, RBT &arbol);
void insercion_caso2(RBT &n, RBT &arbol);
void insercion_caso3(RBT &n, RBT &arbol);
void insercion_caso4(RBT &n, RBT &arbol);
void insercion_caso5(RBT &n, RBT &arbol);
/*****************************************************/


void insercion_caso5(RBT &n, RBT &arbol)
{
	RBT a = abuelo(n);

	n->padre->color = NEGRO;
	a->color = ROJO;
	if ((n == n->padre->izq) && (n->padre == a->izq)) {
		rotar_dcha(arbol, a);
	} else {
			rotar_izda(arbol, a);
	}
}
/*****************************************************/

void insercion_caso4(RBT &n, RBT &arbol)
{
	RBT a = abuelo(n);

	if ((n == n->padre->der) && (n->padre == a->izq)) {
		rotar_izda(arbol, n->padre);
		n=n->izq;
	} else if ((n == n->padre->izq) && (n->padre == a->der)) {
		rotar_dcha(arbol, n->padre);
		n=n->der;
	}
	insercion_caso5(n, arbol);
}
/*****************************************************/

void insercion_caso3(RBT &n, RBT &arbol)
{
	RBT t = tio(n), a;

	if ((t != NULL) && (t->color == ROJO)) {
		n->padre->color = NEGRO;
		t->color = NEGRO;
		a = abuelo(n);
		a->color = ROJO;
		insercion_caso1(a, arbol);
	} else {
		insercion_caso4(n, arbol);
        }
}
/*****************************************************/


void insercion_caso2(RBT &n, RBT &arbol)
{
	if (n->padre->color == NEGRO)
		return; /* �rbol v�lido. */
	else
		insercion_caso3(n, arbol);
}
/*****************************************************/

void insercion_caso1(RBT &n, RBT &arbol)
{
	if (n->padre == NULL)
		n->color = NEGRO;
	else
		insercion_caso2(n, arbol);
}
/*****************************************************/

void insertarARN(RBT &arbol, int dato)
{
   RBT padre = NULL;
   RBT actual = arbol;
   while(actual!=NULL && dato!=actual->nro)
   {
      padre=actual;

      if(dato < actual->nro) actual = actual->izq;
      else if(dato > actual->nro) actual = actual->der;
   }
   if(actual!=NULL) return; //Actual ya apunta a un nro, salimos

  if(padre==NULL) //El nro a insertar ser� la ra�z
  {
      arbol = (RBT)malloc(sizeof(struct nodoRBT));
      arbol->nro = dato;
      arbol->izq = arbol->der = NULL;
      arbol->padre = NULL;
      arbol->color = ROJO;
      actual=arbol;
  }

  else if(dato < padre->nro)
       {
            actual=(RBT)malloc(sizeof(struct nodoRBT));
            padre->izq = actual;
            actual->nro = dato;
            actual->izq=actual->der = NULL;
            actual->padre = padre;
            actual->color = ROJO;
       }else{
              if(dato > padre->nro)
              {
                    actual = (RBT)malloc(sizeof(struct nodoRBT));
                    padre->der = actual;
                    actual->nro = dato;
                    actual->izq = actual->der = NULL;
                    actual->padre = padre;
                    actual->color = ROJO;
              }
                }
    insercion_caso1(actual, arbol);
   cout<<"\n\n\tEl numero ha sido insertado\n\n";
}
/*****************************************************/

void eliminar_rbt (RBT &arbol, int x)
{
    RBT aux1,aux2;
    if(arbol==NULL)
        return;
    if(x<arbol->nro)
        eliminar_rbt(arbol->izq,x);
    if(x>arbol->nro)
        eliminar_rbt(arbol->der,x);
    if(x==arbol->nro)
    {
        if(arbol->izq==NULL&&arbol->der==NULL)
            {
                arbol=NULL;
                return;
            }
        if(arbol->izq==NULL)
        {
            arbol=arbol->der;
            return;
        }
        if(arbol->der==NULL)
        {
            arbol=arbol->izq;
            return;
        }
            aux1=arbol;
            aux2=arbol->izq;
            while(aux2->der!=NULL)
            {
                aux1=aux2;
                aux2=aux2->der;
            }
            arbol->nro=aux2->nro;
            if(aux1==arbol)
                arbol->izq=aux2->izq;
            else
            aux1->der=aux2->izq;
    }
}


