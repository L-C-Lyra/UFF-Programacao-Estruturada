typedef struct typeNode{
    int info;
    struct typeNode *next_node;
}tList;

void circ_listprint(tList * l_list){
    tList * node;
    node = l_list;

    if(l_list == NULL){
        printf("Lista Vazia.");

        return;
    }

    do{
        printf("%4d", node -> info);
        node = node -> next_node;
    }while(node != l_list);
}

int sizeof_circ_list(tList * l_list){
    if(l_list == NULL){
        return 0;
    }

    tList * node = l_list;
    int size_list = 0;

    do{
        size_list++;

        node = node -> next_node;
    }while(node != l_list);

    return size_list;
}

tList * nodealloc(){
    tList * temp;
    temp = (tList *) malloc(sizeof(tList));
    temp -> next_node = NULL;

    return temp;
}

tList * pos_circ_listalloc(tList * l_list, int elem, int pos){
    if((pos < 0) || (pos > sizeof_circ_list(l_list))){
        printf("Posicao Invalida.");

        return l_list;
    }

    tList * new_node = nodealloc();
    new_node -> info = elem;
    new_node -> next_node = new_node;

    if(l_list == NULL){
        return new_node;
    }else if(pos == 0){
        tList * last = l_list;

        do last = last -> next_node;
        while(last -> next_node != l_list);

        last -> next_node = new_node;
        new_node -> next_node = l_list;

        return new_node;
    }else{
        int i;
        tList * prev = l_list;

        for(i = 0; i < (pos - 1); i++){
            prev = prev -> next_node;
        }

        new_node -> next_node = prev -> next_node;
        prev -> next_node = new_node;

        return l_list;
    }
}

tList * circ_listfree(tList * l_list){
    if(l_list == NULL){
        return NULL;
    }

    tList * node = l_list;

    do{
        tList * temp = node -> next_node;
        free(node);
        node = temp;
    }while(node != l_list);

    return NULL;
}

tList * pos_circ_listfree(tList * l_list, int pos){
    if((pos < 0) || (pos > (sizeof_circ_list(l_list) - 1)) || (l_list == NULL)){
        printf("Posicao Invalida/Lista Vazia.");

        return l_list;
    }else if(pos == 0){
        tList * last = l_list;

        do last = last -> next_node;
        while(last -> next_node != l_list);

        if(last = l_list){
            free(l_list);

            return NULL;
        }else{
            last -> next_node = l_list -> next_node;
            free(l_list);

            return last -> next_node;
        }
    }else{
        int i;
        tList * prev = l_list;
        tList * rem_node;

        for(i = 0; i < (pos - 1); i++){
            prev = prev -> next_node;
        }

        rem_node = prev -> next_node;
        prev -> next_node = rem_node -> next_node;
        free(rem_node);

        return l_list;
    }
}

tList * circ_listconcatenate(tList * l_list_1, tList * l_list_2){
    if(l_list_1 == NULL){
        return l_list_2;
    }else if(l_list_2 == NULL){
        return l_list_1;
    }

    tList * node = l_list_1;

    do node = node -> next_node;
    while(node -> next_node != l_list_1);

    node -> next_node = l_list_2;

    do node = node -> next_node;
    while(node -> next_node != l_list_2);

    node -> next_node = l_list_1;

    return l_list_1;
}
