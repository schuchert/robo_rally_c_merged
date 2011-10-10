#include "Board.h"
#include "Coordinate.h"
#include "CommonMemory.h"
#include "Robot.h"
#include "Tile.h"
#include "linked_list.h"

typedef struct TileLocation {
	Tile *tile;
	Coordinate location;
} TileLocation;

static TileLocation *TileLocation_create(Tile *t, Coordinate c) {
	TileLocation *value = acquire(sizeof(TileLocation));
	value->tile = t;
	value->location = c;
	return value;
}

static void TileLocation_release(TileLocation *tl) {
	if (tl != NULL) {
		Tile_destroy(tl->tile);
		tl->tile = NULL;
		release(tl);
	}
}

struct Board {
	linked_list *tileLocations;
};

Board *Board_create(Coordinate upperRight) {
	Board *value = acquire(sizeof(Board));
	value->tileLocations = linked_list_create();
	return value;
}

void Board_destroy(Board *value) {
	linked_list_release_destroy(value->tileLocations,
			(RELEASE_F) TileLocation_release);
	release(value);
}

void Board_set_tile(Board *b, struct Tile *t, Coordinate c) {
	linked_list_add(b->tileLocations, TileLocation_create(t, c));
}

static int tile_at(const TileLocation *value, const Coordinate *c) {
	return Coordinate_are_equal(value->location, *c);
}

static Tile *Board_tile_at(Board *b, Coordinate c) {
	TileLocation *found = (TileLocation*)linked_list_find(b->tileLocations, (COMP_F)tile_at, &c);
	Tile *result = NULL;
	if(found != NULL)
		result = found->tile;
	return result;
}

int Board_can_move_through(Board *b, struct Robot *r, enum Direction d) {
	Coordinate c = Robot_location(r);
	Tile *t = Board_tile_at(b, c);
	return t == NULL || Tile_allows_movement_in(t, Robot_facing(r), d);
}
