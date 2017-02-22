#include "ga.h"
#include "game.h"
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
