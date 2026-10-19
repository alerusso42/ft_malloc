/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:39 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:47:09 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "realloc/11_null.output"

int	realloc_11_null(void)
{
	void			*ptr;

	ptr = realloc(NULL, 0);
	if (!ptr)
		return (-1);
	free(ptr);
	return (0);
}
