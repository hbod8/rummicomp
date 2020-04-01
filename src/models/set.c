struct set {
    struct tile *tile;
    struct set *next;
};

struct set *createSet(struct tile *t) {
    struct set *newSet = malloc(sizeof(struct set));
    newSet->tile = t;
    newSet->next = NULL;
    return newSet;
}

void addTileToSet(struct set *s, struct tile *t) {
    if (s->next != 0) {
        addTileToSet(s->next, t);
    } else {
        struct set *newSet = malloc(sizeof(struct set));
        s->next = newSet;
        s->next->tile = t;
    }
}