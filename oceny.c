#include <stdio.h>
#include <stdlib.h>
#define MENU_SIZE 3
//dynamiczna tablica uczniów[imie, nazwisko, oceny], dodawac ich informacje, jak chcemy dodac kolejnego to rezerwujemy kolejne miejsce i dodajemy nowego ucznia 

enum optionCode {UNDEFINED, PRINT_ALL, ADD_PERSON, QUIT};
//struktura ucznia
struct uczen{
    char imie[15];
    char nazwisko[20];
    int oceny[5];
};
//struktura opcji w menu
struct option {
  enum optionCode code;
  char letter[2];
  char text[32];
};
//dostepne opcje programu
struct option options[MENU_SIZE] = {
  {PRINT_ALL, "a", "Wypisz wszystkie osoby"},
  {ADD_PERSON, "d", "Dodaj nową osobę"},
  {QUIT, "q", "Wyjście"}
};

void wypisz(struct uczen s){
  printf("%s %s, oceny: %d\n", s.imie, s.nazwisko, s.oceny);
}

//wyswietlenie menu
enum optionCode menu() {
  char buffer[5];
  int i;

  for (i=0; i<MENU_SIZE; i++){
    printf("[%s] %s\n", options[i].letter, options[i].text);
  }

  printf("Podaj opcję: ");

  fgets(buffer, 4, stdin);
  buffer[strlen(buffer)-1] = '\0';

  printf("Dokonany wybór: %s\n", buffer);

  for (i=0; i<MENU_SIZE; i++) {
    if (strcmp(buffer, options[i].letter) == 0) {
      return options[i].code;
    }
  }

  return UNDEFINED;
}

void init(struct uczen tab[], int index){
  tab[index].imie = "";
  tab[index].nazwisko = "";
  tab[index].oceny = 0;
}

void executeAction(enum optionCode choice, struct uczen tab[]){
  switch(choice) {
    case PRINT_ALL:
      printAll(tab);
      break;
    case SET_SELECTED:
      setSelected(tab);
      break;
    case SET_FREE:
      setFree(tab);
      break;
    case RESET_SELECTED:
      resetSelected(tab);
      break;
    case PRINT_STAT:
      printStat(tab);
      break;
  }
}


int main(){
    int i;
    enum optionCode choice = PRINT_ALL;

    for(i=0; i<TAB_SIZE; i++){
        init(tab, i);
    }

    while(choice != QUIT){
        choice = menu();
        executeAction(choice, tab);
    }

    return 0;
}
