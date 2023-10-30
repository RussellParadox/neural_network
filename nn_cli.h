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
//| nn_cli.h |
//+==========+

#ifndef NN_CLI_H
# define NN_CLI_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <nn.h>

//cli
# define PROMPT ">>> "
# define PROMPT_LEN strlen(PROMPT)
# define INPUT_LEN 500

//read line
int	read_line(char *prompt, int prompt_len, char *buffer, int buffer_len);

//array free
void	array_free(void *root, unsigned int dimension);

//split context
char	**split_context(char *str, int (*context)(char c));

//input parser
char	**input_parser(char input[INPUT_LEN + 1]);

//cmd parser
void	cmd_parser(char **cmd);

#endif
