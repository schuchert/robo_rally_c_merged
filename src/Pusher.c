#include "Pusher.h"
#include "Robot.h"
#include "CommonMemory.h"
#include "Tile.h"

static void push_robot(Tile *t, struct Robot *r, enum BoardElementMove em, enum RegisterPhase rp) {
   if (em == Bem_Pusher) {
      enum Orientation o = *(enum Orientation*) Tile_get_extended_data(t);
      Coordinate destination = Direction_apply(o, forward, Size1, Robot_location(r));
      Robot_move_to(r, destination);
   }
}

static void Pusher_delete(Tile *t) {
   release(Tile_get_extended_data(t));
}

Tile *Pusher_create(enum Orientation o, RegisterPhaseGroup group) {
   TileWalls walls = { TileWalls_none };
   Tile *t = Tile_create(push_robot, walls, group);
   enum Orientation *allocated = acquire(sizeof(enum Orientation));
   *allocated = o;
   Tile_set_extended_data(t, allocated, Pusher_delete);
   return t;
}
