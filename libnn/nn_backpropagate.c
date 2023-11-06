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
//| nn_backpropagate.c |
//+====================+

#include "nn.h"

void	nn_backpropagate(t_neural_network *nn)
{
	t_matrix	*weight_transposed;
	unsigned int	i;

	i = nn->len - 1;
	while (i > 0)
	{
		if (i == nn->len - 1)
		{
			weight_transposed = matrix_new(nn->weight[i - 1]->col, nn->weight[i - 1]->row);
			if (weight_transposed == NULL)
				return ;
		}
		else if (i == 1)
		{
			matrix_free(weight_transposed);
			weight_transposed = matrix_new(nn->weight[i - 1]->col, nn->weight[i - 1]->row);
			if (weight_transposed == NULL)
				return ;
		}
		else if (i == nn->len - 2)
		{
			matrix_free(weight_transposed);
			weight_transposed = matrix_new(nn->weight[i - 1]->col, nn->weight[i - 1]->row);
			if (weight_transposed == NULL)
				return ;
		}
		matrix_transpose(nn->weight[i - 1], weight_transposed);
		matrix_product(weight_transposed, nn->error[i], nn->error[i - 1]);
		i--;
	}
	matrix_free(weight_transposed);
}
