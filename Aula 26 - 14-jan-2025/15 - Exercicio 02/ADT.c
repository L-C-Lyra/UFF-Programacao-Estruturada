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

    printf("-");
    do{
        printf("> %4d -", node -> info);
        node = node -> next_node;
    }while(node != l_list);

    printf("|\n");
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

int rec_circ_list_largest_elem(tList * l_list, tList * node, int largest_elem){
    if(node == l_list){
        return largest_elem;
    }

    if(node -> info > largest_elem){
        largest_elem = node -> info;
    }

    return rec_circ_list_largest_elem(l_list, node -> next_node, largest_elem);
}

int circ_list_largest_elem(tList * l_list){
    if(l_list == NULL){
        return -1;
    }

    return rec_circ_list_largest_elem(l_list, l_list -> next_node, l_list -> info);
}
