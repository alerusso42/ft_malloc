/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_alloc_and_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:39 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:43:47 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "malloc/09_alloc_and_free.output"

int	malloc_09_alloc_and_free(void)
{
	t_test_fds		data;

	if (malloc_rng_test(42, 0, 1, 0) != 0)
		return (-1);
	return (0);
}
