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
//| nn_propagate.c |
//+================+

#include "nn.h"

void	nn_propagate(t_neural_network *nn)
{
	unsigned int	i;

	i = 0;
	while (nn->weight[i] != NULL)
	{
		matrix_product(nn->weight[i], nn->node[i], nn->node[i + 1]);
		matrix_apply(nn->node[i + 1], nn->activation_function);
		i++;
	}
	i = 0;
	while (i < nn->error[nn->len - 1]->row)
	{
		nn->error[nn->len - 1]->v[i][0] = nn->target->v[i][0] - nn->node[nn->len - 1]->v[i][0];
		i++;
	}
	matrix_apply(nn->error[nn->len - 1], nn->error_function);
}
