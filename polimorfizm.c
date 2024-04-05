// #include <stdio.h>
// #include <stdlib.h>

// int getMaxInt(int *, unsigned int); //wykona program mimo ze funkcja jest pod main
// double getMaxDouble(double *, unsigned int);

// int main(void)
// {
//     int tabOfInts[] = {3, 2, 1, 5, 6, 4};
//     printf("max=%d\n", getMaxInt(tabOfInts, 6));

//     double tabOfDoubles[] = {3.3, 2.2, 1.1, 5.5, 6.6, 4.4};
//     printf("max=%f\n", getMaxDouble(tabOfDoubles, 6));


//     return EXIT_SUCCESS;
// }

// int getMaxInt(int *tab, unsigned int size){
//     int i;
//     int max = tab[0];

//     for( i=1; i<size; i++){
//         if(tab[i] > max){
//             max = tab[i];
//         }
//     }
//     return max;
// }
// double getMaxDouble(double *tab, unsigned int size){
//     int i;
//     double max = tab[0];

//     for( i=1; i<size; i++){
//         if(tab[i] > max){
//             max = tab[i];
//         }
//     }
//     return max;
// }

//modyfikacja - uzycie enum

// #include <stdio.h>
// #include <stdlib.h>

// enum argumentType {INT, DOUBLE};

// void getMax(void *tabPoly, unsigned int size, enum argumentType type);

// int main(void)
// {
//     int tabOfInts[] = {3, 2, 1, 5, 6, 4};

//     double tabOfDoubles[] = {3.3, 2.2, 1.1, 5.5, 6.6, 4.4};

//     getMax(tabOfInts, 6, INT);
//     getMax(tabOfDoubles, 6, DOUBLE);

//     return EXIT_SUCCESS;
// }

// void getMax(void * tabPoly, unsigned int size, enum argumentType type){
//     int i;

//     if(type == INT){
//         int max;
//         int *tab = (int *)tabPoly; //przeksztalcenie wskaznika wskazujacego na nic na wskazujacego na inty
    
//     max = tab[0];
//     for( i=1; i<size; i++){
//         if(tab[i] > max){
//             max = tab[i];
//         }
//     }
//     printf("max=%d\n", max);
//     }

//     if(type == DOUBLE){
//         double max;
//         double *tab = (double *)tabPoly; //przeksztalcenie wskaznika wskazujacego na nic na wskazujacego na inty
    
//     max = tab[0];
//     for( i=1; i<size; i++){
//         if(tab[i] > max){
//             max = tab[i];
//         }
//     }
//     printf("max=%0.2f\n", max);
//     }
// }

// modyfikacja - uzycie struct

// #include <stdio.h>
// #include <stdlib.h>

// enum argumentType {INT, DOUBLE};

// struct polyType{
//     int i;
//     double d;
// };


// struct polyType getMax(void *tabPoly, unsigned int size, enum argumentType type);

// int main(void)
// {
//     int tabOfInts[] = {3, 2, 1, 5, 6, 4};
//     double tabOfDoubles[] = {3.3, 2.2, 1.1, 5.5, 6.6, 4.4};

//     struct polyType result1, result2;

//     result1 = getMax(tabOfInts, 6, INT);
//     result2 = getMax(tabOfDoubles, 6, DOUBLE);

//     printf("max=%d\n", result1.i);
//     printf("max=%0.1f\n", result2.d);


//     return EXIT_SUCCESS;
// }

// struct polyType getMax(void * tabPoly, unsigned int size, enum argumentType type){
//     int i;
//     struct polyType result;

//     if(type == INT){
//         int max;
//         int *tab = (int *)tabPoly; //przeksztalcenie wskaznika wskazujacego na nic na wskazujacego na inty
    
//         max = tab[0];
//         for( i=1; i<size; i++){
//             if(tab[i] > max){
//                 max = tab[i];
//             }
//         }
//         result.i = max;
//     }

//     if(type == DOUBLE){
//         double max;
//         double *tab = (double *)tabPoly; //przeksztalcenie wskaznika wskazujacego na nic na wskazujacego na inty
    
