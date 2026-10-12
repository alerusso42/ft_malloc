/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_zero_nmemb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:38 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/12 23:27:25 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "calloc/12_zero_nmemb.output"

int	calloc_12_zero_nmemb(void)
{
	t_test_fds		data;
	void			*ptr;

	data = child_init(OUTPUT_PATH);
	child_redirect(&data, 2);
	ptr = calloc(0, 42);
	if (!ptr)
		return (child_cleanup(&data), -1);
	free(ptr);
	if (child_cmp(&data, LIBUNIT_FLAGS_EXIST, 2) != 0)
		return (child_cleanup(&data), -1);
	child_cleanup(&data);
	return (0);
}
