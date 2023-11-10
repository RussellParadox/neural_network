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
	t_matrix	**node_input;
	t_matrix	**error;
	t_matrix	**weight;
	t_matrix	*target;
	unsigned int	len;
	char		**label;
	unsigned int	layer_size[4];
	float		scale[4];
	float		(*activation_function)(float);
	float		(*activation_derivative)(float);
	float		(*error_function)(float);
	float		(*error_derivative)(float);
	float		learning_rate;
}	t_neural_network;

//nn free
void	nn_free(t_neural_network *nn);

//nn new
t_neural_network	*nn_new(unsigned int layer_size[4], float weight_min, float weight_max);

//nn print
# define NODE 0
# define ERROR 1
# define NODE_INPUT 2
void	nn_print(t_neural_network *nn, int mode);

//nn init
void	nn_init(t_neural_network *nn, char **label, char **value, float scale[4]);

//nn propagate
void	nn_propagate(t_neural_network *nn);

//nn backpropagate
void	nn_backpropagate(t_neural_network *nn);

//nn gradient descent
void	nn_gradient_descent(t_neural_network *nn);

//nn train
void	nn_train(t_neural_network *nn);

#endif
