//Complejidad: O(log(n))
//Función que verifica si el grafo es es un árbol
bool isTree(struct Node* head, int nodos, int arcos){
	int numRaices=0;
	bool parents=true;

	//Recorremos la lista principal hasta encontrar null
	while(head->next!=NULL){
		//Actualizamos la head al nodo principal
		head=head->next;
		//Verificamos que sólo haya una raíz
		if(head->padres==0)
			numRaices+=1;
			
		//Creamos un pointer auxiliar que apunte a la lista de adyacencias del principal
		struct NodeAdyacente* aux=head->adyacente;

		//Recorremos toda la lista de adyacencia
        while(aux!=NULL){
        	//Le sumamos sus padres
        	aux->realNode->padres+=1;
        	//En caso de haber más de un padre significa que no es un árbol
        	if(aux->realNode->padres>1)
        		parents=false;

        	aux=aux->next;
        }
	}
	//En caso de haber más raíces o más de un padre se regresa un false
	if(numRaices>1 || !parents)
		return 0;

	return 1;
}