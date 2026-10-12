/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_seed9.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:38 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:45:08 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "malloc_stressTest/09_seed9.output"

int	malloc_stressTest_09_seed9(void)
{
	t_test_fds		data;

	if (malloc_rng_test(42000, 0, 9, 3) != 0)
		return (-1);
	return (0);
}
