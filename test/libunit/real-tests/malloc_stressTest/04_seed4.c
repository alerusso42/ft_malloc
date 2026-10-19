/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_seed4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:38 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:50:41 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "malloc_stressTest/04_seed4.output"

int	malloc_stressTest_04_seed4(void)
{
	if (malloc_rng_test(42000, 0, 4, 3) != 0)
		return (-1);
	return (0);
}
