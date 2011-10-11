#pragma once
#ifndef TILE_H_
#define TILE_H_


#ifdef __cplusplus
extern "C" {
#endif

#include "Movement.h"

struct Robot;
#include "RegisterPhaseGroup.h"
typedef struct Tile Tile;

typedef struct TileWalls {
	char wallMask;
} TileWalls;

enum {
   TileWalls_none = 0
};

enum BoardElementMove {
   Part1 = 1,
   Part2 = 2,
   Part3 = 3,
   Part4 = 4
};


typedef void (*TILE_E_F)(Tile *, struct Robot *, enum BoardElementMove, enum RegisterPhase);

Tile *Tile_create(TILE_E_F, TileWalls, struct RegisterPhaseGroup);
void Tile_destroy(Tile *);
TileWalls Tile_walls_at(enum Orientation);

void Tile_empty(Tile *, struct Robot *, enum BoardElementMove, enum RegisterPhase);
int Tile_allows_movement_in(Tile *, enum Orientation, enum Direction);
void Tile_execute(Tile *t, struct Robot *, enum BoardElementMove, enum RegisterPhase);
void Tile_set_extended_data(Tile *t, void *d);
void *Tile_get_extended_data(Tile *t);

#ifdef __cplusplus
}
#endif

#endif /* TILE_H_ */
