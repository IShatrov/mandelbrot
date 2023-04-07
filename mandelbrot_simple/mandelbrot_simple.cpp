#include "mandelbrot_simple.h"

#define PXL_CLR(n) (sf::Color(0, 0, 255 - n))

void mandelbrot()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Mandelbrot");

	mandelbrot_start(window);

	window.display();

	wait_until_closed(window);

	return;
}

char check_iter(int iterations)
{
	return (iterations < MAX_ITERATIONS);
}

void wait_until_closed(sf::RenderWindow& window)
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	return;
}

void mandelbrot_start(sf::RenderWindow& window)
{
	time_t start_time = start_timer();

	for (float y0 = -MAX_Y; y0 < MAX_Y; y0 += dY)
	{
		for (float x0 = -MAX_X; x0 < MAX_X; x0 += dX)
		{
			int iterations = mandelbrot_calc(x0, y0);

			mandelbrot_draw(window, iterations, x0, y0);
		}
	}

	end_timer(start_time);

	return;
}

int mandelbrot_calc(float x0, float y0)
{
	int n_iterations = 0, iterations = 0;

	char is_in = 0;

	float xn = x0;
	float yn = y0;

	float xn_sq = xn * xn;
	float yn_sq = yn * yn;
	float xnyn = xn * yn;

	while (check_iter(iterations) && n_iterations < MAX_ITERATIONS)
	{
		xn = xn_sq - yn_sq;
		xn = xn + x0;

		yn = 2 * xnyn;
		yn = yn + y0;

		xn_sq = xn * xn;
		yn_sq = yn * yn;
		xnyn = xn * yn;

		float r_sq = xn_sq + yn_sq;

		is_in = (r_sq <= R_MAX_SQ);
		iterations = iterations + is_in;

		n_iterations++;
	}

	return iterations;
}

void mandelbrot_draw(sf::RenderWindow& window, int iter, float x, float y)
{

		draw_pxl(window, x, y, PXL_CLR(iter));

	return;
}

#undef PXL_CLR
