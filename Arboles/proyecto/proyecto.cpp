#include "ABB.h"
#include "AVL.h"


void menu2()
{
	cout<<"\n[1]. Insertar"<<endl;
	cout<<"[2]. Eliminar"<<endl;
	cout<<"[3]. Buscar"<<endl;
	cout<<"[4]. Ver el Arbol"<<endl;
	cout<<"[5]. Regresar"<<endl;
}

int FuncionesAVL()
{
	int op=0, dato;
	
	AVL arbol=NULL;
	
	cout<<"\n\t\t...[Arbol AVL]...\n\n";
	

	
	do{
		menu2();
		cout<<"ingrese una opcion: ";
		cin>>op;
		
		switch (op)
		{
			case 1: cout<<"ingrese el dato que quiere insertar: ";
					cin>>dato;
					insertarAVL(arbol, dato);
					cout<<"\nEl dato fue insertado correctamente"<<endl;
					break;
			case 2: cout<<"ingrese el dato que quiere eliminar: ";
					cin>>dato;
					eliminarNodo(arbol, dato);
					cout<<"\nEl dato fue eliminado correctamente"<<endl;
					break;
			case 3: cout<<"ingrese el dato que quiere buscar: ";
					cin>>dato;
					buscarAVL(arbol, dato);
					break;
			case 4: verArbolAVL(arbol, 0);
					break;
		}
		// system("clear");
	}while (op!=5);
	
	return 0;
}

//________________________________________________________________________________________________________________________________
//ARBOL ROJO-NEGRO

/*
int FuncionesARN()
{
	int op=0, dato;
	
	ptr arbol=NULL;
	
	cout<<"\n\t\t...[Arbol Rojo-Negro]...\n\n";
	
	insertarcompletoARN(&arbol);
	
	do{
		menu2();
		cout<<"ingrese una opcion: ";
		cin>>op;
		
		switch (op)
		{
			case 1: cout<<"ingrese el dato que quiere insertar: ";
					cin>>dato;
					InsertarARN(&arbol, dato);
					cout<<"\nEl dato fue insertado correctamente"<<endl;
					break;
			case 2: cout<<"ingrese el dato que quiere eliminar: ";
					cin>>dato;
					EliminarARN(&arbol, dato);
					cout<<"\nEl dato fue eliminado correctamente"<<endl;
					break;
			case 3: cout<<"ingrese el dato que quiere buscar: ";
					cin>>dato;
					BuscarARN (arbol, dato);
					break;
			case 4: VerArbolARN(arbol, 0);
					break;
		}
		system("PAUSE");
		system("CLS");
	}while (op!=5);
	
	return 0;
}*/
//_________________________________________________________________________________________________________________________


void menuPrincipal()
{
	cout<<"\n[1]. ABB"<<endl;
	cout<<"[2]. AVL"<<endl;
	cout<<"[3]. Arbol Rojo-Negro"<<endl;
	cout<<"[4]. Salir"<<endl;
}

int main ()
{
	system("clear");
	int n, x, a;
	int op=0, op1=0;
	
	do
	{
		menuPrincipal();
		cout<<"Que tipo de arbol Desea Implementar (1-4)? ";
		cin>>op;
		switch(op)
		{
			case 1: cout<<"\n\t\t...[Arbol Binario de Busqueda]...\n\n";
					FuncionesABB ();
					break;
			case 2: FuncionesAVL ();
					break;
			case 3: //ARN arbol3=NULL;
					cout<<"\n\t\t...[Arbol Rojo-Negro]...\n\n";
					//insertarCompletoARN (arbol3);
					//FuncionesARN ();//
					break;
		}
		system("clear");
	}
	while (op!=4);
}