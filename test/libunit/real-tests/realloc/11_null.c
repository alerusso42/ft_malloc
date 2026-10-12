/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:39 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/12 23:36:12 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "realloc/11_null.output"

int	realloc_11_null(void)
{
	t_test_fds		data;
	void			*ptr;

	data = child_init(OUTPUT_PATH);
	child_redirect(&data, 2);
	ptr = realloc(NULL, 0);
	if (!ptr)
		return (child_cleanup(&data), -1);
	free(ptr);
	if (child_cmp(&data, LIBUNIT_FLAGS_EXIST, 2) != 0)
		return (child_cleanup(&data), -1);
	child_cleanup(&data);
	return (0);
}
