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
//| nn_cli.c |
//+==========+

#include "neural_network.h"

int	read_line(char *prompt, int prompt_len, char *buffer, int buffer_len)
{
	ssize_t	read_size;

	memset(buffer, '\0', buffer_len + 1);
	if (write(1, prompt, prompt_len) < 0)
		perror("write");
	else
	{
		read_size = read(0, buffer, buffer_len);
		if (read_size < 0)
			perror("read");
		else
		{
			if (read_size != 0)
				buffer[read_size - 1] = '\0';
			return (0);
		}
	}
	return (-1);
}

int	cli_loop(void)
{
	char	input[INPUT_LEN + 1];

	while (1)
	{
		if (read_line(PROMPT, PROMPT_LEN, input, INPUT_LEN) < 0)
			break ;
		//cli_parser(input);
		if (write(1, input, strlen(input)) < 0)
			perror("write");
		if (!strncmp(input, "exit", 5))
			break ;
	}
	return (EXIT_SUCCESS);
}

//A neural network command line interface
int	main(void)
{
	return (cli_loop());
}
