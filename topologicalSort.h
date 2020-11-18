//Función que devuelve un vector cuyos nodos no tengan padres
queue <Node *> findZeros(struct Node* head, int nodos){
	//Definimos al head como el primer nodo de la lista principal
	head=head->next;
	//Creamos el vector que regresaremos
	queue <Node *> vectorZeros;
	//Recorremos la lista principal
	for(int i=0; i<nodos; i++){
		//Metemos al vector a los nodos que no tienen padres
		if(head->padres==0)
			vectorZeros.push(head);
		head=head->next;
	}
	return vectorZeros;
}

//Complejidad O(n), recorre toda la lista
//Función que ordena los nodos utilizando el algoritmo de Kahn
void topologicalSort(struct Node* head, int nodos, int arcos){
	if(nodos==0) return;
	
	struct Node* toPrint;
	//Creamos cola con la función findZeros
	queue <Node*> queueZeros=findZeros(head, nodos);

	while(!queueZeros.empty()){
		//Sacamos de la cola al primer nodo y lo imprimimos
		toPrint=queueZeros.front();
		struct NodeAdyacente* aux=toPrint->adyacente;
		queueZeros.pop();
		cout<<toPrint->id<<" ";

		//Recorremos la lista de adyacencias del nodo principal
		while(aux!=NULL){
			//Le restamos 1 a su atributo padres
			aux->realNode->padres-=1;
			//En caso de ya no tener padres se mete a la cola
			if(aux->realNode->padres==0)
				queueZeros.push(aux->realNode);
			aux=aux->next;
		}
	}
	cout<<endl;
}