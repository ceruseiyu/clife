#ifndef GAMEOFLIFE_GAME
#define GAMEOFLIFE_GAME

typedef struct golworld {
  int** data;
  int width;
  int height;
} GameWorld;

GameWorld* createWorld(int width, int height);

void printWorld(GameWorld* world);

int cellValue(GameWorld* world, int cellX, int cellY);

int sumCells(GameWorld* world, int cellX, int cellY);

void simCell(GameWorld* world, int cellX, int cellY);

void simWorld(GameWorld* world);

#endif
