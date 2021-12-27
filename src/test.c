#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define RED 0
#define BLUE 1
#define BLACK 2
#define ORANGE 3

#define NVALUES 13
#define NSUITS 4
#define NCOPIES 2
#define MIN_RUN 3

#define INDEX(i, j) NVALUES * i + j
#define MAX(a, b) a > b ? a : b
#define NRUNSTATES(m) 

void printIntArray(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    printf("[%2d] ", arr[i]);
  }
  puts("");
}

void printScore(int *score) {
  printIntArray(score, NVALUES);
}

void printHand(int *hand) {
  for (int i = 0; i < NSUITS; i++) {
    for (int j = 0; j < NVALUES; j++) {
      printf("[%2.*s] ", hand[INDEX(i, j)], "**");
    }
    puts("");
  }
}

int sumHand(int *hand) {
  int sum = 0;
  for (int i = 0; i < NVALUES * NSUITS; i++) {
    sum += hand[i];
  }
  return sum;
}

int makeRuns(int n, int *hand, int *score) {
  if (n < MIN_RUN) {
    return 0;
  }
  for (int k = 0; k < NSUITS; k++) {

  }
}

int makeGroups(int n, int *hand, int *score) {
  
}

void maxScore(int *hand, int *score) {
  int baseScore = sumHand(hand);
  for (int n = 0; n < NVALUES; n++) {
    makeRuns(n, hand, score);
  }
}

int main() {

  printf("%d values, %d suits, %d copies\n", NVALUES, NSUITS, NCOPIES);

  int *hand = malloc(NSUITS * NVALUES * sizeof(int));
  for (int i = 0; i < (NSUITS * NVALUES); i++) {
    hand[i] = 0;
  }

  int *score = malloc(NVALUES * sizeof(int));
  for (int i = 0; i < NVALUES; i++) {
    score[i] = INT_MIN;
  }

  hand[INDEX(RED, 0)] = 2;
  hand[INDEX(RED, 3)] = 1;
  hand[INDEX(RED, 4)] = 1;
  hand[INDEX(RED, 5)] = 1;

  hand[INDEX(BLUE, 0)] = 2;
  hand[INDEX(BLUE, 9)] = 1;
  hand[INDEX(BLUE, 10)] = 1;
  hand[INDEX(BLUE, 11)] = 1;

  hand[INDEX(BLACK, 0)] = 2;
  hand[INDEX(BLACK, 4)] = 1;
  hand[INDEX(BLACK, 5)] = 1;
  hand[INDEX(BLACK, 6)] = 2;
  hand[INDEX(BLACK, 7)] = 1;
  hand[INDEX(BLACK, 8)] = 1;
  hand[INDEX(BLACK, 9)] = 2;
  hand[INDEX(BLACK, 10)] = 1;
  hand[INDEX(BLACK, 11)] = 1;

  hand[INDEX(ORANGE, 0)] = 2;
  hand[INDEX(ORANGE, 9)] = 1;
  hand[INDEX(ORANGE, 10)] = 1;
  hand[INDEX(ORANGE, 11)] = 1;
  hand[INDEX(ORANGE, 12)] = 1;

  printHand(hand);
  maxScore(hand, score);
  printScore(score);

  free(hand);
}