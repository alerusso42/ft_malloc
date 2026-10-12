/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_size100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 22:40:01 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:31:45 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "calloc/05_size100.output"

int	calloc_05_size100(void)
{
	t_test_fds		data;

	if (calloc_test(42, 100) != 0)
		return (-1);
	return (0);
}
