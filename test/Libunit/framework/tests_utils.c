/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 14:32:41 by alerusso42        #+#    #+#             */
/*   Updated: 2026/10/11 14:58:44 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static int	test_error(const char *s);
static void	rng_free(void **ptrs, int len, int free_ratio);

static int	_malloc_test(int len, int size, int randomizer, int free_ratio)
{
	void	**ptrs;
	int		i;

	if (randomizer)
		srand(randomizer);
	ptrs = calloc(len, sizeof(void *));
	if (!ptrs)
		return (test_end(ptrs, len, NULL));
	i = len;
	while (i--)
	{
		if (randomizer)
			ptrs[i] = malloc(rand() % 100000);
		else
			ptrs[i] = malloc(size);
		if (!ptrs[i])
			return (test_end(ptrs, len, "out of memory\n"));
		if (randomizer)
			rng_free(ptrs, len, free_ratio);
	}
	return (test_end(ptrs, len, NULL));
}

int	malloc_test(int len, int size)
{
	return (_malloc_test(len, size, 0, 0));
}

int	malloc_rng_test(int len, int size, int randomizer, int free_ratio)
{
	return (_malloc_test(len, size, randomizer, free_ratio));
}

static int	test_end(void **ptrs, int len, const char *err)
{
	if (!ptrs)
	{
		write(2, "out of memory\n", strlen("out of memory\n"));
		return (1);
	}
	for (int i = 0; i != len; i++)
	{
		free(ptrs[i]);
		ptrs[i] = NULL;
	}
	free(ptrs);
	if (!err)
		return (0);
	write(2, err, strlen(err));
	return (1);
}

static void	rng_free(void **ptrs, int len, int free_ratio)
{
	int	i;

	if (free_ratio && rand() % free_ratio != 0)
		return ;
	i = rand() % len;
	free(ptrs[i]);
	ptrs[i] = NULL;	
}
