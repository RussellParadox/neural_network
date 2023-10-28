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
//| neural_network.h |
//+==================+

#ifndef NEURAL_NETWORK_H
# define NEURAL_NETWORK_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <math_nn.h>

typedef struct s_neural_network
{
	t_matrix	*node;
	t_matrix	*weight;
}	t_neural_network;

//cli
# define PROMPT "<<< "
# define PROMPT_LEN strlen(PROMPT)
# define INPUT_LEN 500

//read line
int	read_line(char *prompt, int prompt_len, char *buffer, int buffer_len);

//free array
void	free_array(void *root, unsigned int dimension);

//split context
char	**split_context(char *str, int (*context)(char c));

//input parser
char	**input_parser(char input[INPUT_LEN + 1]);

//cmd parser
void	cmd_parser(char **cmd);

#endif
