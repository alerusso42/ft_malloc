/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 22:40:01 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:49:33 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "calloc/01_basic.output"

int	calloc_01_basic(void)
{
	void			*ptr;

	ptr = calloc(1, 1);
	if (!ptr)
		return (-1);
	free(ptr);
	return (0);
}
