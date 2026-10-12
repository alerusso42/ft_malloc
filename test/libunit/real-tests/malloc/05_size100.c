/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_size100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:39 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:39:52 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "malloc/05_size100.output"

int	malloc_05_size100(void)
{
	t_test_fds		data;

	if (malloc_test(42, 100) != 0)
		return (-1);
	return (0);
}
