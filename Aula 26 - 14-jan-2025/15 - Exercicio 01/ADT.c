typedef struct typeNode{
    int info;
    struct typeNode *next_node;
}tList;

void listprint(tList * l_list){
    tList * node;
    node = l_list;

    while(node != NULL){
        printf("%4d -> ", node -> info);
        node = node -> next_node;
    }

    printf("NULL\n");
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
    new_node -> next_node = NULL;

    if((l_list == NULL) || (l_list -> info >= elem)){
        new_node -> next_node = l_list;
        l_list = new_node;
    }else{
        tList * prev = l_list;

        while((prev -> next_node != NULL) && (prev -> next_node -> info < elem)){
            prev = prev -> next_node;
        }

        new_node -> next_node = prev -> next_node;
        prev -> next_node = new_node;
    }

    return l_list;
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
