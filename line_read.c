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
//| line_read.c |
//+=============+

#include "nn_cli.h"

//Print a prompt and wait for an input, then redirect in buffer
int	line_read(char *prompt, int prompt_len, char *buffer, int buffer_len)
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
