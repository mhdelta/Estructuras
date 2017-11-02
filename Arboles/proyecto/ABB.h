#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//------------------------------------------------------------------------------------------
// ABB

struct nodos
{
	int nro;
	nodos *izq;
	nodos *der;
};

typedef struct nodos *ABB;

//Funciones Basicas de ABB

ABB CrearNodo (int x)
{
	ABB nuevoNodo = new(struct nodos);
	nuevoNodo->nro=x;
	nuevoNodo->izq=NULL;
	nuevoNodo->der=NULL;
	return(nuevoNodo);
}

void insertar (ABB &arbol, int x)
{
	if (arbol==NULL)
	{
		arbol=CrearNodo(x);
	}
	else
	{
		if(x<arbol->nro)
		{
			insertar(arbol->izq, x);
		}
		else
		{
			insertar(arbol->der,x);
			
		}
	}
}

int buscar(ABB &arbol, int n)
{
	if (arbol==NULL)
	{
		return(0);
	}
	else
	{
		if(n<arbol->nro)
		{
			if(n==arbol->nro)
				return(1);
				buscar(arbol->izq, n);
		}
		else
		{
			if(n==arbol->nro)
				return(1);
				buscar(arbol->der, n);
		}
	}
}

void insertarCompletoABB(ABB &arbol)
{
	int n, x, op=0;
	
	cout<<"Numero de nodos del arbol: ";
	cin>>n;
	cout<<endl;
	
	for(int i=0;i<n;i++)
	{
	cout<<"\nNumero del Nodo "<<i+1<<": ";
	cin>>x;
	op=buscar(arbol,x);
	if(op==1)
		cout<<"\nEl numero fue insertado en el arbol";
	else
		insertar(arbol,x);
	}
}
				
ABB unirABB(ABB izq, ABB der)
{
    if(izq==NULL) return der;
    if(der==NULL) return izq;

    ABB centro = unirABB(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}

void PreOrden(ABB arbol)
{
	if(arbol!=NULL)
	{
		cout<<arbol->nro<<" ";
		PreOrden(arbol->izq);
		PreOrden(arbol->der);
	}
}

void EnOrden(ABB arbol)
{
	if(arbol!=NULL)
	{
		EnOrden(arbol->izq);
		cout<<arbol->nro<<" ";
		EnOrden(arbol->der);
	}
}

void PostOrden (ABB arbol)
{
	if(arbol!=NULL)
	{
		PostOrden(arbol->izq);
		PostOrden(arbol->der);
		cout<<arbol->nro<<" ";
	}
}

void VerArbol(ABB arbol,int n)
{
	if (arbol==NULL)
		return;
	VerArbol(arbol->der,n+1);	
	
	
	for(int i=0;i<n;i++)
		cout<<"   ";
		
	cout<<arbol->nro<<endl;
	
	VerArbol(arbol->izq,n+1);
	
}

//FUNCIONES DE ABB

//PUNTO 1
int peso(ABB arbol)
{
	if(arbol!=NULL)
	{
		return(1+peso(arbol->izq)+peso(arbol->der));
	}
	
}

//PUNTO 2
int altu(ABB arbol)
{
	int altiz,altde,alt;
	if(arbol==NULL)
	{return (0);}
	else
	{
		altiz=altu(arbol->izq);
		altde=altu(arbol->der);
		
		if(altiz>altde)
			alt=altiz+1;
		else
			alt=altde+1;
	}
	return(alt);
}

//PUNTO 3
int cueho(ABB arbol)
{
	if(arbol==NULL)
	{
		return(0);
	}
	
	else if(((arbol->izq)==NULL) and ((arbol->der)==NULL))
		return(1);
		
	else return(cueho(arbol->izq)+cueho(arbol->der));
	
}

int nivno(ABB arbol, int n)
{
	if(arbol==NULL)
		return (-1);
		
	else if ((arbol->nro)==n)
		return(0);
		
	else if (buscar(arbol->izq, n))
		return (nivno(arbol->izq,n)+1);
		
	else if (buscar(arbol->der,n))
		return (nivno(arbol->der,n)+1);
		
	else return(-1);
}

//PUNTO 4
int buscapa(ABB &arbol, int n)
{
	int x = nivno(arbol,n);
	if(x==0){
		cout<<"El numero es la raiz"<<endl;			
	}else{
			if (arbol==NULL)
			return(0);
			else{
				if(n<arbol->nro)
				{
					if(n==arbol->izq->nro or n==arbol->der->nro)
						return(arbol->nro);
						buscapa(arbol->izq, n);
				}
				else
				{
					if(n==arbol->izq->nro or n==arbol->der->nro)
						return(arbol->nro);
						buscapa(arbol->der, n);
					
				}
			}
		}
		
}
//PUNTO 15
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
         arbol = unirABB(arbol->izq, arbol->der);
         delete p;
     }
}

void menuABB ()
{
	cout<<"\n[1]. Mostrar el Arbol\n[2]. Recorridos del arbol\n[3]. Buscar un numero\n[4]. Insertar otro numero.\n[5]. Eliminar un numero\n[7]. Altura del arbol.\n[8]. Contar hojas\n";
	cout<<"[9]. Buscar el padre de un elemento.[20].Regresar\n>>";
}

int FuncionesABB ()
{
	int x, a, op=0, n;
	ABB arbol=NULL;
	ABB arbol2=NULL;
	ABB arbol3=NULL;
	ABB arbol4=NULL;
	
	insertarCompletoABB (arbol);
	
	do {
		menuABB();
		cout<<"ingrese una opcion: ";
		cin>>a;
		
		switch(a)
		{
			case 1: cout<<"\n Mostrando ABB: \n\n";
					VerArbol(arbol,0);
					break;
			case 2: cout<<"Recorridos del ABB";
					cout<<"\nEn Orden: ";
					EnOrden(arbol);
					cout<<"\nPreOrden: ";
					PreOrden(arbol);
					cout<<"\nPostOrden: ";
					PostOrden(arbol);
					cout<<endl<<endl;
					break;
			case 3: cout<<"Numero a buscar:";
					cin>>x;
					x=buscar(arbol,x);
					if(x==1)
						cout<<"\nEl numero esta en el arbol"<<endl;
					else
						cout<<"\nEl numero no esta en el arbol"<<endl;
					break;
			case 4: cout<<"Numero a insertar:"<<endl;
					cin>>x;
					op=buscar(arbol,x);
					if(op==1)
						cout<<"\nEl numero fue insertado previamente en el arbol"<<endl;
					else
						insertar(arbol,x);
						cout<<"\nEl numero fue insertado correctamente"<<endl;
					break;
			case 5: cout<<"Numero a eliminar:"<<endl;
					cin>>x;
					elimina(arbol,x);
					cout<<"El numero se elimino correctamente"<<endl;
					break;
			case 7: cout<<"\nAltura del arbol:"<<altu(arbol)<<endl;
					break;
			case 8:	cout<<"\nCantidad de hojas:"<<cueho(arbol)<<endl;
					break;
			case 9:	cout<<"\nNumero a buscarle el padre:\n>> ";
					cin>>n;
					cout<<"\nPadre del elemento:"<<buscapa(arbol, n)<<endl;
					break;
			}
		}while(a!=20);
}
