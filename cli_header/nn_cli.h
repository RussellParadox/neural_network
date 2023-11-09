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
# define PROMPT "\n>>> "
# define PROMPT_LEN strlen(PROMPT)
# define INPUT_LEN 500
# define UNKNOWN_CMD "\tUnknown command."
# define UNKNOWN_CMD_LEN strlen(UNKNOWN_CMD)
# define ARG_QT_ERROR "Wrong argument quantity."
# define ARG_QT_ERROR_LEN strlen(ARG_QT_ERROR)
# define FILE_FORMAT_ERROR "Wrongly formatted file."
# define FILE_FORMAT_ERROR_LEN strlen(FILE_FORMAT_ERROR)
# define FILE_EXIST_ERROR "File not found."
# define FILE_EXIST_ERROR_LEN strlen(FILE_EXIST_ERROR)
# define FILE_PERMISSION_ERROR "Wrong permissions, need write and read."
# define FILE_PERMISSION_ERROR_LEN strlen(FILE_PERMISSION_ERROR)

//line read
int	line_read(char *prompt, int prompt_len, char *buffer, int buffer_len);

//array free
void	array_free(void *root, unsigned int dimension);

//split context
char	**split_context(char *str, int (*context)(char c));

//input parser
char	**input_parser(char input[INPUT_LEN + 1]);

//cmd parser
void	cmd_parser(char **cmd);

//split len
unsigned int	split_len(char **split);

//is not comma
int	is_not_comma(char c);

//load
int	load(char **cmd);

#endif
