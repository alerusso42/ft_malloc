/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_seed3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:39 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:48:06 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "realloc_stressTest/03_seed3.output"

int	realloc_stressTest_03_seed3(void)
{
	if (realloc_rng_test(42000, 0, 3, 3) != 0)
		return (-1);
	return (0);
}
