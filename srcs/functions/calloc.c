/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 00:21:17 by alerusso          #+#    #+#             */
/*   Updated: 2026/09/29 11:26:22 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

/// @brief returns ptr with malloc. Size is nmemb * size
/// @param nmemb number of elements to allocate
/// @param size size in bytes of each element to allocate
/// @return aligned ptr of heap memory, NULL if an error occurred
void 	*calloc(size_t nmemb, size_t size)
{
	size_t		total;
	void		*ptr;
	uintptr_t	area;

	DEBUG("CALLOC\n$Ysize request$Z: %d\n$Ynmemb$Z: %p\n", size, nmemb);
	if (nmemb && SIZE_MAX / nmemb < size)
	{
		WARNING("calloc: %u * %u overflows\n", nmemb, size);
		return (NULL);
	}
	if (!nmemb || !size)
		total = ALIGN;
	else
		total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total);
	area = ((uintptr_t)ptr) - sizeof(t_area);
	((t_area *)area)->info |= MEM_SET;
	DEBUG("$GCalloc success.$Z");
	return (ptr);
}
