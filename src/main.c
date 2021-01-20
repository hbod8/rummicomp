/*
 * Harry Saliba 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

#include "models/models.h"

bool ANSI_COLOR = true;

/*Get Color Code
 * Returns a ANSI character of the color given its color value.
 */
char *getColorCode(char c)
{
  switch (c)
  {
  case 0:
    return "\033[47m\033[30m";
  case 1:
    return "\033[47m\033[34m";
  case 2:
    return "\033[47m\033[31m";
  case 3:
    return "\033[47m\033[33m";
  default:
    return "NA";
  }
}

/*Get Color
 * Returns a string representation of the color given its color value.
 */
char *getColor(char c)
{
  switch (c)
  {
  case 0:
    return "black";
  case 1:
    return "blue";
  case 2:
    return "red";
  case 3:
    return "orange";
  default:
    return "NA";
  }
}

/*Print Run
 * Recursvley prints every Tile in a Run.
 */
void printRun(struct run *r)
{
  if (r != NULL)
  {
    if (ANSI_COLOR)
    {
      printf("%s%d%s ", getColorCode(r->tile->color), r->tile->value, "\033[0m");
    }
    else
    {
      printf("[%s %d] ", getColor(r->tile->color), r->tile->value);
    }
    printRun(r->next);
  }
}

/*Print Board
 * Recursivley prints every Tile in every Run in a Board.
 */
void printBoard(struct board *b)
{
  if (b != NULL)
  {
    printRun(b->run);
    printf("\n");
    printBoard(b->next);
  }

  return;
}

/*Test
 * Function for testing.
 */
void test()
{
  //Contruct and display a board of predetermined order and tiles using manual construction of runs:
  printf("Contructing and displaying a board of predetermined order and tiles using manual construction of runs:\n");

  struct tile b6 = {1, 6}; //blue 6
  struct tile b7 = {1, 7}; //blue 7
  struct tile b8 = {1, 8}; //blue 8

  struct tile bl6 = {0, 6}; //black 6
  struct tile bu6 = {1, 6}; //blue 6
  struct tile r6 = {2, 6};  //red 6
  struct tile o6 = {3, 6};  //orange 6

  struct run r12 = {&b8, NULL};
  struct run r11 = {&b7, &r12};
  struct run r10 = {&b6, &r11};

  struct run r23 = {&bl6, NULL};
  struct run r22 = {&bu6, &r23};
  struct run r21 = {&r6, &r22};
  struct run r20 = {&o6, &r21};

  struct board b11 = {&r20, NULL};
  struct board b10 = {&r10, &b11};

  printBoard(&b10);

  //Contruct and display a board of predetermined order and tiles using functions to add tiles to runs and runs to boards:
  printf("Contructing and displaying a board of predetermined order and tiles using functions to add tiles to runs and runs to boards:\n");

  struct run *run1 = createRun(createTile(1, 6));
  addTileToRun(run1, createTile(1, 7));
  addTileToRun(run1, createTile(1, 8));

  struct run *run2 = createRun(createTile(0, 6));
  addTileToRun(run2, createTile(1, 6));
  addTileToRun(run2, createTile(2, 6));
  addTileToRun(run2, createTile(3, 6));

  struct board *board1 = createBoard(run1);
  addRunToBoard(board1, run2);

  printBoard(board1);

  printf("Run1 length: %d, Run2 length: %d\n", length(run1), length(run2));
  //Call delete board and check that memory chunks are freed.
  printf("Free memory space: ");
  struct mallinfo info = mallinfo();
  int bytesUsedBefore = info.uordblks;
  deleteBoard(board1);
  info = mallinfo();
  int bytesUsedAfter = info.uordblks;
  printf("Freed %d bytes of memory.\n", bytesUsedBefore - bytesUsedAfter);
  //Create and display every tile:
  printf("Create and display every tile:\n");
  // malloc_stats();
  struct board *fullBoard = createBoard(NULL);
  for (int j = 0; j < 8; j++)
  {
    struct run *curRun = createRun(createTile((j / 2), 1));
    for (int i = 2; i <= 13; i++)
    {
      addTileToRun(curRun, createTile((j / 2), i));
    }
    addRunToBoard(fullBoard, curRun);
  }
  printBoard(fullBoard);
  // malloc_stats();
  deleteBoard(fullBoard);
  // malloc_stats();
}

/*Main
 * Main entry point for program.
 */
int main()
{
  printf("\033[0;31mRummicomp\033[0m\n");
  test();
}