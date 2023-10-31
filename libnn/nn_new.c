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
//| nn_new.c |
//+==========+

#include "nn.h"

static int	init_node(t_neural_network *nn, unsigned int layer_size[4])
{
	unsigned int	i;

	nn->node[0] = matrix_new(layer_size[1], 1);
	if (nn->node[0] == NULL)
		return (-1);
	matrix_init(nn->node[0], NULL, 0, 0);
	i = 1;
	while (i < layer_size[0] - 1)
	{
		nn->node[i] = matrix_new(layer_size[2], 1);
		if (nn->node[i] == NULL)
			return (-1);
		matrix_init(nn->node[i], NULL, 0, 0);
		i++;
	}
	nn->node[i] = matrix_new(layer_size[3], 1);
	if (nn->node[i] == NULL)
		return (-1);
	matrix_init(nn->node[i], NULL, 0, 0);
	nn->node[i + 1] = NULL;
	return (0);
}

static int	init_weight(t_neural_network *nn, unsigned int layer_size[4], float weight_min, float weight_max)
{
	unsigned int	i;

	nn->weight[0] = matrix_new(layer_size[2], layer_size[1]);
	if (nn->weight[0] == NULL)
		return (-1);
	matrix_init(nn->weight[0], NULL, weight_min, weight_max);
	i = 1;
	while (i < layer_size[0] - 2)
	{
		nn->weight[i] = matrix_new(layer_size[2], layer_size[2]);
		if (nn->weight[i] == NULL)
			return (-1);
		matrix_init(nn->weight[i], NULL, weight_min, weight_max);
		i++;
	}
	nn->weight[i] = matrix_new(layer_size[3], layer_size[2]);
	if (nn->weight[i] == NULL)
		return (-1);
	matrix_init(nn->weight[i], NULL, weight_min, weight_max);
	nn->weight[i + 1] = NULL;
	return (0);
}

//layer_size[0]: layer quantity
//layer_size[1]: size of input layer
//layer_size[2]: size of hidden layer
//layer_size[3]: size of output layer
t_neural_network	*nn_new(unsigned int layer_size[4], float weight_min, float weight_max)
{
	t_neural_network	*nn;

	nn = (t_neural_network *)malloc(sizeof(t_neural_network));
	if (nn == NULL)
		return (NULL);
	nn->node = (t_matrix **)malloc(sizeof(t_matrix *) * (layer_size[0] + 1));
	if (nn->node == NULL)
	{
		nn_free(nn);
		return (NULL);
	}
	nn->weight = (t_matrix **)malloc(sizeof(t_matrix *) * layer_size[0]);
	if (nn->weight == NULL)
	{
		nn_free(nn);
		return (NULL);
	}
	nn->node[0] = NULL;
	nn->weight[0] = NULL;
	if (init_node(nn, layer_size))
		return (NULL);
	if (init_weight(nn, layer_size, weight_min, weight_max))
		return (NULL);
	return (nn);
}