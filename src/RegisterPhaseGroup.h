#pragma once
#ifndef REGISTERPHASEGROUP_H_
#define REGISTERPHASEGROUP_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "RegisterPhase.h"

enum Rfg_Mode {
   Rfg_All = 0b11111,
   Rfg_Odd = 0b10101,
   Rfg_Even = 0b01010,
   Rfg_One = 0b00001,
   Rfg_Two = 0b00010,
   Rfg_Three = 0b00100,
   Rfg_Four = 0b01000,
   Rfg_Five = 0b10000,
   Rfg_BeyondLast = 0b0000
};

typedef struct RegisterPhaseGroup {
   unsigned char phase_mask;
} RegisterPhaseGroup;

RegisterPhaseGroup RegisterPhaseGroup_create(enum Rfg_Mode);
RegisterPhaseGroup RegisterPhaseGroup_add_to(RegisterPhaseGroup, enum Rfg_Mode);
int RegisterPhaseGroup_should_apply(RegisterPhaseGroup, enum RegisterPhase);

#ifdef __cplusplus
}
#endif

#endif /* REGISTERPHASEGROUP_H_ */
