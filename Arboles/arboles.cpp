/*
* C++ - Arboles Binaros de busqueda -Recorridos por amplitud
* Description: Recorrdos por Orden, Pre-Orden y Post-Orden
*/

#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo{
     int nro;
     struct nodo *izq, *der;
};

typedef struct nodo *ABB;
/* es un puntero de tipo nodo que hemos llamado ABB, que ulitizaremos
   para mayor facilidad de creacion de variables */
//-------------------------------------------------------------------
ABB crearNodo(int x)
{
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}
//-------------------------------------------------------------------
void insertar(ABB &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}
//-------------------------------------------------------------------
void preOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->nro <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}
//-------------------------------------------------------------------
void enOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->nro << " ";
          enOrden(arbol->der);
     }
}
//-------------------------------------------------------------------
void postOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          postOrden(arbol->izq);
          postOrden(arbol->der);
          cout << arbol->nro << " ";
     }
}
//-------------------------------------------------------------------
void verArbol(ABB arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nro <<endl;

     verArbol(arbol->izq, n+1);
}
//-------------------------------------------------------------------
ABB EnlazarArbol(ABB izq, ABB der)
{
    if(izq==NULL) return der;
    if(der==NULL) return izq;

    ABB centro = EnlazarArbol(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}

void elimina(ABB &arbol, int x)
{

     if(arbol==NULL) return;

     if(x<arbol->nro)
         elimina(arbol->izq, x);
     else if(x>arbol->nro)
         elimina(arbol->der, x);

     else
     {
         ABB p = arbol;
         arbol = EnlazarArbol(arbol->izq, arbol->der);
         delete p;
     }
}
void eliminar(ABB &arbol){
	printf("%s\n", "[1] Eliminar\t[2]. Salir");
	int op;
	scanf("%d", &op); getchar();

	while(op != 2 and arbol != NULL){
		printf("%s\n", "Valor a eliminar");
		int x;
		scanf("%d", &x); getchar();
		elimina(arbol, x);
		printf("%s\n", "-----------------");
		verArbol(arbol, 0);
	}

}
int main()
{
    ABB arbol = NULL;   // creado Arbol

    int n;  // numero de nodos del arbol
    int x; // elemento a insertar en cada nodo

    cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";

    cout << " Numero de nodos del arbol:  ";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++)
    {
        cout << " Numero del nodo " << i+1 << ": ";
        cin >> x;
        insertar( arbol, x);
    }

    cout << "\n Mostrando ABB \n\n";
    verArbol( arbol, 0);

    // cout << "\n Recorridos del ABB";

    // cout << "\n\n En orden   :  ";   enOrden(arbol);
    // cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
    // cout << "\n\n Post Orden :  ";   postOrden(arbol);

    cout << endl << endl;


	eliminar(arbol);

    system("pause");
    return 0;
}