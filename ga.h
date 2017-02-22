#ifndef GAMEOFLIFE_GA
#define GAMEOFLIFE_GA
#include "game.h"

typedef struct worldscore {
  GameWorld* world;
  int score;
} ScoredWorld;

void prepGA();

GameWorld* createRanWorld(int width, int height);

ScoredWorld** seedWorlds(int count, int width, int height);

int scoreWorld(GameWorld* world, int iterations);

#endif
