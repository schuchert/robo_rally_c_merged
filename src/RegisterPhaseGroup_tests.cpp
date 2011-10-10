#include <CppUTest/TestHarness.h>

#include "RegisterPhaseGroup.h"

TEST_GROUP(RFG) {
};

TEST(RFG, all) {
   RegisterPhaseGroup g = RegisterPhaseGroup_create(Rfg_All);
   CHECK( RegisterPhaseGroup_should_apply(g, One));
   CHECK( RegisterPhaseGroup_should_apply(g, Two));
   CHECK( RegisterPhaseGroup_should_apply(g, Three));
   CHECK( RegisterPhaseGroup_should_apply(g, Four));
   CHECK( RegisterPhaseGroup_should_apply(g, Five));
}

TEST(RFG, one) {
   RegisterPhaseGroup g = RegisterPhaseGroup_create(Rfg_One);
   CHECK( RegisterPhaseGroup_should_apply(g, One));
   CHECK(!RegisterPhaseGroup_should_apply(g, Two));
   CHECK(!RegisterPhaseGroup_should_apply(g, Three));
   CHECK(!RegisterPhaseGroup_should_apply(g, Four));
   CHECK(!RegisterPhaseGroup_should_apply(g, Five));
}

TEST(RFG, two) {
   RegisterPhaseGroup g = RegisterPhaseGroup_create(Rfg_Two);
   CHECK(!RegisterPhaseGroup_should_apply(g, One));
   CHECK( RegisterPhaseGroup_should_apply(g, Two));
   CHECK(!RegisterPhaseGroup_should_apply(g, Three));
   CHECK(!RegisterPhaseGroup_should_apply(g, Four));
   CHECK(!RegisterPhaseGroup_should_apply(g, Five));
}

TEST(RFG, Three) {
   RegisterPhaseGroup g = RegisterPhaseGroup_create(Rfg_Three);
   CHECK(!RegisterPhaseGroup_should_apply(g, One));
   CHECK(!RegisterPhaseGroup_should_apply(g, Two));
   CHECK( RegisterPhaseGroup_should_apply(g, Three));
   CHECK(!RegisterPhaseGroup_should_apply(g, Four));
   CHECK(!RegisterPhaseGroup_should_apply(g, Five));
}

TEST(RFG, Four) {
   RegisterPhaseGroup g = RegisterPhaseGroup_create(Rfg_Four);
   CHECK(!RegisterPhaseGroup_should_apply(g, One));
   CHECK(!RegisterPhaseGroup_should_apply(g, Two));
   CHECK(!RegisterPhaseGroup_should_apply(g, Three));
   CHECK( RegisterPhaseGroup_should_apply(g, Four));
   CHECK(!RegisterPhaseGroup_should_apply(g, Five));
}

TEST(RFG, Five) {
   RegisterPhaseGroup g = RegisterPhaseGroup_create(Rfg_Five);
   CHECK(!RegisterPhaseGroup_should_apply(g, One));
   CHECK(!RegisterPhaseGroup_should_apply(g, Two));
   CHECK(!RegisterPhaseGroup_should_apply(g, Three));
   CHECK(!RegisterPhaseGroup_should_apply(g, Four));
   CHECK( RegisterPhaseGroup_should_apply(g, Five));
}

TEST(RFG, Odd) {
   RegisterPhaseGroup g = RegisterPhaseGroup_create(Rfg_Odd);
   CHECK( RegisterPhaseGroup_should_apply(g, One));
   CHECK(!RegisterPhaseGroup_should_apply(g, Two));
   CHECK( RegisterPhaseGroup_should_apply(g, Three));
   CHECK(!RegisterPhaseGroup_should_apply(g, Four));
   CHECK( RegisterPhaseGroup_should_apply(g, Five));
}

TEST(RFG, Even) {
   RegisterPhaseGroup g = RegisterPhaseGroup_create(Rfg_Even);
   CHECK(!RegisterPhaseGroup_should_apply(g, One));
   CHECK( RegisterPhaseGroup_should_apply(g, Two));
   CHECK(!RegisterPhaseGroup_should_apply(g, Three));
   CHECK( RegisterPhaseGroup_should_apply(g, Four));
   CHECK(!RegisterPhaseGroup_should_apply(g, Five));
}

TEST(RFG, OddAndEvenIsAll) {
   RegisterPhaseGroup g = RegisterPhaseGroup_create(Rfg_Even);
   RegisterPhaseGroup added = RegisterPhaseGroup_add_to(g, Rfg_Odd);
   CHECK( RegisterPhaseGroup_should_apply(added, One));
   CHECK( RegisterPhaseGroup_should_apply(added, Two));
   CHECK( RegisterPhaseGroup_should_apply(added, Three));
   CHECK( RegisterPhaseGroup_should_apply(added, Four));
   CHECK( RegisterPhaseGroup_should_apply(added, Five));
}

TEST(RFG, OneAndFour) {
   RegisterPhaseGroup g = RegisterPhaseGroup_create(Rfg_One);
   RegisterPhaseGroup added = RegisterPhaseGroup_add_to(g, Rfg_Four);
   CHECK( RegisterPhaseGroup_should_apply(added, One));
   CHECK(!RegisterPhaseGroup_should_apply(added, Two));
   CHECK(!RegisterPhaseGroup_should_apply(added, Three));
   CHECK( RegisterPhaseGroup_should_apply(added, Four));
   CHECK(!RegisterPhaseGroup_should_apply(added, Five));
}
