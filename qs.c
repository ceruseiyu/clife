#include "qs.h"
#include "game.h"
#include "ga.h"

void quickSort(ScoredWorld** worldList, int low, int high) {
  int partitionValue;
  if(low < high) {
    partitionValue = partition(worldList, low, high);
    quickSort(worldList, low, partitionValue - 1);
    quickSort(worldList, partitionValue + 1, high);
  }
}

/*
for j := lo to hi - 1 do
    if A[j] ≤ pivot then
        i := i + 1
        swap A[i] with A[j]
swap A[i+1] with A[hi]
return i + 1
*/

int partition(ScoredWorld** worldList, int low, int high) {
  int pivot = worldList[high]->score;
  int i = low - 1;
  int j;
  for(j = low; j < high; j++) {
    if(worldList[j]->score <= pivot) {
      i++;
      swap(worldList, i, j);
    }
  }
  swap(worldList, i + 1, high);
  return i + 1;
}

void swap(ScoredWorld** worldList, int left, int right) {
  ScoredWorld* saveWorld = worldList[left];
  worldList[left] = worldList[right];
  worldList[right] = saveWorld;
}
