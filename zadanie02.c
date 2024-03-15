#include <stdio.h>
struct aa {
    int x;
    float y;
};

struct bb {
    int x;
    float y;
    struct aa z;
};
int main(){
    struct aa s1;
    struct bb s2;

    struct aa tab[10];
    
    s1.x = 2;
    s1.y = 1.5;

    s2.x = 3;
    s2.y = 4.5;
    s2.z = s1;

    printf("s1.x=%d\n", s1.x);
    printf("s1.y=%.1f\n", s1.y);
    printf("\ns2.x=%d\n", s2.x);
    printf("s2.y=%.1f\n", s2.y);
    printf("s2.z.x=%d\n", s2.z.x);
    printf("s2.z.y=%.1f\n", s2.z.y);

    tab[2].x = 2;

    for(int i = 0; i<6; i++){
        printf("%d\n",tab[i].x);
    }

    return 0;
}
