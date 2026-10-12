/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_memory_exaustion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:38 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/12 23:10:00 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "calloc/10_memory_exaustion.output"

int	calloc_10_memory_exaustion(void)
{
	t_test_fds		data;
	data = child_init(OUTPUT_PATH);
	child_redirect(&data, 2);
	if (calloc_test(INT_MAX, -1) != 0)
		return (child_cleanup(&data), -1);
	if (child_cmp(&data, LIBUNIT_FLAGS_EXIST, 2) != 0)
		return (child_cleanup(&data), -1);
	child_cleanup(&data);
	return (0);
}
