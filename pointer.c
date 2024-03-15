#include <stdio.h>

void swap(int v, int w){
    int tmp;

    tmp = v;
    v = w;
    w = tmp;
}

void swapNew(int *v, int *w){
    int tmp;

    tmp = *v;
    *v = *w;
    *w = tmp;
}

int main(void){
    int x=2;
    int y=5;

    int *pointer; //wskaznik

    pointer = &x;
    printf("%d %d %d\n", x, y, *pointer); // 2 5 2

    pointer = &y;
    printf("%d %d %d\n", x, y, *pointer); // 2 5 5

    *pointer = 123;
    printf("%d %d %d\n", x, y, *pointer); // 2 123 123

    swap(x,y);
    printf("%d %d %d\n", x, y, *pointer); // 2 123 123
    
    swapNew(&x,&y);
    printf("%d %d %d\n", x, y, *pointer); // 123 2 2
    
    return 0;
}
