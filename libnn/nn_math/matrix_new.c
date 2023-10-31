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
//| matrix_new.c |
//+==============+

#include "nn_math.h"

t_matrix	*matrix_new(unsigned int row, unsigned int col)
{
	t_matrix	*m;
	unsigned int	i;

	if (row < 1 || col < 1)
		return (NULL);
	m = (t_matrix *)malloc(sizeof(t_matrix));
	if (m == NULL)
		return (NULL);
	m->v = (float **)malloc(sizeof(float *) * (row + 1));
	if (m->v == NULL)
	{
		free(m);
		return (NULL);
	}
	i = 0;
	while (i < row)
	{
		m->v[i] = (float *)malloc(sizeof(float) * col);
		if (m->v[i] == NULL)
		{
			array_free(m->v, 2);
			free(m);
			return (NULL);
		}
		i++;
	}
	m->v[i] = NULL;
	m->row = row;
	m->col = col;
	return (m);
}
