#pragma once
#ifndef Coordinate_test_helper_h
#define coordinate_test_helper_h

#include <CppUTest/TestHarness.h>
#include "Coordinate.h"

bool operator !=(Coordinate lhs, Coordinate rhs);
SimpleString StringFrom(Coordinate c);

#endif
