/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_seed7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:38 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:38:26 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "calloc_stressTest/07_seed7.output"

int	calloc_stressTest_07_seed7(void)
{
	t_test_fds		data;

	if (calloc_rng_test(42000, 0, 7, 3) != 0)
		return (-1);
	return (0);
}
