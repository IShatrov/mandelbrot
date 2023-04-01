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

void wait_until_closed(sf::RenderWindow& window);

void mandelbrot_start(sf::RenderWindow& window);

__m128 mandelbrot_calc(__m128 x0_vec, __m128 y0_vec);

void mandelbrot_draw(sf::RenderWindow& window, float* iter_ptr, float* x_ptr, float* y_ptr);
