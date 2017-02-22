#include "game.h"
#include <stdlib.h>
#include <stdio.h>

GameWorld* createWorld(int width, int height) {
  GameWorld* world = malloc(sizeof(GameWorld));
  if(world == NULL) {
    return NULL;
  }
  world->data = malloc(sizeof(int*) * height);
  if(world->data == NULL) {
    return NULL;
  }
  int i;
  for(i = 0; i < height; i++) {
    world->data[i] = malloc(sizeof(int) * width);
    if(world->data[i] == NULL) {
      return NULL;
    }
    int j;
    for(j = 0; j < width; j++) {
      world->data[i][j] = 0;
    }
  }
  world->height = height;
  world->width = width;
  return world;
}

GameWorld* cloneWorld(GameWorld* world) {
  if(world == NULL) {
    return NULL;
  }
  GameWorld* clone = malloc(sizeof(GameWorld));
  if(clone == NULL) {
    return NULL;
  }
  clone->data = malloc(sizeof(int*) * world->height);
  if(clone->data == NULL) {
    return NULL;
  }
  int i;
  for(i = 0; i < world->height; i++) {
    clone->data[i] = malloc(sizeof(int) * world->width);
    if(clone->data[i] == NULL) {
      return NULL;
    }
    int j;
    for(j = 0; j < world->width; j++) {
      clone->data[i][j] = world->data[i][j];
    }
  }
  clone->height = world->height;
  clone->width = world->width;
  return clone;
}

void printWorld(GameWorld* world) {
  int i;
  for(i = 0; i < world->height; i++) {
    int j;
    for(j = 0; j < world->width; j++) {
      printf("%i", world->data[i][j]);
    }
    printf("\n");
  }
}

int cellValue(GameWorld* world, int cellX, int cellY) {
  if(cellX >= 0 && cellY >= 0 && cellX < world->width && cellY < world->height) {
    return world->data[cellY][cellX];
  }
  return 0;
}

int sumCells(GameWorld* world, int cellX, int cellY) {
  int count = 0;
  int i;
  //Check top three cells
  for(i = -1; i < 2; i++)
    if(cellValue(world, cellX + i, cellY -1))
      count++;
  //Check bottom three cells
  for(i = -1; i < 2; i++)
    if(cellValue(world, cellX + i, cellY +1))
      count++;
  //Check the left and right cells
  if(cellValue(world, cellX -1, cellY))
    count++;
  if(cellValue(world, cellX +1, cellY))
    count++;

  return count;
}

void simCell(GameWorld* world, int cellX, int cellY) {
  int count = sumCells(world, cellX, cellY);
  if(count < 2) {
    world->data[cellY][cellX] = 0;
  } else if(count == 2) {
    return;
  } else if(count == 3) {
    world->data[cellY][cellX] = 1;
  } else {
    world->data[cellY][cellX] = 0;
  }
}

void simWorld(GameWorld* world) {
  int i;
  int j;
  for(i = 0; i < world->height; i++)
    for(j = 0; j < world->width; j++)
      simCell(world, i, j);
}
