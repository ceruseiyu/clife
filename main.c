#include "game.h"
#include "ga.h"
#include <ncurses.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10
#define GENEPOOL_COUNT 50

int main() {
  prepGA();
  //GameWorld* world = createRanWorld(WIDTH, HEIGHT);
  ScoredWorld** worldPool = seedWorlds(GENEPOOL_COUNT, WIDTH, HEIGHT);

  /*initscr();
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
  endwin();*/
  return 1;
}
