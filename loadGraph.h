//Función auxiliar que encuentra un nodo en la lista dado su id alfabético, regresa su dirección de memoria
struct Node* findRealNode(struct Node* head,string l){
    //Recorre toda la lista hasta encontrar el indicado
    while(true){
        if(head->next->id==l){
            return head->next;
        }
        else{
            head=head->next;
        }
    }
}

struct Node* loadGraph(int nNodos, int nArcos){
    struct Node* head=new Node;
    head->id="head";
    

    struct Node* actual=head;//Nodo que recorrerá la lista principal
    
    //Este ciclo construye la lista principal (aun sin adyacencias)
    for(int i=0;i<nNodos;i++){
        //Se crea nuevo nodo con informacion correspondiente
        struct Node* nuevo= new Node;
        nuevo->id=toLetters(i+1); //Se utiliza to letters para obtener indice alfabético
        nuevo->nId=i;
        nuevo->adyacente=NULL;
        nuevo->estado=0;
        nuevo->padres=0;
        //Se agrega a la lista
        actual->next=nuevo;
        actual=actual->next;
    }
    actual->next=NULL;//Lista termina con NULL

    string arc1, arc2;


    struct NodeAdyacente* aux;
    for(int i=0; i<nArcos;i++){
        actual=head;
        cin>>arc1;
        cin>>arc2;
        struct NodeAdyacente* nuevo=new NodeAdyacente;
        nuevo->realNode=findRealNode(head,arc2);
        nuevo->next=NULL;
        nuevo->realNode->estado=0;
        nuevo->realNode->padres=0;
        while(actual!=NULL){
            if(actual->id==arc1){
                if(actual->adyacente==NULL){  
                    actual->adyacente=nuevo;
                }
                else{
                    aux=actual->adyacente;
                    while(aux->next!=NULL){
                        aux=aux->next;
                    }
                    aux->next=nuevo;
                }

                break;
            }
            else{
                actual=actual->next;
            }
        }
    }

    return head;
}