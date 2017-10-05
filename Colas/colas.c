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

struct cola{
  nodo *delante;
  nodo *atras;  
};

struct nodo_pila{
     int nro;
     struct nodo_pila *sgte;
     
};
typedef nodo_pila *ptrpila;

void encolar(struct nodo &q, int valor);
int desencolar(struct cola &q);
void mostrar_cola(struct cola &p);
void eliminar_cola(struct cola &q);
void invertir_cola(struct cola &q);
void existeX(int x, struct cola &q);
void estaOrdenada(struct cola &q);
void push(ptrpila &p, int valor);
int pop(ptrpila &p);
void sonIguales();

void push(ptrpila &p, int valor)
{
    ptrpila aux;
    aux=new(struct nodo_pila);
    aux->nro=valor;
    aux->sgte=p;
    p=aux;
}


int pop(ptrpila &p)
{
    if(p == NULL){

    }else{
        int num;
        ptrpila aux;
        aux=p;
        num=aux->nro;
        p=aux->sgte;
        delete(aux);
        return num;
    }
}

void encolar(struct cola &q, int valor)
{
  struct nodo *aux = new(struct nodo);
  aux->nro = valor;
  aux->sgte = NULL;
  if(q.delante == NULL){
    q.delante = aux;
  }else{
    (q.atras)->sgte = aux;
  }
  q.atras = aux;
}


int desencolar(struct cola &q)
{
  if(q.delante == NULL){
    return 0;
  }
  int num;
  struct nodo *aux;
  aux = q.delante;
  num = aux->nro;
  q.delante = (q.delante)->sgte;
  delete(aux);

  return num;

}

void mostrar_cola(struct cola &q)
{
    struct nodo *aux;
    aux=q.delante;
    while(aux!=NULL)
    {
        cout<<" \t "<<aux->nro<<endl;
        aux=aux->sgte;
    }
}
void eliminar_cola(struct cola &q)
{
    struct nodo *aux;
    while(q.delante!=NULL)
    {
        aux = q.delante;
        q.delante = aux->sgte;
        delete(aux);
    }
    q.delante = NULL;
    q.atras = NULL;
}

void invertir_cola(struct cola &q){
  ptrpila x = NULL;
  struct nodo  *aux = new(struct nodo);
  int num =0;
  aux = q.delante;
  while(aux != NULL){
    push(x, aux->nro);
    aux = aux->sgte;
  }
  eliminar_cola(q);
  while(x != NULL){
    encolar(q, pop(x));
  }
}

void existeX(int x, struct cola &q){
    struct nodo *aux;
    int flag = 0;
    aux = q.delante;
    while(aux != NULL){
        if(x == aux->nro){
            flag=1;
        }
        aux = aux->sgte;
    }
    if(flag){
        printf("\n El numero %d si esta en la pila\n", x);
    }else{
        printf("\n El numero %d no esta en la pila\n", x);
    }
}
void estaOrdenada(struct cola &q){
    struct nodo *aux;
    int flag = 0;
    int temp;
    aux = q.delante;
    while(aux->sgte != NULL){
        temp = aux->nro;
        // printf("%d\n", temp);
        aux = aux->sgte;
        // printf("%d\n", aux->nro);
        if(temp > aux->nro){
            flag=1;
        }
    }
    if(flag){
        printf("%s\n", "La pila NO esta ordenada ascendentemente");
    }else{
        printf("%s\n", "La pila SI esta ordenada ascendentemente");
    }
}

void comparar(struct cola &q1, struct cola &q2){
  struct nodo *aux1;
  struct nodo *aux2;
  aux1 = q1.delante;
  aux2 = q2.delante;
  int flag = 0;
  int temp1, temp2;

  while(aux1 != NULL && aux2 != NULL){
    temp1 = aux1->nro;
    temp2 = aux2->nro;
    // printf("\n aux 1 : %d     aux2 : %d", aux1,aux2);
    if(temp1 != temp2){
      flag = 1;  
    }
    aux1 = aux1->sgte;
    aux2 = aux2->sgte;
  }
  if(flag){
    printf("%s\n", "Las pilas NO son iguales");
  }else{
    printf("%s\n", "las pilas SI son iguales");
  }
}
void menu_comparar(){
  struct cola q1;
  struct cola q2;
  q1.delante = NULL;
  q2.delante = NULL;
  char m;
  int k;
  puts("Encolar Q1 [A], Desencolar Q1 [B], Encolar Q2 [L], Desencolar Q2 [P], Comparar [I], mostrar pilas [M]: ");
  while(1){
        printf("[A], [B], [L], [S], [P], [I], [M]: ");
        m=getchar();
        getchar();
 switch(m){
      case 'A': printf("Introduzca un número: "); scanf("%d", &k); getchar(); encolar(q1, k); break;
      case 'B': desencolar(q1); break;
      case 'L': printf("Introduzca un número: "); scanf("%d", &k); getchar(); encolar(q2, k); break;
      case 'P': desencolar(q2); break;
      case 'I': comparar(q1, q2); break;
      case 'M': printf("%s\n", "pila 1: "); mostrar_cola(q1); printf("%s\n", "Pila 2: "); mostrar_cola(q2); break;
      case 'S': exit(0);
      default: puts("\nSaliendo del programa..."); exit(0);
        }
  }
}

