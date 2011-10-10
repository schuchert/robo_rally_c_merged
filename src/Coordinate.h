#pragma once
#ifndef COORDINATE_H_
#define COORDINATE_H_


#ifdef __cplusplus
extern "C" {
#endif

typedef struct Coordinate {
	int x;
	int y;
} Coordinate;

Coordinate Coordinate_create(int x, int y);
int Coordinate_are_equal(Coordinate, Coordinate);

#ifdef __cplusplus
}
#endif

#endif /* COORDINATE_H_ */
