/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_alloc_and_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:38 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:50:41 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "calloc/09_alloc_and_free.output"

int	calloc_09_alloc_and_free(void)
{
	if (calloc_rng_test(42, 0, 1, 0) != 0)
		return (-1);
	return (0);
}
