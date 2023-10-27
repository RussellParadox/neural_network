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
//| free_array.c |
//+==============+

#include "neural_network.h"

void	free_array_nodes(void *node, size_t size, unsigned int dimension)
{
	if (node == NULL)
		return ;
	while (*(void **)node != NULL)
	{
		if (dimension > 2)
			free_array_nodes(*(void **)node, size, dimension - 1);
		free(*(void **)node);
		node += size;
	}
}

//free each dimension of a dynamic multi-dimensionnal
//array NULL terminated on any other dimension than the first
void	free_array(void *root, unsigned int dimension)
{
	if (root == NULL)
		return ;
	free_array_nodes(root, sizeof(void *), dimension);
	free(root);
}