void sacarX(struct cola &q, int x){
    struct nodo *aux = new(struct nodo);
    struct cola temp;
    temp.delante = NULL;
    temp.atras = NULL;
    int tmp;
    int flag = 0;
    aux = q.delante;
    while(aux != NULL)
    {
        tmp = aux->nro;
        if(tmp == x){
          flag=1;
        }else{
          encolar(temp, aux->nro);
        }
        aux = aux->sgte;
    }
    aux = temp.delante;
    eliminar_cola(q);
    while(aux != NULL){
      encolar(q, aux->nro);
      aux = aux->sgte;
    }
    if(flag){
        printf("\n El numero %d se extrajo de la pila\n", x);
    }else{
        printf("\n El numero %d no estaba en la pila\n", x);
    }
}
void insertarX(struct cola &q,int k, int pos){
    struct nodo *aux = new(struct nodo);
    struct cola temp;
    temp.delante = NULL;
    temp.atras = NULL;
    int flag = 0;
    int i = 0;
    aux = q.delante;
    while(aux != NULL){
        if(i == pos){
          flag=1;
          encolar(temp, k);
        }else{
        encolar(temp, aux->nro);
        aux = aux->sgte;
       }
      i++;
    }
    aux = temp.delante;
    eliminar_cola(q);
    while(aux != NULL){
      encolar(q, aux->nro);
      aux = aux->sgte;
    }
    if(flag){
        printf("\n El numero %d se inserto en la pila\n", k);
    }else{
        printf("\n La pila no tiene suficientes posiciones\n");
    } 
}

void ejercicio7(struct cola &q, int x){
  struct cola q1;
  q1.delante = NULL;
  q1.atras = NULL;
  struct cola q2;
  q2.delante = NULL;
  q2.atras = NULL;

  struct nodo *aux = new(struct nodo);
  int flag = 0;
  aux = q.delante;
  while(aux != NULL){
      if(x >= aux->nro){
          encolar(q1, aux->nro);
      }else{
          encolar(q2, aux->nro);
     }
     aux = aux->sgte;
  }
  printf("\n Pila con los numeros mayores a %d: \n", x);
  mostrar_cola(q2);
  printf("\n Pila con los numeros menores o iguales a %d: \n", x);
  mostrar_cola(q1);
   
}
main(){
  struct cola q;
  q.delante = NULL;
  q.atras = NULL;

  char m;
  int k;
  int pos;
  puts("Encolar [A], Desencolar [B], Listar [L] , Salir [S], Eliminar cola[P], Invertir cola[I], Existe x? [E]Comparar [C], Sacar X[T], Insertar X[N] , Ejercicio 7 [7]:");
  while(1){
        printf("[A], [B], [L], [S], [P], [I], [E], [O], [C], [T], [N], [7]: ");
        m=getchar();
        getchar();
 switch(m){
      case 'A': printf("Introduzca un número: "); scanf("%d", &k); getchar(); encolar(q, k); break;
      case 'B': desencolar(q); break;
      case 'L': mostrar_cola(q); break;
      case 'P': eliminar_cola(q); break;
      case 'I': invertir_cola(q); break;
      case 'E': printf("Introduzca un número: "); scanf("%d", &k); getchar(); existeX(k, q); break;
      case 'O': estaOrdenada(q); break;
      case 'C': menu_comparar();
      case 'T': printf("Introduzca un número: "); scanf("%d", &k); getchar();sacarX(q, k); break;
      case 'N': printf("Introduzca un número: "); scanf("%d", &k); getchar(); printf("Introduzca la pos: "); scanf("%d", &pos); getchar();insertarX(q, k, pos); break;
      case '7': printf("Introduzca un número: "); scanf("%d", &k); getchar();ejercicio7(q, k); break;
      case 'S': exit(0);
      default: puts("\nSaliendo del programa..."); exit(0);
        }
  }
  return 0;

}