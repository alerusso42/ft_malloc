/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 00:21:17 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/21 22:46:01 by alerusso         ###   ########.fr       */
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

	thread_safe(MALL_THREAD_LOCK);
	DEBUG("Calloc, $Ysize request$Z: %d, $Ynmemb$Z: %p: ", size, nmemb);
	if (nmemb && SIZE_MAX / nmemb < size)
	{
		WARNING("calloc: %u * %u overflows\n", nmemb, size);
		return (thread_safe(MALL_THREAD_UNLOCK), NULL);
	}
	if (!nmemb || !size)
		total = ALIGN;
	else
		total = nmemb * size;
	thread_safe(MALL_THREAD_UNLOCK);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	thread_safe(MALL_THREAD_LOCK);
	ft_memset(ptr, 0, total);
	area = ((uintptr_t)ptr) - sizeof(t_area);
	((t_area *)area)->info |= MEM_SET;
	return (DEBUG("ok\n"), thread_safe(MALL_THREAD_UNLOCK), ptr);
}
