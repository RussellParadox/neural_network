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
//| query.c |
//+=========+

#include "nn_cli.h"

extern t_neural_network *cli_nn;

unsigned int	layer_max_index(t_matrix *layer)
{
	float		max;
	unsigned int	i;
	unsigned int	i_max;

	i = 0;
	i_max = 0;
	max = layer->v[0][0];
	while (i < layer->row)
	{
		if (layer->v[i][0] > max)
		{
			max = layer->v[i][0];
			i_max = i;
		}
		i++;
	}
	return (i_max);
}

int	query(char **cmd)
{
	FILE		*query_file;
	char		*line;
	size_t		line_size;
	char		**value;
	unsigned int	sum;
	unsigned int	total;
	unsigned int	max_index;
	unsigned int	target_index;

	if (split_len(cmd) != 2)
		return (write(2, ARG_QT_ERROR, ARG_QT_ERROR_LEN) * 0);
	query_file = fopen(cmd[1], "r");
	if (query_file == NULL)
		return (write(2, CANT_OPEN_FILE_ERROR, CANT_OPEN_FILE_ERROR_LEN) * 0);
	line = NULL;
	sum = 0;
	total = 0;
	while (getline(&line, &line_size, query_file) > 0)
	{
		if (line == NULL)
			return (-1);
		value = split_context(line, &is_not_comma);
		free(line);
		line = NULL;
		if (value == NULL)
			return (-1);
		if (split_len(value) != cli_nn->layer_size[1] + 1)
		{
			array_free(value, 2);
			return (write(2, FILE_FORMAT_ERROR, FILE_FORMAT_ERROR_LEN) * 0);
		}
		nn_init(cli_nn, &(cli_nn->label[1]), value, cli_nn->scale);
		nn_propagate(cli_nn);
		max_index = layer_max_index(cli_nn->node[cli_nn->len - 1]);
		target_index = layer_max_index(cli_nn->target);
		if (max_index == target_index)
			sum += 1;
		total++;
	}
	if (total != 0)
	{
		printf("\n\tMean score: %f%%\n", (float)sum / (float)total * 100.);
		fflush(stdout);
	}
	return (0);
}
