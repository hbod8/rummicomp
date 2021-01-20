/*
 * Harry Saliba 2020
 */

/*Tile
 * Structure that defines a rummikub tile.
 * Color represents one of the four colors where 0=black, 1=blue, 2=red, 3=orange.
 * Value represents the number on the tile 1-13.
 */
struct tile
{
  char color;
  char value;
};

/*Create Tile
 * Returns a pointer to a new Tile given its color and value.
 */
struct tile *createTile(char c, char v)
{
  struct tile *t = malloc(sizeof(struct tile));
  t->color = c;
  t->value = v;
  return t;
}