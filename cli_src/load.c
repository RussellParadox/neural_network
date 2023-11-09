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
//| load.c |
//+========+

#include "nn_cli.h"

extern t_neural_network	*nn;

int	profile_parser(t_profile profile, char **split)
{
	if (split == NULL)
		return (-1);
}

int	load(char **cmd)
{
	FILE		*nn_file;
	t_profile	cli_profile;
	char		*line;
	size_t		line_size;
	unsigned int	i;

	if (split_len(cmd) != 2)
	{
		write(2, ARG_QT_ERROR, ARG_QT_ERROR_LEN);
		return (0);
	}
	nn_file = NULL;
	if (!access(cmd[1], F_OK | R_OK | W_OK))
		nn_file = fopen(cmd[1], "r+");
	else if (access(cmd[1], F_OK))
		write(2, FILE_EXIST_ERROR, FILE_EXIST_ERROR_LEN);
	else
		write(2, FILE_PERMISSION_ERROR, FILE_PERMISSION_ERROR_LEN);
	if (nn_file == NULL)
		return (0);
	line = NULL;
	i = 0;
	while (i < 9)
	{
		getline(&line, &line_size, nn_file);
		if (line == NULL)
			return (-1);
		if (profile_parser(t_profile profile, split_context(line, &is_not_comma)) == -1)
			return (0);
		free(line);
		line = NULL;
		i++;
	}
	fclose(nn_file);
	return (0);
}
