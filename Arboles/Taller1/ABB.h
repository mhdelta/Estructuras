using namespace std;
struct nodo{
     int nro;
     nodo *izq;
	 nodo *der;
};
typedef nodo *ABB;

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
     //global=n;
}
//-------------------------------------------------------------------
 

bool buscar(ABB arbol, int dato)
{
     int r=0;   // 0 indica que lo encontre

     if(arbol==NULL)
        return r;

     if(dato<arbol->nro)
         r = buscar(arbol->izq, dato);

     else if(dato> arbol->nro)
         r = buscar(arbol->der, dato);

     else
        r = 1;   // son iguales, lo encontre

     return r;
}


void eliminar(ABB &arbol,int x)
{
    ABB aux1,aux2;
    if(arbol==NULL) return;
    if(x>arbol->nro)
         eliminar(arbol->der,x);
    if(x<arbol->nro)
        eliminar(arbol->izq,x);
    if(x==arbol->nro)
    {
        if(arbol->der==NULL && arbol->izq==NULL) //Si el nodo es hoja
        {
            arbol=NULL;
            return;
        }
        if(arbol->der!=NULL && arbol->izq==NULL)
        {
            arbol=arbol->der;
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
//---------------------------------------------------------
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
//---------------------------------------------------------------
int cuentahojas(ABB arbol)
{
    if(arbol==NULL)
    {
    return(0);
    }
    
    else if(((arbol->izq)==NULL) and ((arbol->der)==NULL))
    return(1);
    
    else return(cueho(arbol->izq)+cueho(arbol->der));
    
}
//--------------------------------------------------------
int buscapadre(ABB &arbol, int n)
{
    if (arbol==NULL)
    return(0);
    else
    {
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
//------------------------------------------------------------

