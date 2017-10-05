#include <iostream>
#include <stdlib.h>

using namespace std;

void FlushStdin(void) {
  int ch;
  while(((ch = getchar()) !='\n') && (ch != EOF));
}

struct nodo{
     int nro;
     struct nodo *sgte;     
};
typedef struct nodo *Tlista;

void insertarInicio(Tlista &lista, int valor);
void insertarFinal(Tlista &lista, int valor);
int insertarAntesDespues(Tlista &lista, int valor);
void insertarElemento(Tlista &lista, int valor, int pos);
void eliminarRepetidos(Tlista &lista, int valor);
// void invertir_pila(Tlista &p);
// void existeX(int x, Tlista &p);
// void estaOrdenada(Tlista &p);

void insertarInicio(Tlista &lista, int valor)
{
    Tlista q;
    q=new(struct nodo);
    q->nro=valor;
    q->sgte=lista;
    lista = q;
}

void insertarFinal(Tlista &lista, int valor)
{
  Tlista t, q = new(struct nodo);
  q->nro = valor;
  q->sgte = NULL;
  if(lista == NULL){
    lista = q;
  }else{
    t = lista;
    while(t->sgte != NULL){
      t = t->sgte;
    }
    t->sgte = q;
  }
}
int insertarAntesDespues(){
  int _op, band;
  printf("\n%s","[1]. Antes de la posicion\t[2]. Despues de la posicion\n");
  scanf("%d", &_op);
  if(_op){
    band = -1;
  }else{
    band = 0;
  }
  return band;
}
void insertarElemento(Tlista &lista, int valor, int pos){
	Tlista q, t;
	int i;
	q = new(struct nodo);
	q->nro = valor;
	if(pos == 1){
		q->sgte = lista;
		lista = q;
	}else{
		int x = insertarAntesDespues();
		t = lista;
		for(i=1; t!=NULL; i++){
			q->sgte = t->sgte;
			t->sgte = q;
			return;
		}
		t = t->sgte;
	}
	printf("%s\n", "Error ... Pos no encontrada");
}
void buscarElemento(Tlista lista, int valor){
	Tlista q = lista;
	int i = 1, band = 0;
	while(q!=NULL){
		if (q->nro == valor){
			printf("\n%s %d", "Encontrada en pos",i);
			band=1;
		}
		q = q->sgte;
		i++;
	}
	if(band == 0){
		printf("%s\n", "\n\nNumero no encontrado..");
	}
}
void MostrarLista(Tlista lista){
	int i = 0;
	while(lista!=NULL){
		printf("%s\n %d )  %d", " ", (i + 1), lista->nro);
		lista = lista->sgte;
		i++;
	}
}
void eliminarElemento(Tlista &lista, int valor){
	eliminarRepetidos(lista, valor);
}
void eliminarRepetidos(Tlista &lista, int valor){
	Tlista q, ant;
	q=lista;
	ant=lista;
	while(q!=NULL){
		if(q->nro==valor){
			if(q==lista){
				lista=lista->sgte;
				delete(q);
				q=lista;
			}else{
				ant->sgte = q->sgte;
				delete(q);
				q=ant->sgte;
			}
		}else{
			ant = q;
			q = q->sgte;
		}
	}
	printf("%s\n", "Valores eliminados..!");
}
int Xveces(Tlista lista, int valor){
	int x;
	int i=0;
	while(lista!=NULL){
		x = lista->nro;
		if(x == valor){
			i++;
		}
		lista=lista->sgte;
	}
	return i;
}
int len(Tlista &lista){
	int i=0;
	Tlista aux;
	aux = lista;
	while(aux != NULL){
		aux=aux->sgte;
		i++;
	}
	return i;
}
void invertirLista(Tlista &lista){
	Tlista aux;
	aux = lista;
	int n = len(aux);
	int valores[n];
	int i =0;
	while(aux != NULL){
		valores[i] = aux->nro;
		aux=aux->sgte;
		i++;
	}
	aux = lista;
	while(aux != NULL){
		aux->nro = valores[n-1];
		n--;
		aux = aux->sgte;
	}
}
void xmayor(Tlista &lista){
	Tlista aux;
	aux = lista;
	int mayor = aux->nro;
	while(aux->sgte!=NULL){
		aux = aux->sgte;
		if(mayor <= aux->nro){
			mayor = aux->nro;
		}
	}
	printf("%s %d\n", "El numero mayor es: ",mayor);
}
void listaOrdenada(Tlista &lista){
	Tlista aux;
	aux = lista;
	aux = aux->sgte;
	int flag = 0;
	while(aux->sgte!=NULL){
		if(lista->nro > aux->nro){
			flag = 1;
		}
		aux = aux->sgte;
	}
	if(flag){
		printf("%s\n", "La lista NO esta ordenada");
	}else{
		printf("%s\n", "La lista SI esta ordenada");
	}
}
main(){
  Tlista x =NULL;
  char m;
  int k;
  int pos;
  puts("LISTA ENLAZADA SIMPLE\n");
  puts("Insertar al inicio [A], Insertar al final [B], Insertar en una pos [L] , QUIT [S], Mostrar [P], Buscar elemento[I], Eliminar elemento [E], Eliminar elementos con valor 'x' [C], Xveces [X]: ");
    while(1){    
        printf("\n[A], [B], [L], [S], [P], [I], [E], [O], [C], [X]: ");
        m=getchar();
        getchar();
 switch(m){
      case 'A': printf("Introduzca un número: "); scanf("%d", &k); getchar(); insertarInicio(x, k); break;
      case 'B': printf("Introduzca un número: "); scanf("%d", &k); getchar(); insertarFinal(x, k); break;
      case 'L': printf("Introduzca un número: "); scanf("%d", &k); getchar(); printf("Introduzca la pos: "); scanf("%d", &pos); getchar();insertarElemento(x, k, pos); break;
	  case 'P': MostrarLista(x); break;
	  case 'I': printf("Introduzca un número: "); scanf("%d", &k); getchar(); buscarElemento(x, k); break;
      case 'E': printf("Introduzca un número: "); scanf("%d", &k); getchar(); eliminarElemento(x, k); break;
      case 'C': printf("Introduzca un número: "); scanf("%d", &k); getchar(); eliminarRepetidos(x, k); break;
      case 'X': printf("Introduzca un número: "); scanf("%d", &k); getchar(); printf("El numero %d se encuentra %d veces en la lista",k,Xveces(x, k)); break;
      case 'N': invertirLista(x); break;
      case 'M': xmayor(x); break; 
      case 'l': printf("%d", (len(x))); break;
      case 'O': listaOrdenada(x); break;
   	  case 'S': exit(0);  
      default: puts("\nSaliendo del programa..."); exit(0);
    }
   }
   return 0;
  }

// 1. Dada una lista de elementos y un número P, devolver el número de veces que 

// está el valor de P en la lista. 




// 2. Dada una lista, hacer una función que invierta sus datos en ella misma y la 

// devuelva invertida. 




// 3. Hacer una función que reciba una lista y devuelva el promedio de los datos de la lista.



// 4. Hacer una función que reciba una lista y el mayor valor datos existentes. 



// 5. Hacer una función que reciba una lista e indique si está ordenada 

// ascendentemente. 