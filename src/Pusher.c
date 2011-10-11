#include "Pusher.h"
#include "Robot.h"
#include "CommonMemory.h"
static void push_robot(Tile *t, struct Robot *r, enum BoardElementMove em, enum RegisterPhase rp) {
   enum Orientation o = *(enum Orientation*)Tile_get_extended_data(t);
   Coordinate destination = Direction_apply(o, forward, Size1, Robot_location(r));
   Robot_move_to(r, destination);
}

Tile *Pusher_create(enum Orientation o, RegisterPhaseGroup group) {
   TileWalls walls = { TileWalls_none };
   Tile *t = Tile_create(push_robot, walls, group);
   enum Orientation *allocated = acquire(sizeof(enum Orientation));
   *allocated = o;
   Tile_set_extended_data(t, allocated);
   return t;
}

void Pusher_destroy(Tile *t) {
   if (t != NULL) {
      release(Tile_get_extended_data(t));
      Tile_destroy(t);
   }
}
