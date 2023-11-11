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
//| cmd_parser.c |
//+==============+

#include "nn_cli.h"

extern t_neural_network	*cli_nn;

void	cmd_parser(char **cmd)
{
	if (!strcmp(cmd[0], "exit"))
	{
		array_free(cmd, 2);
		nn_free(cli_nn);
		exit(EXIT_SUCCESS);
	}
	else if (!strcmp(cmd[0], "load"))
	{
		if (split_len(cmd) != 3)
			write(2, ARG_QT_ERROR, ARG_QT_ERROR_LEN);
		else if (!strcmp(cmd[1], "profile"))
		{
			if (profile_load(cmd) == -1)
			{
				array_free(cmd, 2);
				nn_free(cli_nn);
				exit(EXIT_FAILURE);
			}
		}
		else if (!strcmp(cmd[1], "weight"))
		{
			if (weight_load(cmd) == -1)
			{
				array_free(cmd, 2);
				nn_free(cli_nn);
				exit(EXIT_FAILURE);
			}
		}
	}
	else if (!strcmp(cmd[0], "save"))
	{
		if (save(cmd) == -1)
		{
			array_free(cmd, 2);
			nn_free(cli_nn);
			exit(EXIT_FAILURE);
		}
	}
	else if (!strcmp(cmd[0], "train"))
	{
		if (train(cmd) == -1)
		{
			array_free(cmd, 2);
			nn_free(cli_nn);
			exit(EXIT_FAILURE);
		}
	}
	else if (!strcmp(cmd[0], "query"))
	{
		if (query(cmd) == -1)
		{
			array_free(cmd, 2);
			nn_free(cli_nn);
			exit(EXIT_FAILURE);
		}
	}
	else
		write(1, UNKNOWN_CMD, UNKNOWN_CMD_LEN);
}
