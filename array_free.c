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
//| array_free.c |
//+==============+

#include "nn_cli.h"

void	array_nodes_free(void *node, size_t size, unsigned int dimension)
{
	if (node == NULL)
		return ;
	while (*(void **)node != NULL)
	{
		if (dimension > 2)
			array_nodes_free(*(void **)node, size, dimension - 1);
		free(*(void **)node);
		node += size;
	}
}

//free each dimension of a dynamic multi-dimensionnal
//array NULL terminated on any other dimension than the first
void	array_free(void *root, unsigned int dimension)
{
	if (root == NULL)
		return ;
	array_nodes_free(root, sizeof(void *), dimension);
	free(root);
}
