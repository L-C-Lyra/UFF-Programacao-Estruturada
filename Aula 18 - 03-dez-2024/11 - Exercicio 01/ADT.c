typedef struct typeNode{
    int info;
    struct typeNode *next_node;
}tList;

void listprint(tList * l_list){
    tList * node;
    node = l_list;

    while(node != NULL){
        printf("%4d", node -> info);
        node = node -> next_node;
    }
}

void rec_listprint(tList * l_list){
    if(l_list == NULL){
        return;
    }else{
        printf("%4d", l_list -> info);
        rec_listprint(l_list -> next_node);
    }
}

tList * nodealloc(){
    tList * temp;
    temp = (tList *) malloc(sizeof(tList));
    temp -> next_node = NULL;

    return temp;
}

tList * listalloc(tList * l_list, int elem){
    tList * new_node = nodealloc();
    new_node -> info = elem;
    new_node -> next_node = l_list;
    l_list = new_node;

    return l_list;
}

tList * pos_listalloc(tList * l_list, int elem, int pos){
    if(pos < 0){
        printf("Posicao Invalida.");

        return l_list;
    }else if(pos == 0){
        tList * new_node = nodealloc();
        new_node -> info = elem;
        new_node -> next_node = l_list;

        return new_node;
    }else{
        int i;
        tList * prev = l_list;

        for(i = 0; i < (pos - 1); i++){
            prev = prev -> next_node;

            if(prev == NULL){
                printf("Posicao Invalida.");

                return l_list;
            }
        }

        tList * new_node = nodealloc();
        new_node -> info = elem;
        new_node -> next_node = l_list;
        prev -> next_node = new_node;

        return l_list;
    }
}

tList * listfree(tList * l_list){
    tList * node = l_list;

    while(node != NULL){
        tList * temp = node -> next_node;
        free(node);
        node = temp;
    }

    return NULL;
}

tList * pos_listfree(tList * l_list, int pos){
    if((pos < 0) || (l_list == NULL)){
        printf("Posicao Invalida/Lista Vazia.");

        return l_list;
    }else if(pos == 0){
        tList * rem_node = l_list;
        l_list = l_list -> next_node;
        free(rem_node);

        return l_list;
    }else{
        int i;
        tList * rem_node = l_list;
        tList * prev;

        for(i = 0; i < pos; i++){
            prev = rem_node;
            rem_node = rem_node -> next_node;

            if(rem_node == NULL){
                printf("Posicao Invalida.");

                return l_list;
            }
        }

        prev -> next_node = rem_node -> next_node;
        free(rem_node);

        return l_list;
    }
}

tList * listsearch(tList * l_list, int elem){
    tList * node = l_list;

    while(node != NULL){
        if(node -> info == elem){
            return node;
        }

        node = node -> next_node;
    }

    return NULL;
}
