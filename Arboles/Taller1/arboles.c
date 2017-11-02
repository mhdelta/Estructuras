#include <iostream>
#include <cstdlib>
#include "ABB.h"


int main(){
	ABB arbol = NULL;   // creado Arbol

    int n;  // numero de nodos del arbol
    int x; // elemento a insertar en cada nodo
    char m;
  int k;
  int pos;
  puts("ARBOLES BINARIOS\n");
    while(1){    
        printf("\n Insertar [I], Buscar [B], Eliminar [E] , Ver arbol [V], Recorridos [R], SALIR [S]: ");
        m=getchar();
        getchar();
 switch(m){
      case 'I': printf("Introduzca un número: "); scanf("%d", &k); getchar(); insertar(arbol, k); verArbol(arbol, 0); break;
      case 'B': printf("Introduzca un número: "); scanf("%d", &k); getchar(); if(buscar(arbol, k)){
      																				printf("%s %d %s\n", "El numero ", k, " SI esta en el arbol");
      																			}else{
      																				printf("%s %d %s \n", "El numero ", k, " NO se encuentra en el arbol");	
      																			}; 
      																			break;
      case 'E': printf("Introduzca un número: "); scanf("%d", &k); getchar(); eliminar(arbol, k); verArbol(arbol, 0); break;
	  case 'V': verArbol(arbol, 0); break;
	  case 'R': printf("%s :", "Pre-orden"); preOrden(arbol);printf("\n");printf("%s :", "En orden"); enOrden(arbol);printf("\n");printf("%s :", "Post-orden") ;postOrden(arbol);printf("\n") ;break;
   	  case 'S': exit(0);  
      default: puts("\nSaliendo del programa..."); exit(0);
    }
   }

	return 0;
}
