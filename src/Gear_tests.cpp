#include <CppUTest/TestHarness.h>

#include "Robot.h"
#include "Coordinate.h"
#include "Board.h"
#include "Tile.h"
#include "Gear.h"
#include "RegisterPhaseGroup.h"

TEST_GROUP(Gear) {
   Tile *gear;
   Board *b;
   Robot *r;

   void setup() {
      gear = NULL;
      b = Board_create(Coordinate_create(10, 10));
      r = Robot_create(b, Coordinate_create(5,5), N);
   }

   void teardown() {
      Tile_destroy(gear);
      Board_destroy(b);
      Robot_destroy(r);
   }
};

TEST(Gear, rotates_1_clockwise_all_phases) {
   gear = Gear_create(clockwise, Size1, RegisterPhaseGroup_create(Rfg_All));
   Tile_execute(gear, r, Bem_Gear, One);
   CHECK_EQUAL(E, Robot_facing(r));
}

TEST(Gear, rotates_2_counter_clockwise_odd_phases) {
   gear = Gear_create(counter_clockwise, Size2, RegisterPhaseGroup_create(Rfg_Odd));
   Tile_execute(gear, r, Bem_Gear, Two);
   CHECK_EQUAL(N, Robot_facing(r));
   Tile_execute(gear, r, Bem_Gear, Three);
   CHECK_EQUAL(S, Robot_facing(r));
}

TEST(Gear, does_not_rotate_if_wrong_board_move_phase) {
   gear = Gear_create(clockwise, Size1, RegisterPhaseGroup_create(Rfg_All));
   Tile_execute(gear, r, Bem_Conveyor_1, Four);
   CHECK_EQUAL(N, Robot_facing(r));
}
