#include <stdio.h>
#include <stdlib.h>

void foo1(void){
    printf("I'm a function 1\n");
}
void foo2(void){
    printf("I'm a function 2\n");
}
void none(void){
    printf("I'm a function NONE\n");
}


int main(int argc, char **argv){         //(void)
//    switch(argc){
//     case 1:
//         foo1();
//         break;
//     case 2:
//         foo2();
//         break;
//     default:
//         none();
//         break;
//    }
void(*f[])(void) = {none, foo1, foo2};
if(argc>2){
    argc = 0;
}
f[argc]();
    
    return EXIT_SUCCESS;
}
