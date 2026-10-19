/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_zero_nmemb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:38 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:49:45 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "calloc/12_zero_nmemb.output"

int	calloc_12_zero_nmemb(void)
{
	void			*ptr;

	ptr = calloc(0, 42);
	if (!ptr)
		return (-1);
	free(ptr);
	return (0);
}
