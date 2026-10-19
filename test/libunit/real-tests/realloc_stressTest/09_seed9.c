/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_seed9.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:39 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:48:53 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "realloc_stressTest/09_seed9.output"

int	realloc_stressTest_09_seed9(void)
{
	if (realloc_rng_test(42000, 0, 9, 3) != 0)
		return (-1);
	return (0);
}
