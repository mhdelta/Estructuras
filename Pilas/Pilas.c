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
typedef nodo *ptrpila;

void push(ptrpila &p, int valor);
int pop(ptrpila &p);
void mostrar_pila(ptrpila &p);
void eliminar_pila(ptrpila &p);
void invertir_pila(ptrpila &p);
void existeX(int x, ptrpila &p);
void estaOrdenada(ptrpila &p);

void push(ptrpila &p, int valor)
{
    ptrpila aux;
    aux=new(struct nodo);
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

void mostrar_pila(ptrpila &p)
{
    ptrpila aux;
    aux=p;
    while(aux!=NULL)
    {
        cout<<" \t "<<aux->nro<<endl;
        aux=aux->sgte;
    }
}
void eliminar_pila(ptrpila &p)
{
    ptrpila aux;
    while(p!=NULL)
    {
        aux=p;
        p=aux->sgte;
        delete(aux);
    }
}

void invertir_pila(ptrpila &p){
    ptrpila aux = NULL;

    while(p != NULL){
        push(aux, p->nro);
        pop(p);
    }
    p = aux;
}

void existeX(int x, ptrpila &p){
    ptrpila aux = NULL;
    int flag = 0;
    while(p != NULL){
        push(aux, p->nro);
        pop(p);
        if(x == aux->nro){
            flag=1;
        }
    }
    p = aux;
    invertir_pila(p);
    if(flag){
        printf("\n El numero %d si esta en la pila\n", x);
    }else{
        printf("\n El numero %d no esta en la pila\n", x);
    }
}
void estaOrdenada(ptrpila &p){
    ptrpila aux = NULL;
    int flag = 0;
    int temp = 0;
    while(p->sgte != NULL){
        push(aux, p->nro);
        pop(p);
        temp = p->nro;          
        if(aux->nro < temp){    
           flag=1;
        }
    }
    p = aux;
    invertir_pila(p);
    if(flag){
        printf("\n%s", "La pila NO esta ordenada\n");
    }else{
        printf("\n%s", "La pila SI esta ordenada\n");
    }
}

void comparar(ptrpila &q1, ptrpila &q2){
  ptrpila aux1 = NULL;
  ptrpila aux2 = NULL;

  int flag = 0;

  while(q1 != NULL&& q2 != NULL){
    push(aux1, q1->nro);
    pop(q1);
    push(aux2, q2->nro);
    pop(q2);
    // printf("\n aux 1 : %d     aux2 : %d", aux1,aux2);
    if(aux1->nro != aux2->nro){
      flag = 1;
    }
  }
  q1 = aux1;
  invertir_pila(q1);
  q2 = aux2;
  invertir_pila(q2);
  if(flag){
    printf("%s\n", "Las pilas NO son iguales");
  }else{
    printf("%s\n", "las pilas SI son iguales");
  }
}
void menu_comparar(){
  ptrpila q1 =NULL;
  ptrpila q2 =NULL;
  char m;
  int k;
  puts("Push Q1 [A], POP Q1 [B], Push Q2 [L], Pop Q2 [P], Comparar [I], mostrar pilas [M]: ");
  while(1){
        printf("[A], [B], [L], [S], [P], [I], [M]: ");
        m=getchar();
        getchar();
 switch(m){
      case 'A': printf("Introduzca un número: "); scanf("%d", &k); getchar(); push(q1, k); break;
      case 'B': pop(q1); break;
      case 'L': printf("Introduzca un número: "); scanf("%d", &k); getchar(); push(q2, k); break;
      case 'P': pop(q2); break;
      case 'I': comparar(q1, q2); break;
      case 'M': printf("%s\n", "pila 1: "); mostrar_pila(q1); printf("%s\n", "Pila 2: "); mostrar_pila(q2); break;
      case 'S': exit(0);
      default: puts("\nSaliendo del programa..."); exit(0);
        }
  }
}

void sacarX(ptrpila &p, int x){
    ptrpila aux = NULL;
    int flag = 0;
    while(p != NULL){
        if(x == p->nro){
          flag=1;
          pop(p);
        }else{
        push(aux, p->nro);
        pop(p);
       }
    }
    p = aux;
    invertir_pila(p);
    if(flag){
        printf("\n El numero %d se extrajo de la pila\n", x);
    }else{
        printf("\n El numero %d no estaba en la pila\n", x);
    }
}
void insertarX(ptrpila &p,int k, int pos){
    ptrpila aux = NULL;
    int flag = 0;
    int i = 0;
    while(p != NULL){
        if(i == pos){
          flag=1;
          push(aux, k);
        }else{
        push(aux, p->nro);
        pop(p);
       }
      i++;
    }
    p = aux;
    invertir_pila(p);
    if(flag){
        printf("\n El numero %d se inserto en la pila\n", k);
    }else{
        printf("\n La pila no tiene suficientes posiciones\n");
    } 
}

void ejercicio7(ptrpila &p, int x){
  ptrpila p1 =NULL;
  ptrpila p2 =NULL;
  ptrpila aux = NULL;
  int flag = 0;
  while(p != NULL){
      push(aux, p->nro);
      if(x >= p->nro){
          flag=1;
          push(p1, p->nro);
      }else{
          push(p2, p->nro);
     }
     pop(p);
  }
  p = aux;
  invertir_pila(p);
  printf("\n Pila con los numeros mayores o iguales a %d: \n", x);
  mostrar_pila(p2);
  printf("\n Pila con los numeros menores a %d: \n", x);
  mostrar_pila(p1);
   
}
main(){
  ptrpila x =NULL;
  char m;
  int k;
  int pos;
  puts("PUSH [A], POP [B], LISTAR [L] , QUIT [S], Eliminar pila[P], Invertir pila[I], Existe x? [E], Comparar [C], Sacar X[T], Insertar X[N] , Ejercicio 7 [7]: ");
  while(1){
        printf("[A], [B], [L], [S], [P], [I], [E], [O], [C], [T], [N], [7]: ");
        m=getchar();
        getchar();
 switch(m){
      case 'A': printf("Introduzca un número: "); scanf("%d", &k); getchar(); push(x, k); break;
      case 'B': pop(x); break;
      case 'L': mostrar_pila(x); break;
      case 'P': eliminar_pila(x); break;
      case 'I': invertir_pila(x); break;
      case 'E': printf("Introduzca un número: "); scanf("%d", &k); getchar(); existeX(k, x); break;
      case 'O': estaOrdenada(x); break;
      case 'C': menu_comparar();
      case 'T': printf("Introduzca un número: "); scanf("%d", &k); getchar();sacarX(x, k); break;
      case 'N': printf("Introduzca un número: "); scanf("%d", &k); getchar(); printf("Introduzca la pos: "); scanf("%d", &pos); getchar();insertarX(x, k, pos); break;
      case '7': printf("Introduzca un número: "); scanf("%d", &k); getchar();ejercicio7(x, k); break;
      case 'S': exit(0);  
      default: puts("\nSaliendo del programa..."); exit(0);
    }
  }
  return 0;

}