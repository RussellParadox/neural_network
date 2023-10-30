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

void	print_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
	{
		write(1, cmd[i], strlen(cmd[i]));
		write(1, "\n", 1);
		i++;
	}
}

float	generator_test(float min, float max)
{
	(void)min;
	(void)max;
	return (1);
}

int	cli_loop(void)
{
	char	input[INPUT_LEN + 1];
	char	**cmd;
	unsigned int	layer_size[4];

	cmd = NULL;
	layer_size[0] = 5;
	layer_size[1] = 3;
	layer_size[2] = 3;
	layer_size[3] = 7;
	cli_nn = nn_new(layer_size, -1, 1);
	if (cli_nn == NULL)
		return (EXIT_FAILURE);
	nn_print(cli_nn);
	nn_free(cli_nn);
	while (1)
	{
		if (read_line(PROMPT, PROMPT_LEN, input, INPUT_LEN) < 0)
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
	return (cli_loop());
}
