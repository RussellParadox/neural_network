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
//| nn_gradient_descent.c |
//+=======================+

#include "nn.h"

void	nn_gradient_descent(t_neural_network *nn)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = nn->len - 2;
	while (1)
	{
		j = 0;
		while (j < nn->weight[i]->row)
		{
			k = 0;
			while (k < nn->weight[i]->col)
			{
				nn->weight[i]->v[j][k] += nn->learning_rate * (*nn->error_derivative)(nn->error[i + 1]->v[j][0]) * (*nn->activation_derivative)(nn->node_input[i + 1]->v[j][0]) * nn->node[i]->v[k][0];
				k++;
			}
			j++;
		}
		if (i == 0)
			break ;
		i--;
	}
}
