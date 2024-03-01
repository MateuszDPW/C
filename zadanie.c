//tablica 2x3, user musi podac wszystkim wspolrzednym wartosci zeby wypelnic tablice
#include <stdio.h>

int main(){
    int v1[2][3], i, j;
    
    printf("Podaj wartości do tablicy:\n");
    for(i=0; i<2; i++){
        for(j=0; j<3; j++){
            scanf("%d", &v1[i][j]);
        }
        
    }
    printf("===================\n");
    
    for(i=0; i<2; i++){
        for(j=0; j<3; j++){
            printf("%d ", v1[i][j]);
        }
        printf("\n");
    }
    return 0;
}
