//+=================================================================+
//|                                                                 |
//|    ______  ______   _____                                       |
//|   / ___\ \|  _ \ \ / _ \ \ _ __ __ _  __ _ _ __   ___  _ __     |
//|   \___ \\ \ | | \ \ | | \ \ '__/ _` |/ _` | '_ \ / _ \| '_ \    |
//|    ___) / / |_| / / |_| / / | | (_| | (_| | | | | (_) | | | |   |
//|   |____/_/|____/_/ \___/_/|_|  \__, |\__,_|_| |_|\___/|_| |_|   |
//|                                |___/                            |
//|                                                                 |
//+=================================================================+
//| project: neural_network |
//+=========================+
//| matrix_init.c |
//+===============+

#include "math_nn.h"

float	default_generator(float min, float max)
{
	(void)min;
	(void)max;
	return (0.);
}

void	matrix_init(t_matrix *m, float (*generator)(float, float), float min, float max)
{
	unsigned int	i;
	unsigned int	j;

	if (generator == NULL)
		generator = &default_generator;
	i = 0;
	while (i < m->row)
	{
		j = 0;
		while (j < m->col)
		{
			m->v[i][j] = (*generator)(min, max);
			j++;
		}
		i++;
	}
}
