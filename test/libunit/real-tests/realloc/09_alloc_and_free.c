/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_alloc_and_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:39 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:46:41 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "realloc/09_alloc_and_free.output"

int	realloc_09_alloc_and_free(void)
{
	t_test_fds		data;

	if (realloc_rng_test(42, 0, 1, 0) != 0)
		return (-1);
	return (0);
}
