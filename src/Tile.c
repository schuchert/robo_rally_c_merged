#include "Tile.h"
#include "CommonMemory.h"

struct Tile {
	TILE_M_F behavior;
	TileWalls walls;
};

Tile *Tile_create(TILE_M_F f, TileWalls w) {
	Tile *value = acquire(sizeof(Tile));
	value->behavior = f;
	value->walls = w;
	return value;
}
void Tile_destroy(Tile *value) {
	release(value);
}

static char mask_for(enum Orientation o) {
	return 1 << o;
}

TileWalls Tile_walls_at(enum Orientation o) {
	TileWalls w = { mask_for(o) };
	return w;
}

int Tile_empty(Tile *t, enum Orientation o, enum Direction d) {
	return 1;
}

int Tile_allows_movement_in(Tile *t, enum Orientation o, enum Direction d) {
	enum Orientation actual = Orientation_actual(o, d);
	return !(t->walls.wallMask & mask_for(actual));
}
