/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_memory_exaustion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:39 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:43:55 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "malloc/10_memory_exaustion.output"

int	malloc_10_memory_exaustion(void)
{
	t_test_fds		data;

	if (malloc_test(INT_MAX, -1) != 0)
		return (-1);
	return (0);
}
