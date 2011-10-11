#pragma once
#ifndef PUSHER_H_
#define PUSHER_H_


#ifdef __cplusplus
extern "C" {
#endif

#include "RegisterPhaseGroup.h"
#include "Coordinate.h"
#include "Movement.h"
#include "Tile.h"

Tile *Pusher_create(enum Orientation, RegisterPhaseGroup group);
void Pusher_destroy(Tile *);

#ifdef __cplusplus
}
#endif

#endif /* PUSHER_H_ */
