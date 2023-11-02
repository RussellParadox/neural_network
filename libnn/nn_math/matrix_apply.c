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
//| matrix_apply.c |
//+================+

#include "nn_math.h"

void	matrix_apply(t_matrix *m, float (*f)(float))
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < m->row)
	{
		j = 0;
		while (j < m->col)
		{
			m->v[i][j] = (*f)(m->v[i][j]);
			j++;
		}
		i++;
	}
}
