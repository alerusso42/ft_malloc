/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_seed4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:39 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/12 23:36:29 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "realloc_stressTest/04_seed4.output"

int	realloc_stressTest_04_seed4(void)
{
	t_test_fds		data;
	data = child_init(OUTPUT_PATH);
	child_redirect(&data, 2);
	if (realloc_stressTest(42000, 0, 4, 3) != 0)
		return (child_cleanup(&data), -1);
	if (child_cmp(&data, LIBUNIT_FLAGS_EXIST, 2) != 0)
		return (child_cleanup(&data), -1);
	child_cleanup(&data);
	return (0);
}
