/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_size10000.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 22:40:01 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:32:22 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "calloc/06_size10000.output"

int	calloc_06_size10000(void)
{
	t_test_fds		data;

	if (calloc_test(42, 10000) != 0)
		return (-1);
	return (0);
}
