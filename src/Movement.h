#pragma once
#ifndef DIRECTION_H_
#define DIRECTION_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Coordinate.h"
enum Orientation { N = 0, E = 1, S = 2, W = 3 };
enum Direction { forward = 1, backwards = -1, clockwise = 1, counter_clockwise = -1 };
enum Size { Size1 = 1, Size2 = 2, Size3 = 3, D90 = 1, D180 = 2, D270 = 3, D360 = 4  };

enum BoardElementMove {
    Bem_ParticleAccelerator,
    Bem_AirShaft,
    Bem_RotatingBelts,
    Bem_Conveyor_1,
    Bem_Conveyor_2,
    Bem_Conveyor_3,
    Bem_FlipConveyor,
    Bem_WaterCurrent,
    Bem_JackPopsOut,
    Bem_Pusher,
    Bem_Gear,
    Bem_Crusher
};
enum Orientation Orientation_rotate(enum Orientation, enum Direction, enum Size);
struct Coordinate Direction_apply(enum Orientation, enum Direction, enum Size, Coordinate);
enum Orientation Orientation_actual(enum Orientation, enum Direction);

#ifdef __cplusplus
}
#endif

#endif /* DIRECTION_H_ */
