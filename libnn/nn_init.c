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
//| nn_init.c |
//+===========+

#include "nn.h"

//layer_size[0]: size of input layer
//layer_size[1]: size of hidden layer
//layer_size[2]: size of output layer
t_neural_network	*nn_new(unsigned int layer_quantity, unsigned int layer_size[3], float weight_min, float weight_max)
{
	t_neural_network	*nn;

	nn = (t_neural_network *)malloc(sizeof(t_neural_network));
	if (nn == NULL)
		return (NULL);
	nn->node = (t_matrix **)malloc(sizeof(t_matrix *) * layer_quantity);
	if (nn->node == NULL)
	{
		nn_free(nn);
		return (NULL);
	}
	nn->weight = (t_matrix **)malloc(sizeof(t_matrix *) * (layer_quantity - 1));
	if (nn->weight == NULL)
	{
		free(nn->weight);
		return (-1);
	}
	nn->node[0] = matrix_new(layer_size[1], 1);
	if (nn->node[0] == NULL)

}
