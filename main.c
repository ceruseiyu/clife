#include "game.h"
#include "ga.h"
#include <ncurses.h>
#include <stdlib.h>

#define WIDTH 25
#define HEIGHT 25
#define GENEPOOL_COUNT 50
#define GENERATIONS 40

int main() {
  prepGA();
  //GameWorld* world = createRanWorld(WIDTH, HEIGHT);
  ScoredWorld** worldPool = seedWorlds(GENEPOOL_COUNT, WIDTH, HEIGHT);
  printf("%d\n",worldPool[GENEPOOL_COUNT - 1]->score);
  runGenerations(worldPool, GENERATIONS, GENEPOOL_COUNT);
  printf("%d\n",worldPool[GENEPOOL_COUNT - 1]->score);
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
