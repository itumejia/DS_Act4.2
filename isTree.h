//Complejidad: O(log(n))
//Función que verifica si el grafo es es un árbol
bool isTree(struct Node* head, int nodos, int arcos){
	int numRaices=0;

	//Recorremos la lista principal hasta encontrar null
	while(head->next!=NULL){
		//Actualizamos la head al nodo principal
		head=head->next;
		//Verificamos que sólo haya una raíz
		if(head->padres==0){
			numRaices+=1;
			//En caso de haber más raíces se regresa un false
			if(numRaices>1)
				return 0;
		}
		//Creamos un pointer auxiliar que apunte a la lista de adyacencias del principal
		struct NodeAdyacente* aux=head->adyacente;

		//Recorremos toda la lista de adyacencia
        while(aux!=NULL){
        	//Le sumamos sus padres
        	aux->realNode->padres+=1;
        	//En caso de haber más de un padre significa que no es un árbol
        	if(aux->realNode->padres>1)
        		return 0;
        	aux=aux->next;
        }
	}
	return 1;
}