/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_seed1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:38 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 01:01:15 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "malloc_stressTest/01_seed1.output"

int	malloc_stressTest_01_seed1(void)
{
	if (malloc_rng_test(420, 0, 1, 3) != 0)
		return (-1);
	return (0);
}
