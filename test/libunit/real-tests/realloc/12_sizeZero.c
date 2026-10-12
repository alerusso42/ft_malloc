/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_sizeZero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:37:58 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:47:33 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "realloc/12_sizeZero.output"

int	realloc_12_sizeZero(void)
{
	void			*ptr;

	ptr = realloc(NULL, 0);
	if (!ptr)
		return (-1);
	return (0);
}
