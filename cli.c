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

int	is_not_comma(char c)
{
	if (c == ',')
		return (0);
	return (1);
}

int	cli_loop(void)
{
	char	input[INPUT_LEN + 1];
	char	**cmd;
	unsigned int	layer_size[4];
	char	**label;
	char	**value;
	float	scale[3];

	cmd = NULL;
	layer_size[0] = 5;
	layer_size[1] = 4;
	layer_size[2] = 9;
	layer_size[3] = 7;
	cli_nn = nn_new(layer_size, -1 / sqrtf(layer_size[2]), 1 / sqrtf(layer_size[2]));
	if (cli_nn == NULL)
		return (EXIT_FAILURE);
	cli_nn->activation_function = &sigmoid;
	cli_nn->error_function = &square;
	nn_print(cli_nn, NODE);
	nn_print(cli_nn, ERROR);
	label = split_context("1,2,3,4,5,6,7,8,9", &is_not_comma);
	value = split_context("4,100,13,0,255", &is_not_comma);
	scale[0] = 255;
	scale[1] = 1;
	scale[2] = 0.01;
	nn_init(cli_nn, label, value, scale);
	nn_print(cli_nn, NODE);
	nn_propagate(cli_nn);
	nn_print(cli_nn, NODE);
	nn_print(cli_nn, ERROR);
	nn_free(cli_nn);
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
	return (cli_loop());
}
