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

#include "neural_network.h"

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

int	cli_loop(void)
{
	char	input[INPUT_LEN + 1];
	char	**cmd;

	cmd = NULL;
	while (1)
	{
		if (read_line(PROMPT, PROMPT_LEN, input, INPUT_LEN) < 0)
			break ;
		cmd = input_parser(input);
		if (cmd == NULL)
			break ;
		cmd_parser(cmd);
		//print_cmd(cmd);
		free_array(cmd, 2);
	}
	return (EXIT_SUCCESS);
}

//A neural network command line interface
int	main(void)
{
	return (cli_loop());
}
