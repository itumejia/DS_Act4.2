//TC1031.500
//Myroslava Sánchez Andrade A01730712
//Ituriel Mejía Garita A01730875
//Fecha: 15/11/2020
//Act 4.2 - Grafos: Algoritmos complementarios 

//Se agregan librerías
#include "iostream"
#include "string"
using namespace std;

//Incluimos los archivos
#include "toLetters.h"
#include "Node.h"
#include "NodeAdyacente.h"
#include "loadGraph.h"
#include "printList.h"
//#include "isTree.h"



int main(){
	//bool tree;
	int nNodos,nArcos;
    cin>>nNodos;
    cin>>nArcos;

    struct Node* head=loadGraph(nNodos, nArcos);
    //tree=isTree(head, );
    return 0;
}
