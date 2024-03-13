#include<stdio.h>
#include<string.h>
#define vertex 6
int main() {
    // int vertex;
    // printf("Enter the number of Vertices: ");
    // scanf("%d", &vertex);
    // printf("Enter the Names of the Vertices: ");
    char str[vertex] = {'P', 'Q', 'R', 'S', 'T', 'U'};
    // for (int i = 0; i < vertex; i++)
    //     scanf("%c", &str[i]);
    int matrix[vertex][vertex];

    for (int i = 0; i < vertex; i++)
        for (int j = 0; j < vertex; j++)
            matrix [i][j] = 0;


    // for (int i = 0; i < vertex; i++)
    //     for (int j = 0; j < vertex; j++) {
    //         printf("Adjacency_Matrix [%d] [%d] = ", i, j);
    //         scanf("%d", &matrix [i][j]);  
    //     }
    matrix [0][1] = 1;
    matrix [0][3] = 6;
    matrix [0][4] = 7;
    matrix [1][2] = 1;
    matrix [1][3] = 4;
    matrix [2][3] = 3;
    matrix [2][5] = 1;
    matrix [3][4] = 3;
    matrix [3][5] = 2;
    matrix [4][5] = 2;
    
    printf("The Matrix is: \n");
    for (int k = 0; k < vertex; k++)
        printf("\t%c", str[k]);
    printf("\n\n");
    for (int i = 0; i < vertex; i++) {
        printf("%c", str[i]);
        for (int j = 0; j < vertex; j++)
            printf("\t%d", matrix[i][j]);
        printf("\n");
    }
}