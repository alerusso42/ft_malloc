/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_size10000000.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 22:40:01 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/12 23:07:49 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "calloc/08_size10000000.output"

int	calloc_08_size10000000(void)
{
	t_test_fds		data;
	data = child_init(OUTPUT_PATH);
	child_redirect(&data, 2);
	if (calloc_test(42, 10000000) != 0)
		return (child_cleanup(&data), -1);
	if (child_cmp(&data, LIBUNIT_FLAGS_EXIST, 2) != 0)
		return (child_cleanup(&data), -1);
	child_cleanup(&data);
	return (0);
}
