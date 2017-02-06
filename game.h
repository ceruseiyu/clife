#ifndef GAMEOFLIFE_GAME
#define GAMEOFLIFE_GAME

typedef struct golworld {
  int** data;
  int width;
  int height;
} GameWorld;

GameWorld* createWorld(int width, int height);

void printWorld(GameWorld* world);

#endif
