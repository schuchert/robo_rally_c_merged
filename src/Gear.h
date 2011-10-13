#pragma once
#ifndef GEAR_H_
#define GEAR_H_


#ifdef __cplusplus
extern "C" {
#endif

struct Tile;
#include "Movement.h"
#include "RegisterPhaseGroup.h"
struct Tile *Gear_create(enum Direction, enum Size, RegisterPhaseGroup group);

#ifdef __cplusplus
}
#endif

#endif /* GEAR_H_ */
