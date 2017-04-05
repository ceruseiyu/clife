#include "ga.h"
#include "game.h"
#include "qs.h"
#include <time.h>
#include <stdlib.h>

#define POOL_ITERATIONS 30

void prepGA() {
  srand(time(NULL));
}

GameWorld* createRanWorld(int width, int height) {
  GameWorld* world = createWorld(width, height);
  if(world == NULL) {
    return NULL;
  }

  int i;
  int j;
  for(i = 0; i < height; i++) {
    for(j = 0; j < width; j++) {
      world->data[i][j] = rand() % 2;
    }
  }

  return world;
}

ScoredWorld** seedWorlds(int count, int width, int height) {
  ScoredWorld** worldPool = malloc(sizeof(ScoredWorld*) * count);
  if(worldPool == NULL) {
    return NULL;
  }

  int i;
  for(i = 0; i < count; i ++) {
    worldPool[i] = malloc(sizeof(ScoredWorld));
    if(worldPool[i] == NULL) {
      int j;
      for(j = 0; j < i; j++) {
        free(worldPool[j]->world);
        free(worldPool[j]);
      }
      free(worldPool);
      return NULL;
    }

    worldPool[i]->world = createRanWorld(width, height);
    if(worldPool[i]->world == NULL) {
      if(worldPool[i] == NULL) {
        int j;
        for(j = 0; j < i; j++) {
          free(worldPool[j]->world);
          free(worldPool[j]);
        }
        free(worldPool[i]);
        free(worldPool);
        return NULL;
      }
    }

    worldPool[i]->score = scoreWorld(worldPool[i]->world, POOL_ITERATIONS);
  }
  return worldPool;
}

void sortWorlds(ScoredWorld** worlds, int count) {
  quickSort(worlds, 0, count-1);
}

int scoreWorld(GameWorld* world, int iterations) {
  GameWorld* clone = cloneWorld(world);
  int i;
  for(i = 0; i < iterations; i++) {
    simWorld(clone);
  }

  int score = 0;
  int j;
  for(i = 0; i < world->width; i++) {
    for(j = 0; j < world->height; j++) {
      score += world->data[i][j];
    }
  }

  return score;
}

ScoredWorld** cloneAllWorlds(ScoredWorld** worlds, int worldCount) {
  ScoredWorld** clonedWorlds = malloc(sizeof(ScoredWorld*) * worldCount);
  if(clonedWorlds == NULL) {
    return NULL;
  }

  int i;
  for(i = 0; i < worldCount; i++) {
    clonedWorlds[i] = malloc(sizeof(ScoredWorld));
    clonedWorlds[i]->world = cloneWorld(worlds[i]->world);
    clonedWorlds[i]->score = worlds[i]->score;
  }

  return clonedWorlds;
}

void crossOver(GameWorld* newWorld, GameWorld* leftWorld, GameWorld* rightWorld) {
  int i;
  int j;
  for(i = 0; i < newWorld->width; i++) {
    for(j = 0; j < newWorld->height; j++) {
      if(rand() % 2) {
        newWorld->data[i][j] = leftWorld->data[i][j];
      } else {
        newWorld->data[i][j] = rightWorld->data[i][j];
      }
    }
  }
}

int pickWorld(int worldCount) {
  int total = (worldCount * (worldCount + 1)) / 2;
  int count = 0;
  int choice = rand() % total;

  int i;
  for(i = 0; i < worldCount; i++) {
    count = count + i;
    if(count >= choice) {
      return i;
    }
  }
  return 0;
}

void runGenerations(ScoredWorld** worlds, int genCount, int worldCount) {
  sortWorlds(worlds, worldCount);
  int i;
  for(i = 0; i < genCount; i++) {
    int j;
    ScoredWorld** oldWorlds = cloneAllWorlds(worlds, worldCount);
    for(j = 1; j < worldCount; j++) {
      int leftWorld = pickWorld(worldCount);
      int rightWorld = pickWorld(worldCount);
      crossOver(worlds[i]->world, oldWorlds[leftWorld]->world, oldWorlds[rightWorld]->world);
    }
  }
}
