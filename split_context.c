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
//| split_context.c |
//+=================+

#include "neural_network.h"

unsigned int	word_size(char *str, int (*context)(char c))
{
	unsigned int	size;

	size = 0;
	while (*str && (*context)(*str))
	{
		size++;
		str++;
	}
	return (size);
}

unsigned int	word_count(char *str, int (*context)(char c))
{
	unsigned int	count;

	count = 0;
	while (*str)
	{
		if ((*context)(*str))
		{
			count++;
			str += word_size(str, context);
		}
		else
			str++;
	}
	return (count);
}

//Split the string str in words defined by a context function.
//The context function tell us if the character pointed by c is a part of the word or not(i.e.: return true or false).
char	**split_context(char *str, int (*context)(char c))
{
	unsigned int	split_len;
	unsigned int	size;
	unsigned int	i;
	char		**split;

	split_len = word_count(str, context);
	split = (char **)malloc(sizeof(char *) * (split_len + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (*str)
	{
		if ((*context)(*str))
		{
			size = word_size(str, context);
			split[i] = (char *)malloc(sizeof(char) * (size + 1));
			if (split[i] == NULL)
			{
				free_array(split, 2);
				return (NULL);
			}
			memcpy(split[i], str, (size_t)size);
			split[i][size] = '\0';
			str += size;
			i++;
		}
		else
			str++;
	}
	split[i] = NULL;
	return (split);
}

/*
int	isnotspace(char c)
{
	return (!isspace(c));
}

int	main(void)
{
	char	str[] = " a kafj adb pl ";
	char	**split;
	int	i;

	split = split_context(str, isnotspace);
	i = 0;
	while (split[i])
	{
		printf("word: %s\n", split[i]);
		i++;
	}
	free_array(split, 2);
}
*/
