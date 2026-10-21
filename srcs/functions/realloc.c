/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 00:21:25 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/21 22:50:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

static inline void	*expand_mem(void *ptr, size_t size, size_t prev_size);

/// @brief expand ptr memory. 
///			If size <= ptr.size, realloc does nothing.
///			If there is available space near the ptr, ptr metadata are updated.
///			Else, a new malloc call is performed, memcpy is called.
/// @param ptr ptr to the start of the memory to realloc
/// @param size bytes needed for memory chunk
/// @return aligned ptr of heap memory, NULL if an error occurred
void 	*realloc(void *ptr, size_t size)
{
	t_alloc		*data;
	t_area		*area;

	if (!ptr)
		return (malloc(size));
	if (size == 0)
		size = ALIGN;
	thread_safe(MALL_THREAD_LOCK);
	data = malloc_global_data();
	DEBUG("Realloc, $Ysize request$Z: %d, $Yptr$Z: %p: ", size, ptr);
	switch (identify_area(data, ptr))
	{
		case (MEM_ALLOC) :
			area = ptr - sizeof(t_area);
			if (area->next - sizeof(t_area) >= size)
				return (DEBUG("ok\n"), thread_safe(MALL_THREAD_UNLOCK), ptr);
			return (expand_mem(ptr, size, area->next - sizeof(t_area)));
		case (MEM_FREED) :
			WARNING("$RRealloc: $Z%p $Ralready freed$Z\n");
			return (thread_safe(MALL_THREAD_UNLOCK), malloc(size));
		case (MEM_INVALID) :
			WARNING("$RRealloc: $Zinvalid ptr\n");
			return (expand_mem(ptr, size, 0));
		case (MEM_NO_HEAP) :
			WARNING("$RRealloc: $Z%p$R is not a heap ptr$Z\n");
			break ;
	}
	DEBUG("ok\n");
	return (thread_safe(MALL_THREAD_UNLOCK), NULL);
}

/// @brief called when memory is not enough. 
///			A malloc and memcpy call is performed.
/// @param ptr ptr to the start of the old memory
/// @param size bytes of the old memory
/// @return aligned ptr of heap memory, NULL if an error occurred
static inline void	*expand_mem(void *ptr, size_t size, size_t prev_size)
{
	void		*new_ptr;

	DEBUG("$GRealloc expand mem.$Z");
	thread_safe(MALL_THREAD_UNLOCK);
	new_ptr = malloc(size);
	if (!new_ptr)
		return (free(ptr), fatal_malloc("Realloc failure"));
	thread_safe(MALL_THREAD_LOCK);
	ft_memcpy(new_ptr, ptr, prev_size);
	thread_safe(MALL_THREAD_UNLOCK);
	return (free(ptr), new_ptr);
}
