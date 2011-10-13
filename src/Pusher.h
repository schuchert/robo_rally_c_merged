#pragma once
#ifndef PUSHER_H_
#define PUSHER_H_


#ifdef __cplusplus
extern "C" {
#endif

#include "Coordinate.h"
#include "Movement.h"
#include "RegisterPhaseGroup.h"
struct Tile;
struct Tile *Pusher_create(enum Orientation, RegisterPhaseGroup group);

#ifdef __cplusplus
}
#endif

#endif /* PUSHER_H_ */
