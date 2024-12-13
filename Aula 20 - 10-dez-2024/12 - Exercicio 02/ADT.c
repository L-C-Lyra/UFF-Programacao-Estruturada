typedef struct typeNode{
    int info;
    struct typeNode *prev_node, *next_node;
}tList;

void listprint(tList * l_list){
    tList * node;
    node = l_list;

    while(node != NULL){
        printf("%4d", node -> info);
        node = node -> next_node;
    }
}

tList * nodealloc(){
    tList * temp;
    temp = (tList *) malloc(sizeof(tList));
    temp -> prev_node = NULL;
    temp -> next_node = NULL;

    return temp;
}

tList * pos_listalloc(tList * l_list, int elem, int pos){
    if(pos < 0){
        printf("Posicao Invalida.");

        return l_list;
    }else if((pos == 0) || (l_list == NULL)){
        tList * new_node = nodealloc();
        new_node -> info = elem;
        new_node -> prev_node = NULL;
        new_node -> next_node = l_list;

        if(l_list != NULL){
            l_list -> prev_node = new_node;
        }

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
        new_node -> prev_node = prev;
        new_node -> next_node = prev -> next_node;

        if(prev -> next_node != NULL){
            prev -> next_node -> prev_node = new_node;
        }

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
        if(l_list != NULL){
            l_list -> prev_node = NULL;
        }
        free(rem_node);

        return l_list;
    }else{
        int i;
        tList * rem_node = l_list;

        for(i = 0; i < pos; i++){
            rem_node = rem_node -> next_node;

            if(rem_node == NULL){
                printf("Posicao Invalida.");

                return l_list;
            }
        }

        if(rem_node -> prev_node != NULL){
            rem_node -> prev_node -> next_node = rem_node -> next_node;
        }
        if(rem_node -> next_node != NULL){
            rem_node -> next_node -> prev_node = rem_node -> prev_node;
        }
        free(rem_node);

        return l_list;
    }
}

tList * listinvert(tList * l_list){
    if((l_list == NULL) || (l_list -> next_node == NULL)){
        return l_list;
    }

    tList * node = l_list;
    tList * temp;

    while(node != NULL){
        temp = node -> next_node;
        node -> next_node = node -> prev_node;
        node -> prev_node = temp;

        if(node -> next_node != NULL){
            l_list = node;
        }

        node = temp;
    }

    return l_list;
}
