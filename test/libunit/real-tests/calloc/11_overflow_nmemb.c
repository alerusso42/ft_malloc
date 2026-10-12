/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_overflow_nmemb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:06:38 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/13 00:49:42 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"
#define OUTPUT_PATH "calloc/11_overflow_nmemb.output"

int	calloc_11_overflow_nmemb(void)
{
	void			*ptr;

	ptr = calloc(INT_MAX, 42);
	if (ptr)
		return (free(ptr), -1);
	return (0);
}
