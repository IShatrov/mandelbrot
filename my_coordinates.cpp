#include "my_coordinates_consts.h"
#include "my_coordinates.h"

void coord_to_pxl(float x, float y, float* x_pxl, float* y_pxl)
{
	*x_pxl = WIDTH / 2 + x * WIDTH / (2 * MAX_X);
	*y_pxl = HEIGHT / 2 - y * HEIGHT / (2 * MAX_Y);

	return;
}

void draw_pxl(sf::RenderWindow& window, float x, float y, sf::Color clr)
{
	sf::RectangleShape pixel(sf::Vector2f(1, 1));
	pixel.setFillColor(clr);

	float x_pxl, y_pxl;
	coord_to_pxl(x, y, &x_pxl, &y_pxl);
	pixel.setPosition(x_pxl, y_pxl);
	window.draw(pixel);

	return;
}

time_t start_timer()
{
	return time(NULL);
}

void end_timer(time_t start_time)
{
	time_t fin_time = time(NULL);

	printf("Time spent: %d seconds\n", (int) (fin_time - start_time));
}