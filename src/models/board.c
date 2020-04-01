/*Board
 * Structure that defines a linked list of rummikub runs.
 * run represents a pointer to the first Run on the Board.
 * next represents a pointer to the next Board structure in the list.
 * If there are no more tiles remaining in the Board next will be NULL.
 * If the Board is empty tile will be NULL.
 */
struct board {
    struct run *run;
    struct board *next;
};

/*Create Board
 * Returns pointer to a new Board given the first Run on the Board.
 * Given a NULL Run, the Board is empty.
 */
struct board *createBoard(struct run *r) {
    struct board *newBoard = malloc(sizeof(struct board));
    newBoard->next = NULL;
    newBoard->run = r;
    return newBoard;
}

/*Add Run to Board
 * Adds given Run to given Board. Will fill any NULL Tiles with given tile.
 */
void addRunToBoard(struct board *b, struct run *r) {
    if (b->run == NULL) {
        b->run = r;
    } else if (b->next != NULL) {
        addRunToBoard(b->next, r);
    } else {
        struct board *newBoard = malloc(sizeof(struct board));
        newBoard->next = NULL;
        newBoard->run = r;
        b->next = newBoard;
    }
}

/*Delete Board
 * Unallocates memory to given Board.  Will recursivley unallocate any contained Run and subsequent Board.
 */
void deleteBoard(struct board *b) {
    if (b->next != NULL) {
        deleteBoard(b->next);
        deleteRun(b->run);
        free(b);
    } else {
        deleteRun(b->run);
        free(b);
    }
}