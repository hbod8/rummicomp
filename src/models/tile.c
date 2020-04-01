/*
 *
 * Colors: 0=black, 1=blue, 2=red, 3=orange
 * 
 */
struct tile {
    char color;
    char value;
};

struct tile *createTile(char c, char v) {
    struct tile *t = malloc(sizeof(struct tile));
    t->color = c;
    t->value = v;
}