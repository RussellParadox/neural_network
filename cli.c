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
	t_matrix	*m1;
	t_matrix	*m2;
	t_matrix	*m3;

	printf("fmodf: %.3f\n", fmodf(50, -5.3));
	m1 = matrix_new(3, 3);
	m2 = matrix_new(3, 3);
	m3 = matrix_new(3, 3);
	matrix_init(m1, NULL, 0, 5);
	matrix_init(m2, NULL, 0, 10);
	matrix_print(m1);
	matrix_print(m2);
	matrix_product(m1, m2, m3);
	matrix_print(m3);
	matrix_free(m1);
	matrix_free(m2);
	matrix_free(m3);
	cmd = NULL;
	while (1)
	{
		if (read_line(PROMPT, PROMPT_LEN, input, INPUT_LEN) < 0)
			break ;
		cmd = input_parser(input);
		if (cmd == NULL)
			break ;
		if (cmd[0] != NULL)
			cmd_parser(cmd);
		free_array(cmd, 2);
	}
	return (EXIT_SUCCESS);
}

//A neural network command line interface
int	main(void)
{
	return (cli_loop());
}
