#include "RegisterPhaseGroup.h"

RegisterPhaseGroup RegisterPhaseGroup_create(enum Rfg_Mode m) {
   RegisterPhaseGroup g = { m };
   return g;
}

RegisterPhaseGroup RegisterPhaseGroup_add_to(RegisterPhaseGroup g, enum Rfg_Mode m) {
   RegisterPhaseGroup result =  { g.phase_mask | m };
   return result;
}

int RegisterPhaseGroup_should_apply(RegisterPhaseGroup g, enum RegisterPhase p) {
   return g.phase_mask & (1 << p);
}
