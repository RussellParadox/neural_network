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
//| nn_print.c |
//+============+

#include "nn.h"

void	nn_print(t_neural_network *nn)
{
	unsigned int	max_position;
	unsigned int	i;
	unsigned int	j;

	printf("\n");
	i = 0;
	max_position = 1;
	while (nn->node[i] != NULL)
	{
		j = 0;
		if (nn->node[i]->row > max_position)
			max_position = nn->node[i]->row;
		while (nn->node[i]->v[j] != NULL)
		{
			printf("\033[%dC", i * (8));
			printf("   %.2f\n", nn->node[i]->v[j][0]);
			j++;
		}
		i++;
		printf("\033[%dA", nn->node[i - 1]->row);
	}
	if (nn->target->row > max_position)
		max_position = nn->target->row;
	j = 0;
	while (nn->target->v[j] != NULL)
	{
		printf("\033[%dC", i * (8));
		printf("   %.2f\n", nn->target->v[j][0]);
		j++;
	}
	printf("\033[%dB\n", max_position + 1 - nn->target->row);
}
