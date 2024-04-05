//dana jest tablica 10 intów, w zaleznosci od wywolania:
//PROG min - element minimalny
//PROG sort - posortowac dane
//PROG sort desc - posortowane malejaco
//PROG inRange min max T/F T/F - wypisac wszystkie wartosci o indeksach mieszczacych sie w zakresie
//0 1 2 3 4 5 - indeksy
//[1,2,3,4,5,6]
//PROG inRange 1,3 (czy te elementy tez wchodza w zakres)



#include <stdio.h>
#include <stdlib.h>
#define MENU_SIZE 3

enum optionCode {MIN, IN_RANGE, QUIT};

struct option {
  enum optionCode code;
  char letter[2];
  char text[32];
};

struct option options[MENU_SIZE] = {
  {MIN, "m", "Wypisz najmniejszą"},
  {IN_RANGE, "i", "Wypisz z zakresu"},
  {QUIT, "q", "Wyjście"}
};

int getMin(int *tab, unsigned int size){
    int i;
    int min = tab[0];

    for( i=1; i<size; i++){
        if(tab[i] < min){
            min = tab[i];
        }
        
    }
    return min;
}

int main()
{
    int tablica[] = {10,8,4,1,12,57,34,2,23,24};
    printf("min = %d\n", getMin(tabOfInts, 10));
    enum optionCode choice = MIN;




    return EXIT_SUCCESS;
}
