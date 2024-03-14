//dodawanie do siebie dwoch tablic o tym samym rozmiarze

#include <stdio.h>
#define  TAB_SIZE 6

int main()
{
    int vector1[TAB_SIZE] = {1,2,3,4,5,6};
    int vector2[TAB_SIZE] = {1,2,3,4,5,6};
    
    int sumVector[TAB_SIZE];
    

    for (int i = 0; i<TAB_SIZE; i++){
        sumVector[i] = vector1[i] + vector2[i];
        printf("%d\n", sumVector[i]);
    }
    return 0;
}


//dodawanie tablic 2d i 3d
#include <stdio.h>

#define  _3D 3
#define  _2D 2

void addV(int x[], int y[], int v[], int size){
    int s;
    
    for(s=0; s<size ;s++){
        v[s] = x[s] + y[s];
    }
}



int main()
{
    int v1_3d[_3D] = {1,2,3};
    int v2_3d[_3D] = {4,5,6};
    int v_3d[_3D];
    
    int v1_2d[_2D] = {1,2};
    int v2_2d[_2D] = {4,5};
    int v_2d[_2D];
    
    int i;
    
    addV(v1_3d, v2_3d, v_3d, _3D);
    
    for(i=0; i<_3D; i++){
        printf("%d\n", v_3d[i]);
    }
    
    printf("=======================\n");
    
    addV(v1_2d, v2_2d, v_2d, _2D);
    
    for(i = 0; i<_2D; i++){
        printf("%d\n", v_3d[i]);
    }
    
    printf("=======================\n");
    
    addV(v1_3d, v2_2d, v_3d, _3D);
        for( i=0; i<_3D; i++){
            printf("%d\n", v_3d[i]);
        }
    
    printf("=======================\n");
    
    return 0;
}

// nie wiem co

#include <stdio.h>

int main()
{
    char a[3] = {1,2,3};
    short int b[3] = {4,5,6};
    short int c[3] = {7,8,9};
    
    /*int a[3] = {1,2,3};
    int x = 100;
    int b[3] = {4,5,6};
    int y = 200;
    int c[3] = {7,8,9};
    printf("%d\n", a[3]);
    */
    //printf("%ld\n", sizeof(short int)); // sizeof sprawdza ile pamieci zajmuje cos
    
    printf("%d\n", b[3]);
    
    return 0;
}

//cos dalej na tablicach i o łapce
#include <stdio.h>

void cosInnego(int x[]){
    x[0] = 6;
    printf("%d\n", x[0]);
    
}

int main()
{
    int y[] = {7};
    
    cosInnego(y);
    
    printf("%d\n", y[0]);
    
    return 0;
}


//struktura, dodawanie dwoch wektorow do siebie
#include <stdio.h>

struct vector3D{
    int components[3];
    int size;
};

struct vector3D initV3D(struct vector3D v){
    v.size = 3;
    for (int i = 0; i<v.size; i++){
        v.components[i] = i+1;
    }
    return v;
}



int main()
{
    struct vector3D v1, v2;
    
    
    v1 = initV3D(v1);
    v2 = initV3D(v2);
    int v3[3];
    
    for(int i = 0; i<v1.size; i++){
        v3[i] = v1.components[i] + v2.components[i];
        printf("%d\n", v3[i]);
    }
    
    
    return 0;
}

//to samo, wersja pana, na wiecej funkcji
#include <stdio.h>

struct vector3D{
    int components[3];
    int size;
};

struct vector3D initV3D(struct vector3D v){
    v.size = 3;
    for (int i = 0; i<v.size; i++){
        v.components[i] = 1;
    }
    return v;
}

struct vector3D addV3D(struct vector3D x, struct vector3D y){
    int s;
    
    struct vector3D z;
    z.size = x.size;
    
    for(s=0; s<z.size; s++){
        z.components[s] = x.components[s] + y.components[s];
    }
    return z;
}

void printV3D(struct vector3D v){
    for(int i=0; i<v.size; i++){
        printf("%d ", v.components[i]);
    }
        printf("\n");
}


int main()
{
    struct vector3D v1, v2={{4,5,6}, 3}, v;     //pierwszy sposób inicjalizacji - podczas tworzenia v2
    
    v1.size = 3;
    v1.components[0] = 1;
    v1.components[1] = 2;   //drugi ze sposobów inicjacji
    v1.components[2] = 3;
    
    printV3D(v1);  
    printV3D(v2);
    
    v = addV3D(v1,v2);
    
    printV3D(v);
    
    return 0;
}
