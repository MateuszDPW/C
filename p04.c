#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int main(void){
    int *tabM;
    int *tabC;

    tabM = malloc(sizeof(int)*SIZE);
    tabC = calloc(SIZE, sizeof(int));

    if (tabM != NULL){
        for(int i=0;i<SIZE;i++){
            printf("%d\n", tabM[i]);
        }
    }
    if (tabC != NULL){
        for(int i=0;i<SIZE;i++){
            printf("%d\n", tabC[i]);
        }
    }

    free(tabM);
    free(tabC);

    return 0;
}
