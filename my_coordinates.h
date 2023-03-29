#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "my_coordinates_consts.h"

void coord_to_pxl(float x, float y, float* x_pxl, float* y_pxl);

void draw_pxl(sf::RenderWindow& window, float x, float y, sf::Color clr);