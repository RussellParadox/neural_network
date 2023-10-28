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

#include "math_nn.h"

void	matrix_product(t_matrix *m1, t_matrix *m2, t_matrix *result)
{
	unsigned int	i;
	unsigned int	j;

	if (m1->col != m2->row || result->row != m1->row || result->col != m2->col)
		return ;
	i = 0;
	while (i < result->row)
	{
		j = 0;
		while (j < result->col)
		{
			result->v[i][j] = row_col_scalar(m1, i, m2, j);
			j++;
		}
		i++;
	}
}
