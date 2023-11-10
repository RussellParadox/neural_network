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
//| function_parser.c |
//+===================+

#include "nn_cli.h"

int	activation_function_parser(t_profile *profile, char *function)
{
	if (!strcmp(function, "sigmoid"))
	{
		profile->activation_function = &sigmoid;
		profile->activation_derivative = &sigmoid_derivative;
		return (0);
	}
	else
		return (write(2, UNKNOWN_FUNCTION_ERROR, UNKNOWN_FUNCTION_ERROR_LEN) * 0 - 1);
}

int	error_function_parser(t_profile *profile, char *function)
{
	if (!strcmp(function, "square"))
	{
		profile->error_function = &square;
		profile->error_derivative = &square_derivative;
		return (0);
	}
	else
		return (write(2, UNKNOWN_FUNCTION_ERROR, UNKNOWN_FUNCTION_ERROR_LEN) * 0 - 1);
}
