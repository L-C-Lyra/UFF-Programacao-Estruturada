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

void pos_listprint(tList * l_list, int pos){
    int i, cont;
    tList * node = l_list;

    if(node == NULL){
        printf("Lista Vazia.");

        return;
    }

    cont = 1;
    while(node -> next_node != NULL){
        node = node -> next_node;
        cont++;
    }

    if(pos > cont){
        printf("Posicao Invalida.");

        return;
    }

    node = l_list;

    for(i = 0; i < (cont - pos); i++){
        node = node -> next_node;
    }

    printf("%d Ultimos Elementos: ", pos);
    while(node != NULL){
        printf("%4d", node -> info);
        node = node -> next_node;
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

tList * duplicate_noderemove(tList * l_list){
    tList * node = l_list;

    if(node == NULL){
        return NULL;
    }

    while(node -> next_node != NULL){
        if(node -> info == node -> next_node -> info){
            tList * temp = node -> next_node;
            node -> next_node = node -> next_node -> next_node;
            free(temp);
        }else{
            node = node -> next_node;
        }
    }

    return l_list;
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

tList * listreverse(tList * l_list){
    tList * curr = l_list;
    tList * prev = NULL;
    tList * post = NULL;

    while(curr != NULL){
        post = curr -> next_node;
        curr -> next_node = prev;
        prev = curr;
        curr = post;
    }

    return prev;
}

int list_is_sorted(tList * l_list){
    if(l_list == NULL){
        return 1;
    }else{
        int value = l_list -> info;
        tList * node = l_list -> next_node;

        while(node != NULL){
            if(node -> info < value){
                return 0;
            }

            value = node -> info;
            node = node -> next_node;
        }
    }

    return 1;
}


void listbubblesort(tList * l_list){
    tList * i, * j;
    int temp;

    i = l_list;

    while(i != NULL){
        j = l_list;

        while(j -> next_node != NULL){
            if(j -> info > j -> next_node -> info){
                temp = j -> info;
                j -> info = j -> next_node -> info;
                j -> next_node -> info = temp;
            }

            j = j -> next_node;
        }

        i = i -> next_node;
    }
}

int list_has_loop(tList * l_list){
    tList * ll_1, * ll_2;
    ll_1 = l_list;
    ll_2 = l_list;

    if(l_list == NULL){
        return 0;
    }

    do {
        ll_1 = ll_1 -> next_node;

        ll_2 = ll_2 -> next_node;
        if (ll_2 != NULL) {
            ll_2 = ll_2 -> next_node;
        }
    } while((ll_1 != NULL) && (ll_2 != NULL) && (ll_1 != ll_2));

    if(ll_1 == ll_2){
        return 1;
    }
    return 0;
}

tList * listconcatenate(tList * l_list_1, tList * l_list_2){
    tList * node = l_list_1;

    if(node == NULL){
        return l_list_2;
    }

    while(node -> next_node != NULL){
        node = node -> next_node;
    }

    node -> next_node = l_list_2;

    return l_list_1;
}

tList * listmerge(tList * l_list_1, tList * l_list_2){
    if(l_list_1 == NULL){
        return l_list_2;
    }else if(l_list_2 == NULL){
        return l_list_1;
    }

    tList * ll_1, * ll_2, * first, * last;
    ll_1 = l_list_1;
    ll_2 = l_list_2;

    if(ll_1 -> info < ll_2 -> info){
        first = ll_1;
        last = ll_1;
        ll_1 = ll_1 -> next_node;
    }else{
        first = ll_2;
        last = ll_2;
        ll_2 = ll_2 -> next_node;
    }

    while((ll_1 != NULL) && (ll_2 != NULL)){
        if(ll_1 -> info < ll_2 -> info){
            last -> next_node = ll_1;
            ll_1 = ll_1 -> next_node;
        }else{
            last -> next_node = ll_2;
            ll_2 = ll_2 -> next_node;
        }

        last = last -> next_node;
    }

    if(ll_1 != NULL){
        last -> next_node = ll_1;
    }else if(ll_2 != NULL){
        last -> next_node = ll_2;
    }

    return first;
}
