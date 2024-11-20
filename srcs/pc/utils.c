#include "cub3d.h"

// min et max inclus
// meme quand min=0
t_uint	rand_btw(t_uint min, t_uint max)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	srand(tv.tv_usec);
	return ((rand() % (max - min + 1)) + min);
}
