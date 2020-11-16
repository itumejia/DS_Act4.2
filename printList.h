//Función que imprime lista de adyacencias con el formato correspondiente
void printList(struct Node* head){
    //Se recorre lista principal hasta encontrar NULL
    while(head->next!= NULL){
        struct NodeAdyacente* aux=head->next->adyacente;
        cout<< head->next->id<<" ";
        //Se recorre lista de nodos adyacentes hasta encontrar NULL
        while(aux!=NULL){
            cout<<"- "<<aux->realNode->id<<" ";
            aux=aux->next;
        }
        cout<<endl;
        head=head->next;
    }
}