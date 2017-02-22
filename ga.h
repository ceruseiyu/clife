#ifndef GAMEOFLIFE_GA
#define GAMEOFLIFE_GA
#include "game.h"

typedef struct worldscore {
  GameWorld* world;
  int score;
} ScoredWorld;

void prepGA();

GameWorld* createRanWorld(int width, int height);

#endif
