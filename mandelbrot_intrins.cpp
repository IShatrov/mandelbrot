#include "mandelbrot_intrins.h"

void mandelbrot()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Mandelbrot");

	__m128 vec_twos = _mm_set_ps1(2);
	__m128 vec_rmax_sq = _mm_set_ps1(R_MAX_SQ);

	for (float y0 = -MAX_Y; y0 < MAX_Y; y0 += dY)
	{
		__m128 y0_vec = _mm_set_ps1(y0);
		__m128 y0_sq_vec = _mm_set_ps1(y0 * y0);

		for(float x0 = -MAX_X; x0 < MAX_X; x0 += VECTOR_SIZE * dX)
		{
			int n_iterations = 0;

			__m128 iterations = _mm_set_ps1(0);
			__m128 is_in = _mm_set_ps1(0);

			__m128 x0_vec = _mm_set_ps(x0, x0 + dX, x0 + 2 * dX, x0 + 3 * dX);

			__m128 xn = _mm_set_ps(x0, x0 + dX, x0 + 2 * dX, x0 + 3 * dX);
			__m128 yn = _mm_set_ps1(y0);

			__m128 xn_sq = _mm_mul_ps(xn, xn);
			__m128 yn_sq = _mm_mul_ps(yn, yn);
			__m128 xnyn = _mm_mul_ps(xn, yn);

			while (check_iter(iterations) && n_iterations < MAX_ITERATIONS)
			{
				xn = _mm_sub_ps(xn_sq, yn_sq);
				xn = _mm_add_ps(xn, x0_vec);

				yn = _mm_mul_ps(xnyn, vec_twos);
				yn = _mm_add_ps(yn, y0_vec);

				xn_sq = _mm_mul_ps(xn, xn);
				yn_sq = _mm_mul_ps(yn, yn);
				xnyn = _mm_mul_ps(xn, yn);

				__m128 r_sq = _mm_add_ps(xn_sq, yn_sq);

				is_in = _mm_cmpge_ps(r_sq, vec_rmax_sq);
				iterations = _mm_add_ps(iterations, is_in);

				n_iterations++;
			}

			float *ptr = (float*)(&iterations);
			float *ptrx = (float*)(&x0_vec);
			float *ptry = (float*)(&y0_vec);

			for (int i = 0; i < VECTOR_SIZE; i++)
			{
				float n = ptr[i];

				draw_pxl(window, ptrx[i], ptry[i], sf::Color(0, 0, 255 - n));
			}

		}
	}

	window.display();

	wait_until_closed(window);

	return;
}

char check_iter(__m128 iterations)
{
	char flag = 0;
	float *ptr = (float*)(&iterations);

	for (int i = 0; i < VECTOR_SIZE; i++)
	{
		if (ptr[i] < MAX_ITERATIONS) flag = 1;
	}

	return flag;
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
