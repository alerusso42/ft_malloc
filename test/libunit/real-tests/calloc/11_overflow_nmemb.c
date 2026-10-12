/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_overflow_nmemb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:38 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/12 23:25:56 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "calloc/11_overflow_nmemb.output"

int	calloc_11_overflow_nmemb(void)
{
	t_test_fds		data;
	void			*ptr;

	data = child_init(OUTPUT_PATH);
	child_redirect(&data, 2);
	ptr = calloc(INT_MAX, 42);
	if (ptr)
		return (free(ptr), child_cleanup(&data), -1);
	if (child_cmp(&data, LIBUNIT_FLAGS_EXIST, 2) != 0)
		return (child_cleanup(&data), -1);
	child_cleanup(&data);
	return (0);
}
