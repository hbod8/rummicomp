/*
 * Harry Saliba 2020
 */

/*Set
 * Structure that defines a linked list of rummikub tiles.
 * tile represents a pointer to the first tile in the Set.
 * next represents a pointer to the next Set structure in the list.
 * If there are no more tiles remaining in the Set next will be NULL.
 * If the Set is empty tile will be NULL.
 * Very similar to Run, but there is no need to check for correctness.
 */
struct set {
    struct tile *tile;
    struct set *next;
};

/*Create Set
 * Returns a pointer to a new Set given given the first tile.
 * Given a NULL Tile, the Set is empty.
 */
struct set *createSet(struct tile *t) {
    struct set *newSet = malloc(sizeof(struct set));
    newSet->next = NULL;
    newSet->tile = t;
    return newSet;
}

/*Add Tile to Set
 * Adds given Tile to given Set. Will fill any NULL Tiles with given tile.
 */
void addTileToSet(struct set *s, struct tile *t) {
    if (s->tile == NULL) {
        s->tile = t;
    } else if (s->next != NULL) {
        addTileToSet(s->next, t);
    } else {
        struct set *newSet = malloc(sizeof(struct set));
        newSet->next = NULL;
        newSet->tile = t;
        s->next = newSet;
    }
}