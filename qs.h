#ifndef GAMEOFLIFE_QUICKSORT
#define GAMEOFLIFE_QUICKSORT
#include "game.h"
#include "ga.h"

void quickSort(struct worldscore** worldList, int low, int high);

int partition(struct worldscore** worldList, int low, int high);

void swap(struct worldscore** worldList, int left, int right);

#endif
