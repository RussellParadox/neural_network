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
//| nn.h |
//+======+

#ifndef NN_H
# define NN_H
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <string.h>
# include "nn_math.h"

typedef struct s_neural_network
{
	t_matrix	**node;
	t_matrix	**error;
	t_matrix	**weight;
	t_matrix	*target;
	unsigned int	len;
	float		(*activation)(float);
	float		(*error_derivative)(float);
	float		(*activation_derivative)(float);
	float		learning_rate;
}	t_neural_network;

//nn free
void	nn_free(t_neural_network *nn);

//nn new
t_neural_network	*nn_new(unsigned int layer_size[4], float weight_min, float weight_max);

//nn print
void	nn_print(t_neural_network *nn);

//nn init
void	nn_init(t_neural_network *nn, char **label, char **value, float scale[3]);

//nn propagate
void	nn_propagate(t_neural_network *nn);

#endif
