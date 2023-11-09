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

unsigned int	label_to_index(char **label, char *value)
{
	unsigned int	i;

	i = 0;
	while (label[i] && strcmp(label[i], value))
		i++;
	return (i);
}

//Adapt the input values and target with scale, then assign it to nn.
//
//value[0]: label
//value[i(!=0)]: input values
//
//scale[0]: input max
//scale[1]: input min
//scale[2]: output max
//scale[3]: output min
void	nn_init(t_neural_network *nn, char **label, char **value, float scale[4])
{
	unsigned int	i;
	unsigned int	label_index;

	i = 0;
	while (nn->node[0]->v[i] != NULL)
	{
		nn->node[0]->v[i][0] = (strtof(value[i + 1], NULL) / (scale[0] - scale[1]) * (scale[2] - scale[3])) + scale[3];
		i++;
	}
	label_index = label_to_index(label, value[0]);
	i = 0;
	while (nn->target->v[i] != NULL)
	{
		if (i == label_index)
			nn->target->v[i][0] = scale[2];
		else
			nn->target->v[i][0] = scale[3];
		i++;
	}
}
