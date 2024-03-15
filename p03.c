#include <stdio.h>
int main(void) {
    int tab[3] = {3,5,7};
    int *p;

printf("%d\n", tab[0]);
printf("%d\n", *tab);

p= tab; // bo ++tab nie dziala
printf("%d\n", tab[1]);
printf("%d\n", *(++p));
printf("%d\n", *(tab+1));

    return 0;
}