//         max = tab[0];
//         for( i=1; i<size; i++){
//             if(tab[i] > max){
//                 max = tab[i];
//             }
//         }
//         result.d = max;
//     }
//     return result;
// }

// modyfikacja - zmiana struct na union

// #include <stdio.h>
// #include <stdlib.h>

// enum argumentType {INT, DOUBLE};

// struct polyType{ // mozna usunac
//     int i;
//     double d;
// };

// union polyTypeU{
//     int i;
//     double d;
// };


// union polyTypeU getMax(void *tabPoly, unsigned int size, enum argumentType type);

// int main(void)
// {
//     int tabOfInts[] = {3, 2, 1, 5, 6, 4};
//     double tabOfDoubles[] = {3.3, 2.2, 1.1, 5.5, 6.6, 4.4};
//     union polyTypeU result1, result2;
//     //eksperyment co ile ma miejsca w B (mozna usunac)
//     printf("%d\n", sizeof(int));
//     printf("%d\n", sizeof(double));
//     printf("%d\n", sizeof(struct polyType));
//     printf("%d\n", sizeof(union polyTypeU));
//     //eksperyment

//     result1 = getMax(tabOfInts, 6, INT);
//     result2 = getMax(tabOfDoubles, 6, DOUBLE);

//     printf("max=%d\n", result1.i);
//     printf("max=%0.1f\n", result2.d);


//     return EXIT_SUCCESS;
// }

// union polyTypeU getMax(void * tabPoly, unsigned int size, enum argumentType type){
//     int i;
//     union polyTypeU result;

//     if(type == INT){
//         int max;
//         int *tab = (int *)tabPoly; //przeksztalcenie wskaznika wskazujacego na nic na wskazujacego na inty
    
//         max = tab[0];
//         for( i=1; i<size; i++){
//             if(tab[i] > max){
//                 max = tab[i];
//             }
//         }
//         result.i = max;
//     }

//     if(type == DOUBLE){
//         double max;
//         double *tab = (double *)tabPoly; //przeksztalcenie wskaznika wskazujacego na nic na wskazujacego na inty
    
//         max = tab[0];
//         for( i=1; i<size; i++){
//             if(tab[i] > max){
//                 max = tab[i];
//             }
//         }
//         result.d = max;
//     }
//     return result;
// }

// modyfikacja wstawienie powielenia w define

#include <stdio.h>
#include <stdlib.h>

#define FOO(x) (7*x*x) // mozna usunac, korzystane bylo do nauki

#define maxLoop(_max) \
    typeof(_max) max; \
    typeof(_max) *tab = (typeof(_max) *)tabPoly; \
    max = tab[0]; \
    for( i=1; i<size; i++){ \
        if(tab[i] > max){ \
            max = tab[i]; \
        } \
    }


enum argumentType {INT, DOUBLE};

union polyTypeU{
    int i;
    double d;
};

union polyTypeU getMax(void *tabPoly, unsigned int size, enum argumentType type);

int main(void)
{
    int tabOfInts[] = {3, 2, 1, 5, 6, 4};
    double tabOfDoubles[] = {3.3, 2.2, 1.1, 5.5, 6.6, 4.4};
    union polyTypeU result1, result2;

    printf("to odnosnie foo: %d\n", FOO(5)); //mozna usunac

    result1 = getMax(tabOfInts, 6, INT);
    result2 = getMax(tabOfDoubles, 6, DOUBLE);

    printf("max=%d\n", result1.i);
    printf("max=%0.1f\n", result2.d);


    return EXIT_SUCCESS;
}

union polyTypeU getMax(void * tabPoly, unsigned int size, enum argumentType type){
    int i;
    union polyTypeU result;
    int maxI;
    double maxD;

    if(type == INT){
        maxLoop(maxI)
        result.i = max;
    }
    else if(type == DOUBLE){
        maxLoop(maxD)
        result.d = max;
    }
    return result;
}
