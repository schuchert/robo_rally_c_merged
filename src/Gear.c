#include "Gear.h"
#include "Tile.h"
#include "Robot.h"
#include "CommonMemory.h"

typedef struct {
   enum Direction d;
   enum Size s;
} GearDirectionSize;

static void rotate_robot(Tile *t, struct Robot *r, enum BoardElementMove em) {
   if(em == Bem_Gear) {
      GearDirectionSize *gds = Tile_get_extended_data(t);
      enum Orientation finalFacing = Orientation_rotate(Robot_facing(r), gds->d, gds->s);
      Robot_set_facing(r, finalFacing);
   }
}

static void Gear_delete(Tile *t) {
   release(Tile_get_extended_data(t));
}

Tile *Gear_create(enum Direction d, enum Size s, RegisterPhaseGroup group) {
   TileWalls walls = { TileWalls_none };
   Tile *t = Tile_create(rotate_robot, walls, group);
   GearDirectionSize *gds = acquire(sizeof(GearDirectionSize));
   gds->d = d;
   gds->s = s;
   Tile_set_extended_data(t, gds, Gear_delete);
   return t;
}
