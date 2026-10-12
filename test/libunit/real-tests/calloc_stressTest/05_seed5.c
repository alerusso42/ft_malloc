/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_seed5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:38 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:38:07 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "calloc_stressTest/05_seed5.output"

int	calloc_stressTest_05_seed5(void)
{
	t_test_fds		data;

	if (calloc_rng_test(42000, 0, 5, 3) != 0)
		return (-1);
	return (0);
}
