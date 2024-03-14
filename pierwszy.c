#include <stdio.h>

int main(){

    for(int i=0; i<6; i++){
        for(int j=0; j<i ;j++){
        printf("*");
        }
        printf("\n");
    }
    
    for(int poziom=0; poziom<5; poziom++){
            switch(poziom){
                case 4:
                    printf("*");
                case 3:
                    printf("*");
                case 2:
                    printf("*");
                case 1:
                    printf("*");
                case 0:
                    printf("*");
            }
            printf("\n");
        }

    int i;
    int t [5] = {1,2,4,87,89,90};
    int g [3] = {100,101,102};
    
    for (i=0; i<8; i++){
        printf("%d \n", t[i]);
    }



    int x,i,t[5];
    
    for (i=0; i<5; i++){
        scanf("%d", &x);
        t[i] = x;
    }
    for (i=0;i<5;i++){
        printf("%d\n", t[i]);
        
    }

    int m[3][2] = {{1,2}, {3,4}, {5,6}};
    int n[][2] = {{1,2}, {3,4}, {5,6}};
    int o[3][2] = {1,2,3,4,5,6};

//program robiacy tablice z 0 i 1
//program gra w statki
//program przeliczajacy decymalne na binarne
char x;
    x=0;
    printf("%d\n", x);
    x = x | 1;
    printf("%d\n", x);
    x = x <<1;
    printf("%d\n", x);
    x = x | 1;
    printf("%d\n", x);
    x = x <<2;
    printf("%d\n", x);
    

    return 0;
}
