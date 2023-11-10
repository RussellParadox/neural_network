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
//| save.c |
//+========+

#include "nn_cli.h"

extern t_neural_network *cli_nn;

int	save(char **cmd)
{
	FILE		*weight_file;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (split_len(cmd) != 2)
	{
		write(2, ARG_QT_ERROR, ARG_QT_ERROR_LEN);
		return (0);
	}
	weight_file = fopen(cmd[1], "w");
	if (weight_file == NULL)
		return (-1);
	i = 0;
	while (cli_nn->weight[i] != NULL)
	{
		j = 0;
		while (j < cli_nn->weight[i]->row)
		{
			k = 0;
			while (k < cli_nn->weight[i]->col)
			{
				fprintf(weight_file, "%f", cli_nn->weight[i]->v[j][k]);
				if (k != cli_nn->weight[i]->col - 1)
					fprintf(weight_file, ",");
				k++;
			}
			fprintf(weight_file, "\n");
			j++;
		}
		i++;
	}
	fclose(weight_file);
	return (0);
}
