struct run {
    struct tile *tile;
    struct run *next;
};

struct run *createRun(struct tile *t) {
    struct run *newRun = malloc(sizeof(struct run));
    newRun->tile = t;
    newRun->next = NULL;
    return newRun;
}

void addTileToRun(struct run *r, struct tile *t) {
    if (r->next != 0) {
        addTileToRun(r->next, t);
    } else {
        struct run *newRun = malloc(sizeof(struct run));
        r->next = newRun;
        r->next->tile = t;
    }
}