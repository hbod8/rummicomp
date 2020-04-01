struct board {
    struct run *run;
    struct board *next;
};

struct board *createBoard(struct run *r) {
    struct board *newBoard = malloc(sizeof(struct board));
    newBoard->run = r;
    newBoard->next = NULL;
    return newBoard;
}

void addRunToBoard(struct board *b, struct run *r) {
    if (b->next != 0) {
        addRunToBoard(b->next, r);
    } else {
        struct board *newBoard = malloc(sizeof(struct board));
        b->next = newBoard;
        b->next->run = r;
    }
}