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
	if (!strcmp(cmd[0], "load"))
		load(cmd);
	if (!strcmp(cmd[0], "init"))
		init(cmd);
	if (!strcmp(cmd[0], "train"))
		train(cmd);
	if (!strcmp(cmd[0], "query"))
		query(cmd);
	else
		write(1, UNKNOWN_CMD, UNKNOWN_CMD_LEN);
}
