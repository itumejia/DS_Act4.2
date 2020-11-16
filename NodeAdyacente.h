//Estructura para Nodo de la lista de nodos adyacentes de la lista de adyacencias

struct NodeAdyacente{
    struct Node* realNode; //Pointer a nodo correspondiente de la lista principal
    struct NodeAdyacente* next; //Pointer a siguiente nodo adyacente
};