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
//| nn_free.c |
//+===========+

#include "nn.h"

void	nn_free(t_neural_network *nn)
{
	unsigned int	i;

	if (nn != NULL)
	{
		if (nn->node != NULL)
		{
			i = 0;
			while (nn->node[i] != NULL)
			{
				matrix_free(nn->node[i]);
				i++;
			}
			free(nn->node);
		}
		if (nn->node_input != NULL)
		{
			i = 0;
			while (nn->node_input[i] != NULL)
			{
				matrix_free(nn->node_input[i]);
				i++;
			}
			free(nn->node_input);
		}
		if (nn->error != NULL)
		{
			i = 0;
			while (nn->error[i] != NULL)
			{
				matrix_free(nn->error[i]);
				i++;
			}
			free(nn->error);
		}
		if (nn->weight != NULL)
		{
			i = 0;
			while (nn->weight[i] != NULL)
			{
				matrix_free(nn->weight[i]);
				i++;
			}
			free(nn->weight);
		}
		if (nn->target != NULL)
			matrix_free(nn->target);
		if (nn->label != NULL)
			array_free(nn->label, 2);
		free(nn);
	}
}
