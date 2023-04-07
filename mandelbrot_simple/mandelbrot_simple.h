#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <emmintrin.h>

#include "mandelbrot_consts.h"
#include "../my_coordinates.h"

void mandelbrot();

//return 1 if must continue
char check_iter(int iterations);

void wait_until_closed(sf::RenderWindow& window);

void mandelbrot_start(sf::RenderWindow& window);

int mandelbrot_calc(float x0, float y0);

void mandelbrot_draw(sf::RenderWindow& window, int iter, float x, float y);
