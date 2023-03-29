#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <emmintrin.h>

#include "mandelbrot_consts.h"
#include "my_coordinates.h"

void mandelbrot();

//return 1 if must continue
char check_iter(__m128 iterations);
