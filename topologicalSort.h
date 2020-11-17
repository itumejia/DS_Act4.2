//Función que devuelve un vector cuyos nodos no tengan padres
vector <Node *> findZeros(struct Node* head, int nodos){
	//Definimos al head como el primer nodo de la lista principal
	head=head->next;
	//Creamos el vector que regresaremos
	vector <Node *> vectorZeros;
	//Recorremos la lista principal
	for(int i=0; i<nodos; i++){
		//Metemos al vector a los nodos que no tienen padres
		if(head->padres==0)
			vectorZeros.push_back(head);
		head=head->next;
	}
	return vectorZeros;
}

//Función que ordena los nodos utilizando el algoritmo de Kahn
void topologicalSort(struct Node* head, int nodos, int arcos){
	vector <Node *> vecZeros;
	queue <Node *> queueZeros;
	struct Node* toPrint;

	//Creamos vector con la función findZeros
	vecZeros=findZeros(head, nodos);
	//Metemos a la cola los nodos que no tienen padres
	for(int i=0; i<vecZeros.size(); i++)
		queueZeros.push(vecZeros[i]);

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
}