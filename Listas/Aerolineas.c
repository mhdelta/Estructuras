


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
//------------------------------------------------------------------------
struct pasajeros{
    char cc[50];
	char nombre[50]; 
	char telefono[50];
	char estado[50]; //Con reserva, abordo
	struct vuelo *sgte;     
};
typedef struct pasajeros *Tpasajero;
//------------------------------------------------------------------------
struct vuelo{
    char nro_vuelo[50];
	char ciudad_origen[50]; 
	char ciudad_destino[50];
	char matricula[50];
	char nombre_piloto[50];
	char hora_vuelo[50];
	char fecha_vuelo[50];
	char estado_vuelo[50]; // Programado | Realizado
	struct pasajeros *pasajero;
    struct vuelo *sgte;     
};
typedef struct vuelo *Tvuelo;
//------------------------------------------------------------------------









//------------------------------------------------------------------------


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
  puts("AEROLINEA \"EL ÚLTIMO VIAJE\"\n");
  puts("[1]. Insertar vuelo");
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
// El programa debe permitir hacer lo siguiente:

  // La aerolínea “VIAJAR”, desea hacer un manejo adecuado de los vuelos que realiza periódicamente. De cada vuelo se tienen 
  // los siguientes datos: Nro de vuelo, ciudad origen, ciudad destino, matrícula del avión, nombre del piloto, hora del vuelo 
  // y fecha del vuelo, además se tiene el estado del vuelo (programado o realizado). Cada vuelo tiene a su vez asignado una 
  // lista de pasajeros; de cada pasajero se tiene la cédula, el nombre, el teléfono y el estado (con reserva o a bordo siempre 
  // 	que el vuelo no se haya realizado).

// Crear una estructura de multilista para el manejo de los datos de la aerolinea, con los vuelos como la lista principal y para cada vuelo la sublista de pasajeros.
// Se debe poder adicionar vuelos.
// Adicionar pasajeros
// Obtener listados (pasajeros de un vuelo realizado o programado, lista de vuelos programados, lista de vuelos realizados).
// Dada la cédula de una persona, obtener un listado de los vuelos que ha realizado y de los vuelos que tiene programado realizar.
// Cuando se hace un vuelo, se debe modificar el estado del vuelo a realizado.
// Se debe tener una opción que permita registrar cuando un pasajero pasa a bordo.