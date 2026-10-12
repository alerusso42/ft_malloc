/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 14:32:41 by alerusso42        #+#    #+#             */
/*   Updated: 2026/10/12 23:59:34 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "../../../Libft/printf/ft_printf.h"

typedef enum e_func
{
	F_MALLOC,
	F_REALLOC,
	F_CALLOC
}		t_func;

typedef struct s_test
{
	void		**ptrs;
	t_func		func;
	int			len;
	size_t		size;
	int			randomizer;
	int			free_ratio;
}		t_test;

static void	*alloc(size_t size, t_func func, void *ptr);
static int	_test_end(t_test *data, const char *err);
static void	_rng_free(t_test *data, int i);
static void	_init_test_data(t_test *data, int len, size_t size, t_func func);

/**
 * @brief performs data->len allocations consisting of data->size bytes each.
 * 
 *  if data->randomizer != 0:
 * 
 *  1)	data->size is randomized;
 *  2)	pointers can be randomly freed during the allocation cycle.
 * 	the probability is given by data->free_ratio:
 * 	free_ratio == 0: 100% 
 * 	free_ratio == 1: 100% 
 * 	free_ratio == 2: 50% 
 * 	free_ratio == 3: 33% 
 * 	free_ratio == 4: 25% 
 * 	free_ratio == 5: 20%
 * 	...
 * 	the formula is: free_ratio || rand() % free_ratio 
 * @param data 
 * @return int 
 */
static int	_malloc_test(t_test *data)
{
	int	i;

	if (data->randomizer)
		srand(data->randomizer);
	data->ptrs = calloc(data->len, sizeof(void *));
	if (!data->ptrs)
		return (_test_end(data, NULL));
	i = 0;
	while (i != data->len)
	{
		if (data->randomizer)
			data->ptrs[i] = alloc(rand() % 100000, data->func, data->ptrs[i]);
		else
			data->ptrs[i] = alloc(data->size, data->func, data->ptrs[i]);
		if (!data->ptrs[i])
			return (_test_end(data, "out of memory\n"));
		if (data->randomizer)
			_rng_free(data, i);
		i++;
	}
	return (_test_end(data, NULL));
}

static void	*alloc(size_t size, t_func func, void *ptr)
{
	switch (func)
	{
		case (F_MALLOC):
			return (malloc(size));
		case (F_CALLOC):
			return (calloc(size, 1));
		case (F_REALLOC):
			return (realloc(ptr, size));
		default:
			return (NULL);
	}	
}

//free this test memory, prints and returns error when: 
//``` (!data->ptrs || err) ```
static int	_test_end(t_test *data, const char *err)
{
	uint64_t	b_alloc;
	uint64_t	b_freed;

	if (!data->ptrs)
		return (ft_printf("out of memory\n"), 1);
	for (int i = 0; i != data->len; i++)
	{
		free(data->ptrs[i]);
		data->ptrs[i] = NULL;
	}
	free(data->ptrs);
	if (err)
		return (ft_printf(err), 1);
	b_alloc = malloc_global_data()->bytes_alloc;
	b_freed = malloc_global_data()->bytes_freed;
	if (b_alloc != b_freed)
	{
		ft_printf("leak[%d] =\nalloc[%d] -\nfreed[%d]\n", 
			b_alloc - b_freed, b_alloc, b_freed);
		show_alloc_mem_ex(MALL_SHOW_PRINT_HEX);
		return (1);
	}
	return (0);
}

//pointers can be randomly freed during the allocation cycle.
//the formula is: free_ratio || rand() % free_ratio 
static void	_rng_free(t_test *data, int i)
{
	int	j;

	if (data->free_ratio && rand() % data->free_ratio != 0)
		return ;
	j = rand() % i;
	free(data->ptrs[j]);
	data->ptrs[j] = NULL;	
}

//SECTION - test entrypoint

static void	_init_test_data(t_test *data, int len, size_t size, t_func func)
{
	*data = (t_test){0};
	data->len = len;
	data->size = size;
	data->func = func;
}

int	malloc_test(int len, size_t size)
{
	t_test	data;

	_init_test_data(&data, len, size, F_MALLOC);
	return (_malloc_test(&data));
}

int	malloc_rng_test(int len, size_t size, int randomizer, int free_ratio)
{
	t_test	data;

	_init_test_data(&data, len, size, F_MALLOC);
	data.randomizer = randomizer;
	data.free_ratio = free_ratio;
	return (_malloc_test(&data));
}

int	calloc_test(int len, size_t size)
{
	t_test	data;

	_init_test_data(&data, len, size, F_CALLOC);
	return (_malloc_test(&data));
}

int	calloc_rng_test(int len, size_t size, int randomizer, int free_ratio)
{
	t_test	data;

	_init_test_data(&data, len, size, F_CALLOC);
	data.randomizer = randomizer;
	data.free_ratio = free_ratio;
	return (_malloc_test(&data));
}

int	realloc_test(int len, size_t size)
{
	t_test	data;

	_init_test_data(&data, len, size, F_REALLOC);
	return (_malloc_test(&data));
}

int	realloc_rng_test(int len, size_t size, int randomizer, int free_ratio)
{
	t_test	data;

	_init_test_data(&data, len, size, F_REALLOC);
	data.randomizer = randomizer;
	data.free_ratio = free_ratio;
	return (_malloc_test(&data));
}
