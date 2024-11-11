#include <stdio.h>
#include <stdlib.h>

int ** matalloc(int m, int n){
    int i;
    int ** mat;

    mat = (int **) malloc(m * sizeof(int *));
    for(i = 0; i < n; i++){
        mat[i] = (int *) malloc(n * sizeof(int));
    }

    return mat;
}

void matfree(int m, int n, int ** mat){
    int i;

    for(i = 0; i < n; i++){
        free(mat[i]);
    }
    free(mat);
}

void matread(int m, int n, int ** mat){
    int i, j;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
        printf("\n");
    }
}

void matprint(int m, int n, int ** mat){
    int i, j;

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int menu(){
    int opt;

    printf("---------- Menu ----------\n");
    printf("1. Grau de Conexao\n");
    printf("2. Cidade Facil de Chegar\n");
    printf("3. Roteiro Possivel\n");
    printf("4. Caminho (Indisponivel)\n");
    printf("10. Sair\n");
    printf("--------------------------\n");
    printf("Opcao: ");
     scanf("%d", &opt);

    return opt;
}

void connect_degree(int ** mat, int m, int n){
    int c, i;
    int  in = 0;
    int out = 0;

    printf("---- Grau de Conexao -----\n");

    printf("Cidade? ");
    scanf("%d", &c);

    for(i = 0; i < m; i++){
        out += mat[c][i];
    }
    for(i = 0; i < n; i++){
         in += mat[i][c];
    }

    printf("Sai(aem) %d Estrada(s) e Entra(m) %d Estrada(s) na Cidade %d.\n", out - 1, in - 1, c);
    printf("--------------------------\n");
}

void easy_come(int ** mat, int m, int n){
    int c, i, j;
    int sum = 0;
    int max_sum = 0;

    printf("- Cidade Facil de Chegar -\n");

    for(j = 0; j < n; j++){
        sum = 0;
        for(i = 0; i < m; i++){
            sum += mat[i][j];
        }

        if((j == 0) || (sum > max_sum)){
            max_sum = sum;
            c = j;
        }
    }

    printf("Pela Cidade %d chegam o MAIOR Numero de Estradas = %d.\n", c, max_sum - 1);
    printf("--------------------------\n");
}

void possible_it(int ** mat, int m, int n){
    int n_c, i, aux;
    int * vet_c;

    printf("---- Roteiro Possivel ----\n");

    printf("Quantas Cidades no Roteiro? ");
    scanf("%d", &n_c);

    vet_c = (int *) malloc(n_c * sizeof(int));

    for(i = 0; i < n_c; i++){
        printf("   Cidade %d: ", i + 1);
        scanf("%d", &vet_c[i]);
    }

    for(i = 0; i < n_c - 1; i++){
        if(mat[vet_c[i]][vet_c[i + 1]] == 0){
            printf("A Viagem EH IMPOSSIVEL.\n");
            printf("NAO EXISTE Estrada da Cidade %d para a Cidade %d.\n", vet_c[i], vet_c[i + 1]);

            return;
        }
    }

    printf("A Viagem EH POSSIVEL.\n");
    printf("--------------------------\n");

    free(vet_c);
}

int main(){
    int m = 5;
    int n = 5;
    int opt;
    int ** mat_m = matalloc(m, n);

    mat_m[0][0] = 1;    mat_m[0][1] = 1;    mat_m[0][2] = 0;    mat_m[0][3] = 0;    mat_m[0][4] = 0;
    mat_m[1][0] = 0;    mat_m[1][1] = 1;    mat_m[1][2] = 1;    mat_m[1][3] = 0;    mat_m[1][4] = 0;
    mat_m[2][0] = 1;    mat_m[2][1] = 0;    mat_m[2][2] = 1;    mat_m[2][3] = 0;    mat_m[2][4] = 1;
    mat_m[3][0] = 1;    mat_m[3][1] = 0;    mat_m[3][2] = 0;    mat_m[3][3] = 1;    mat_m[3][4] = 0;
    mat_m[4][0] = 1;    mat_m[4][1] = 0;    mat_m[4][2] = 0;    mat_m[4][3] = 1;    mat_m[4][4] = 1;

    printf("Matriz M: \n");
    matprint(m, n, mat_m);

    opt = menu();
    while(opt != 10){
        switch(opt){
        case 1:
            connect_degree(mat_m, m, n);
            break;

        case 2:
            easy_come(mat_m, m, n);
            break;

        case 3:
            possible_it(mat_m, m, n);
            break;

        default:
            printf("Opcao Invalida.\n");
        }
        opt = menu();
    }

    printf("Fim.");

    matfree(m, n, mat_m);
    return 0;
}
