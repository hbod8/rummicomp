/*Run
 * Structure that defines a linked list of rummikub tiles.
 * tile represents a pointer to the first tile in the Run.
 * next represents a pointer to the next Run structure in the list.
 * If there are no more tiles remaining in the Run next will be NULL.
 * If the Run is empty tile will be NULL.
 */
struct run {
    struct tile *tile;
    struct run *next;
};

/*Create Run
 * Returns a pointer to a new run given the first tile.
 * Given a NULL Tile, the Run is empty.
 */
struct run *createRun(struct tile *t) {
    struct run *newRun = malloc(sizeof(struct run));
    newRun->tile = t;
    newRun->next = NULL;
    return newRun;
}

/*Add Tile to Run
 * Adds given Tile to given Run. Will fill any NULL Tiles with given tile.
 */
void addTileToRun(struct run *r, struct tile *t) {
    if (r->tile == NULL) {
        r->tile = t;
    } else if (r->next != NULL) {
        addTileToRun(r->next, t);
    } else {
        struct run *newRun = malloc(sizeof(struct run));
        newRun->next = NULL;
        newRun->tile = t;
        r->next = newRun;
    }
}

/*Delete Run
 * Unallocates memory to given Run.  Will recursivley unallocate any subsequent Run.
 */
void deleteRun(struct run *r) {
    if (r->next != NULL) {
        deleteRun(r->next);
        free(r);
    } else {
        free(r);
    }
}