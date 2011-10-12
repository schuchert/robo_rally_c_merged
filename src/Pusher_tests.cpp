#include <CppUTest/TestHarness.h>

#include "Card.h"
#include "Pusher.h"
#include "RegisterPhase.h"
#include "Robot.h"
#include "Coordinate.h"
#include "Board.h"

TEST_GROUP(Pusher) {
   Tile *pusher;
   Board *b;
   Robot *r;

   void setup() {
      pusher = NULL;
      b = Board_create(Coordinate_create(10, 10));
      r = Robot_create(b, Coordinate_create(5,5), N);
   }

   void teardown() {
      Tile_destroy(pusher);
      Board_destroy(b);
      Robot_destroy(r);
   }
};

#include "Coordinate_test_helper.h"
TEST(Pusher, PushesAllPhases) {
   pusher = Pusher_create(N, RegisterPhaseGroup_create(Rfg_All));
   Tile_execute(pusher, r, Part1, One);
   CHECK_EQUAL(Coordinate_create(5,6), Robot_location(r));
}

TEST(Pusher, OnlyPushesPhase1) {
   pusher = Pusher_create(N, RegisterPhaseGroup_create(Rfg_One));
   Tile_execute(pusher, r, Part1, Two);
   CHECK_EQUAL(Coordinate_create(5,5), Robot_location(r));
   Tile_execute(pusher, r, Part1, One);
   CHECK_EQUAL(Coordinate_create(5,6), Robot_location(r));
}

TEST(Pusher, OnlyPushesOddPhases) {
   pusher = Pusher_create(N, RegisterPhaseGroup_create(Rfg_Odd));
   Tile_execute(pusher, r, Part1, Two);
   CHECK_EQUAL(Coordinate_create(5,5), Robot_location(r));
   Tile_execute(pusher, r, Part1, One);
   CHECK_EQUAL(Coordinate_create(5,6), Robot_location(r));
}
