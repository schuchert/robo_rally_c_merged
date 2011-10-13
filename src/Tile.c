#include "Tile.h"
#include "CommonMemory.h"
#include "RegisterPhaseGroup.h"

struct Tile {
   TILE_E_F effect;
   TileWalls walls;
   RegisterPhaseGroup registerPhaseGroup;
   void *extendedData;
   TILE_E_D_R extendedDataRelease;
};

Tile *Tile_create(TILE_E_F e, TileWalls w, RegisterPhaseGroup g) {
   Tile *value = acquire(sizeof(Tile));
   value->effect = e;
   value->walls = w;
   value->registerPhaseGroup = g;
   value->extendedData = NULL;
   value->extendedDataRelease = NULL;
   return value;
}

void Tile_destroy(Tile *value) {
   if (value != NULL) {
      TILE_E_D_R releaseExtendedData = value->extendedDataRelease;
      if (releaseExtendedData != NULL) {
         releaseExtendedData(value);
         value->extendedDataRelease = NULL;
      }
      release(value);
   }
}

static char mask_for(enum Orientation o) {
   return 1 << o;
}

TileWalls Tile_walls_at(enum Orientation o) {
   TileWalls w = { mask_for(o) };
   return w;
}

void Tile_empty(Tile *t, struct Robot *r, enum BoardElementMove em) {
}

int Tile_allows_movement_in(Tile *t, enum Orientation o, enum Direction d) {
   enum Orientation actual = Orientation_actual(o, d);
   return !(t->walls.wallMask & mask_for(actual));
}

void Tile_execute(Tile *t, struct Robot *r, enum BoardElementMove em, enum RegisterPhase rp) {
   if (RegisterPhaseGroup_should_apply(t->registerPhaseGroup, rp))
      t->effect(t, r, em);
}

void Tile_set_extended_data(Tile *t, void *d, TILE_E_D_R f) {
   t->extendedData = d;
   t->extendedDataRelease = f;
}

void *Tile_get_extended_data(Tile *t) {
   return t->extendedData;
}

TILE_E_D_R Tile_get_extended_data_release(Tile *f) {
   return f->extendedDataRelease;
}
