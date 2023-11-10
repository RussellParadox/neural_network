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
//| cli.c |
//+=======+

#include "nn_cli.h"

//nn is for neural network
t_neural_network	*cli_nn;

int	cli_loop(void)
{
	char	input[INPUT_LEN + 1];
	char	**cmd;

	printf("coucou");
	fflush(stdout);
	while (1)
	{
		if (line_read(PROMPT, PROMPT_LEN, input, INPUT_LEN) < 0)
			break ;
		cmd = input_parser(input);
		if (cmd == NULL)
			return (EXIT_FAILURE);
		if (cmd[0] != NULL)
			cmd_parser(cmd);
		array_free(cmd, 2);
	}
	return (EXIT_SUCCESS);
}

//A neural network command line interface
int	main(void)
{
	cli_nn = NULL;
	return (cli_loop());
}
