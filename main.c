#include "game.h"
#include <ncurses.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

int main() {
  GameWorld* world = createWorld(HEIGHT, WIDTH);
  initscr();
  noecho();
  curs_set(FALSE);
  while(1) {
    clear();
    int i;
    int j;
    for(i = 0; i < world->height; i++) {
      for(j = 0; j < world->width; j++) {
        if(world->data[i][j]){
          mvprintw(i, j, "1");
        } else{
          mvprintw(i, j, "0");
        }
      }
    }
    refresh();
  }
  endwin();
  return 1;
}
