//Función auxiliar que encuentra un nodo en la lista dado su id alfabético, regresa su dirección de memoria. Complejidad O(n)
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

//Función que carga los nodos y construye lista de adyacencias
//Complejidad O(nm), siendo n el número de nodos en la lista, y m el número de arcos que se deben generar 
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
    //El usuario ingresa los arcos
    for(int i=0; i<nArcos;i++){
        actual=head;
        cin>>arc1;
        cin>>arc2;
        //Inicializamos el nodo adyacente
        struct NodeAdyacente* nuevo=new NodeAdyacente;
        nuevo->realNode=findRealNode(head,arc2);
        nuevo->next=NULL;
        nuevo->realNode->estado=0;
        nuevo->realNode->padres=0;
        //Buscamos el nodo principal
        while(actual!=NULL){
            if(actual->id==arc1){
                //Se agrega el nodo adyacente si es el primero de la lista
                if(actual->adyacente==NULL){
                    actual->adyacente=nuevo;
                }
                else{
                    aux=actual->adyacente;

                    //Se inserta el nodo al inicio de la lista
                    if((aux->realNode->id)>(nuevo->realNode->id)){
                        nuevo->next=aux;
                        actual->adyacente=nuevo;
                    }
                    else{
                        while(aux->next!=NULL){
                            //Buscamos en dónde se debe insertar el nodo y se inseetar en la lista
                            if((aux->realNode->id<nuevo->realNode->id) && (aux->next->realNode->id>nuevo->realNode->id)){
                                nuevo->next=aux->next;
                                aux->next=nuevo;
                                break;
                            }
                            aux=aux->next;
                        }
                        //Se inserta el nodo al final de la lista
                        if(aux->next==NULL){
                            aux->next=nuevo;
                            nuevo->next=NULL;
                        }
                    }
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