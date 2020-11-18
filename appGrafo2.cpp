//TC1031.500
//Myroslava Sánchez Andrade A01730712
//Ituriel Mejía Garita A01730875
//Fecha: 17/11/2020
//Act 4.2 - Grafos: Algoritmos complementarios 

//Se agregan librerías
#include "iostream"
#include "string"
#include "queue"
#include "vector"
using namespace std;

//Incluimos los archivos
#include "toLetters.h"
#include "Node.h"
#include "NodeAdyacente.h"
#include "loadGraph.h"
#include "isTree.h"
#include "topologicalSort.h"



int main(){
	bool tree;
	int nNodos,nArcos;
    //Se reciben como inputs el número de nodos y arcos
    cin>>nNodos;
    cin>>nArcos;

    //Creamos el pointer que apuntará a la lista
    struct Node* head=loadGraph(nNodos, nArcos);
    //Lammamos a la función isTree() para verificar si se trata de un árbol
    if(nNodos>=1 || nArcos>=1)
    	tree=isTree(head, nNodos, nArcos);
    
    if(tree)
    	cout<<"true"<<endl;
    else
    	cout<<"false"<<endl;

    //Hacemos el recorrido topolofical
    topologicalSort(head, nNodos, nArcos);

    return 0;
}
