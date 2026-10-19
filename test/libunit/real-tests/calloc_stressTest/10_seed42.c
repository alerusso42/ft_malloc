/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_seed42.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:38 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:50:41 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "calloc_stressTest/10_seed42.output"

int	calloc_stressTest_10_seed42(void)
{
	if (calloc_rng_test(42000, 0, 42, 3) != 0)
		return (-1);
	return (0);
}
