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
//| weight_load.c |
//+===============+

#include "nn_cli.h"

extern t_neural_network	*cli_nn;

int	weight_load(char **cmd)
{
	FILE		*weight_file;
	char		*line;
	size_t		line_size;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (split_len(cmd) != 3)
	{
		write(2, ARG_QT_ERROR, ARG_QT_ERROR_LEN);
		return (0);
	}
	weight_file = fopen(cmd[2], "r");
	if (weight_file == NULL)
		return (write(2, CANT_OPEN_FILE_ERROR, CANT_OPEN_FILE_ERROR_LEN) * 0);
	line = NULL;
	i = 0;
	while (cli_nn->weight[i] != NULL)
	{
		j = 0;
		while (j < cli_nn->weight[i]->row)
		{
			k = 0;
			getline(&line, &line_size, weight_file);
			if (line == NULL)
				return (-1);
			if (word_count(line, &is_not_comma) != cli_nn->weight[i]->col)
			{
				free(line);
				return (write(2, FILE_FORMAT_ERROR, FILE_FORMAT_ERROR_LEN) * 0);
			}
			while (k < cli_nn->weight[i]->col)
			{
				sscanf(line, "%f", &cli_nn->weight[i]->v[j][k]);
				if (k != cli_nn->weight[i]->col - 1)
					sscanf(line, ",");
				k++;
			}
			free(line);
			line = NULL;
			j++;
		}
		i++;
	}
	fclose(weight_file);
	return (0);
}
