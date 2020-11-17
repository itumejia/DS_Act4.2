//Estructura para Nodo de la lista principal de la lista de adyacencias
struct Node{
    string id; //ID alfabético
    int nId; //ID numérico
    struct NodeAdyacente* adyacente; //Pointer a la lista de nodos adyacentes
    struct Node* next; //Pointer a siguiente nodo de la lista principal
    bool estado; //estado de cada nodo
    int padres; //número de padres que tiene cada nodo
};