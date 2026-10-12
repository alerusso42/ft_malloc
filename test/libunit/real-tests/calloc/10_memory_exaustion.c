/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_memory_exaustion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:38 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:33:37 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "calloc/10_memory_exaustion.output"

int	calloc_10_memory_exaustion(void)
{
	t_test_fds		data;

	if (calloc_test(INT_MAX, -1) != 0)
		return (-1);
	return (0);
}
