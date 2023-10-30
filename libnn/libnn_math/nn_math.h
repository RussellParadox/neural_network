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
//| nn_math.h |
//+===========+

#ifndef NN_MATH_H
# define NN_MATH_H
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <time.h>
# include <math.h>

typedef struct s_matrix
{
	float		**v;
	unsigned int	row;
	unsigned int	col;
}	t_matrix;

//matrix new
t_matrix	*matrix_new(unsigned int row, unsigned int col);

//matrix init
void	matrix_init(t_matrix *m, float (*generator)(float, float), float min, float max);

//matrix free
void	matrix_free(t_matrix *m);

//matrix print
void	matrix_print(t_matrix *m);

//matrix product
void	matrix_product(t_matrix *m1, t_matrix *m2, t_matrix *result);

//array free
void	array_free(void *root, unsigned int dimension);

#endif
