#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define TAB_SIZE 10
#define MENU_SIZE 6

enum optionCode {UNDEFINED, PRINT_ALL, SET_SELECTED, SET_FREE, RESET_SELECTED, PRINT_STAT, QUIT};

struct skladowe {
  int x;
  int y;
};

struct option {
  enum optionCode code;
  char letter[2];
  char text[32];
};

struct option options[MENU_SIZE] = {
  {PRINT_ALL, "a", "Wypisz wszystkie"},
  {SET_SELECTED, "s", "Ustaw wybrany"},
  {SET_FREE, "f", "Ustaw pierwszy wolny"},
  {RESET_SELECTED, "r", "Resetuj wybrany"},
  {PRINT_STAT, "c", "Statystyka"},
  {QUIT, "q", "Wyjście"}
};

void wypisz(struct skladowe s){
  printf("%d %d\n", s.x, s.y);
}

void init(struct skladowe tab[], int index){
  tab[index].x = 0;
  tab[index].y = 0;
}

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

void printAll(struct skladowe tab[]);
void setSelected(struct skladowe tab[]);
void setFree(struct skladowe tab[]);
void resetSelected(struct skladowe tab[]);
void printStat(struct skladowe tab[]);

void executeAction(enum optionCode choice, struct skladowe tab[]){
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
  srand(time(NULL));

  struct skladowe tab[10];
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

int getIndex() {
  int idx;

  while (true) {
    printf("Podaj indeks elementu: ");
    scanf("%d", &idx);
    if (idx < 0 || idx > TAB_SIZE-1) {
      printf("Podany index nie należy do zakresu [0, %d]\n", TAB_SIZE-1);
    } else {
      return idx;
    }
  }
}

void printAll(struct skladowe tab[]) {
  int i;
  for(i=0; i<TAB_SIZE; i++){
    printf("[%2d] ", i);
    wypisz(tab[i]);
  }
}

void set(struct skladowe tab[], int idx) {
  int x, y;

  printf("Podaj wartość pierwszej składowej: ");
  scanf("%d", &x);
  printf("Podaj wartość drugiej składowej: ");
  scanf("%d", &y);

  tab[idx].x = x;
  tab[idx].y = y;
}

void setSelected(struct skladowe tab[]) {
  int idx, x, y;
  idx = getIndex();
  set(tab, idx);
}

void setFree(struct skladowe tab[]) {
  int idx = -1;
  int i;

  for(i=0; i<TAB_SIZE; i++){
    if (tab[i].x == 0 && tab[i].y == 0) {
      idx = i;
      break;
    }
  }

  if (idx == -1) {
    printf("Brak wolnego miejsca\n");
  } else {
    set(tab, idx);
  }
}

void resetSelected(struct skladowe tab[]) {
  int idx, x, y;
  idx = getIndex();

  init(tab, idx);
}

void printStat(struct skladowe tab[]) {
  int i, minX, maxX, avgX, countX, minY, maxY, avgY, countY;
  bool first = true;

  for(i=0; i<TAB_SIZE; i++){
    if (tab[i].x != 0 || tab[i].y != 0){
      if (first){
        minX = maxX = avgX = tab[i].x;
        minY = maxY = avgY = tab[i].y;
        countX = countY = 1;
        first = false;
      } else {
        avgX += tab[i].x;
        avgY += tab[i].y;
        countX += 1;
        countY += 1;

        if (tab[i].x > maxX) {
          maxX = tab[i].x;
        }
        if (tab[i].x < minX) {
          minX = tab[i].x;
        }

        if (tab[i].y > maxY) {
          maxY = tab[i].y;
        }
        if (tab[i].y < minY) {
          minY = tab[i].y;
        }
      }
    }
  }

  if (first) {
    printf("Wszystkie dane są puste\n");
  } else {
    printf("Statystyka dla X:\n");
    printf("min=%d, max=%d, avg=%f\n", minX, maxX, (double)avgX/countX);
    printf("Statystyka dla Y:\n");
    printf("min=%d, max=%d, avg=%f\n", minY, maxY, (double)avgY/countY);
  }
}
