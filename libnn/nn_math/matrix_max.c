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
//| matrix_max.c |
//+==============+

#include "nn_math.h"

float	matrix_max(t_matrix *m)
{
	float		max;
	unsigned int	i;
	unsigned int	j;

	max = m->v[0][0];
	i = 0;
	while (i < m->row)
	{
		j = 0;
		while (j < m->col)
		{
			if (m->v[i][j] > max)
				max = m->v[i][j];
			j++;
		}
		i++;
	}
	return (max);
}
