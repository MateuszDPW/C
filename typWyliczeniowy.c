#include <stdio.h>

enum boolean {TRUE = 17, FALSE=122};        //typ wyliczeniowy
enum dniTygodnia {PN,WT,SR,CZ,PT,SOB,NDZ};


int main()
{
    enum boolean x;
    
    x = FALSE;
    printf("%d\n", x);
    
    x = TRUE;
    printf("%d\n", x);
    
    
    if(x == TRUE){
    printf("!!!\n");
        
    }
    x = 123;
    printf("%d\n", x);
    
    
    enum dniTygodnia dzien;
    
    dzien = PT;
    
    switch(dzien){
        case PN:
            printf("Poniedzialek");
            break;
        case WT:
            printf("Wtorek");
            break;
        case SR:
            printf("Sroda");
            break;
        case CZ:
            printf("Czwartek");
            break;
        case PT:
            printf("Piatek");
            break;
        case SOB:
            printf("Sobota");
            break;
        case NDZ:
            printf("Niedziela");
            break;
            
    }
    return 0;
}
