/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_seed8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:38 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:45:01 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "malloc_stressTest/08_seed8.output"

int	malloc_stressTest_08_seed8(void)
{
	t_test_fds		data;

	if (malloc_rng_test(42000, 0, 8, 3) != 0)
		return (-1);
	return (0);
}
