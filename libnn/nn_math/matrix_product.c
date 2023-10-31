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
//| matrix_product.c |
//+==================+

#include "nn_math.h"

float	row_col_product(t_matrix *m1, t_matrix *m2, unsigned int row, unsigned int col)
{
	float		result;
	unsigned int	i;

	result = 0;
	i = 0;
	while (i < m1->col)
	{
		result += m1->v[row][i] * m2->v[i][col];
		i++;
	}
	return (result);
}

void	matrix_product(t_matrix *m1, t_matrix *m2, t_matrix *result)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < result->row)
	{
		j = 0;
		while (j < result->col)
		{
			result->v[i][j] = row_col_product(m1, m2, i, j);
			j++;
		}
		i++;
	}
}
