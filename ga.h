#ifndef GAMEOFLIFE_GA
#define GAMEOFLIFE_GA
#include "game.h"
#include "qs.h"

typedef struct worldscore {
  GameWorld* world;
  int score;
} ScoredWorld;

void prepGA();

GameWorld* createRanWorld(int width, int height);

ScoredWorld** seedWorlds(int count, int width, int height);

void sortWorlds(ScoredWorld** worlds, int count);

int scoreWorld(GameWorld* world, int iterations);

#endif
