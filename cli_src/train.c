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
//| train.c |
//+=========+

#include "nn_cli.h"

extern t_neural_network	*cli_nn;

int	train(char **cmd)
{
	FILE		*train_file;
	char		*line;
	size_t		line_size;
	char		**value;
	unsigned int	epoch;
	unsigned int	i;

	if (split_len(cmd) > 3 || split_len(cmd) < 2)
		return (write(2, ARG_QT_ERROR, ARG_QT_ERROR_LEN) * 0);
	train_file = fopen(cmd[1], "r");
	if (train_file == NULL)
		return (write(2, CANT_OPEN_FILE_ERROR, CANT_OPEN_FILE_ERROR_LEN) * 0);
	if (cmd[2] != NULL)
		epoch = strtoumax(cmd[2], NULL, 0);
	else
		epoch = 1;
	line = NULL;
	while (getline(&line, &line_size, train_file) > 0)
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
		i = 0;
		while (i < epoch)
		{
			nn_propagate(cli_nn);
			nn_backpropagate(cli_nn);
			nn_gradient_descent(cli_nn);
			i++;
		}
	}
	fclose(train_file);
	return (0);
}
