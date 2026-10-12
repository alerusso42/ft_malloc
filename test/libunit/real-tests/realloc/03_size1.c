/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_size1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:39 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:45:49 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "realloc/03_size1.output"

int	realloc_03_size1(void)
{
	t_test_fds		data;

	if (realloc_test(42, 1) != 0)
		return (-1);
	return (0);
}
