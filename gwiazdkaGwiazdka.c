#include <stdio.h>

int main(int argc, char **argv){
printf("Liczba argumentow: %d\n", argc);

for (int i=0;i<argc;i++){
    printf("argument %d: %s\n", i, argv[i]);
}

return 0;
}
