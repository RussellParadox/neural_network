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
//| load_profile.c |
//+================+

#include "nn_cli.h"

extern t_neural_network	*cli_nn;

int	profile_parser(t_profile *profile, char **split)
{
	if (!strcmp(split[0], "layer size"))
	{
		if (split_len(split) != 5)
			return (write(2, FILE_FORMAT_ERROR, FILE_FORMAT_ERROR_LEN) * 0 - 1);
		profile->layer_size[0] = strtoumax(split[1], NULL, 0);
		profile->layer_size[1] = strtoumax(split[2], NULL, 0);
		profile->layer_size[2] = strtoumax(split[3], NULL, 0);
		profile->layer_size[3] = strtoumax(split[4], NULL, 0);
		array_free(split, 2);
	}
	else if (!strcmp(split[0], "label"))
		profile->label = split;
	else if (!strcmp(split[0], "value range"))
	{
		if (split_len(split) != 3)
			return (write(2, FILE_FORMAT_ERROR, FILE_FORMAT_ERROR_LEN) * 0 - 1);
		profile->scale[0] = strtof(split[2], NULL);
		profile->scale[1] = strtof(split[1], NULL);
		array_free(split, 2);
	}
	else if (!strcmp(split[0], "node range"))
	{
		if (split_len(split) != 3)
			return (write(2, FILE_FORMAT_ERROR, FILE_FORMAT_ERROR_LEN) * 0 - 1);
		profile->scale[2] = strtof(split[2], NULL);
		profile->scale[3] = strtof(split[1], NULL);
		array_free(split, 2);
	}
	else if (!strcmp(split[0], "activation function"))
	{
		if (split_len(split) != 2)
			return (write(2, FILE_FORMAT_ERROR, FILE_FORMAT_ERROR_LEN) * 0 - 1);
		if (activation_function_parser(profile, split[1]) != 0)
			return (-1);
		array_free(split, 2);
	}
	else if (!strcmp(split[0], "error function"))
	{
		if (split_len(split) != 2)
			return (write(2, FILE_FORMAT_ERROR, FILE_FORMAT_ERROR_LEN) * 0 - 1);
		if (error_function_parser(profile, split[1]) != 0)
			return (-1);
		array_free(split, 2);
	}
	else if (!strcmp(split[0], "learning rate"))
	{
		if (split_len(split) != 2)
			return (write(2, FILE_FORMAT_ERROR, FILE_FORMAT_ERROR_LEN) * 0 - 1);
		profile->learning_rate = strtof(split[1], NULL);
		array_free(split, 2);
	}
	else
	{
		array_free(split, 2);
		return (write(2, FILE_FORMAT_ERROR, FILE_FORMAT_ERROR_LEN) * 0 - 1);
	}
	return (0);
}

int	load_profile(char **cmd)
{
	FILE		*nn_file;
	t_profile	cli_profile;
	char		*line;
	size_t		line_size;
	char		**split;
	unsigned int	i;

	if (split_len(cmd) != 3)
	{
		write(2, ARG_QT_ERROR, ARG_QT_ERROR_LEN);
		return (0);
	}
	nn_file = NULL;
	if (!access(cmd[2], F_OK | R_OK | W_OK))
		nn_file = fopen(cmd[2], "r+");
	else if (access(cmd[2], F_OK))
		write(2, FILE_EXIST_ERROR, FILE_EXIST_ERROR_LEN);
	else
		write(2, FILE_PERMISSION_ERROR, FILE_PERMISSION_ERROR_LEN);
	if (nn_file == NULL)
		return (0);
	line = NULL;
	cli_profile.label = NULL;
	i = 0;
	while (i < 7)
	{
		getline(&line, &line_size, nn_file);
		if (line == NULL)
		{
			if (cli_profile.label != NULL)
				array_free(cli_profile.label, 2);
			return (-1);
		}
		line_size = strlen(line);
		if (line_size > 0 && line[line_size - 1] == '\n')
			line[line_size - 1] = '\0';
		split = split_context(line, &is_not_comma);
		free(line);
		if (split == NULL)
		{
			if (cli_profile.label != NULL)
				array_free(cli_profile.label, 2);
			return (-1);
		}
		if (profile_parser(&cli_profile, split) != 0)
		{
			if (cli_profile.label != NULL)
				array_free(cli_profile.label, 2);
			return (0);
		}
		line = NULL;
		i++;
	}
	fclose(nn_file);
	cli_nn = nn_new(cli_profile.layer_size, 0, 0);
	if (cli_nn == NULL)
	{
		array_free(cli_profile.label, 2);
		return (-1);
	}
	cli_nn->label = cli_profile.label;
	cli_nn->layer_size[0] = cli_profile.layer_size[0];
	cli_nn->layer_size[1] = cli_profile.layer_size[1];
	cli_nn->layer_size[2] = cli_profile.layer_size[2];
	cli_nn->layer_size[3] = cli_profile.layer_size[3];
	cli_nn->scale[0] = cli_profile.scale[0];
	cli_nn->scale[1] = cli_profile.scale[1];
	cli_nn->scale[2] = cli_profile.scale[2];
	cli_nn->scale[3] = cli_profile.scale[3];
	cli_nn->activation_function = cli_profile.activation_function;
	cli_nn->activation_derivative = cli_profile.activation_derivative;
	cli_nn->error_function = cli_profile.error_function;
	cli_nn->error_derivative = cli_profile.error_derivative;
	cli_nn->learning_rate = cli_profile.learning_rate;
	return (0);
}
