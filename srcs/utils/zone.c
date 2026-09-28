/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:31:42 by alerusso          #+#    #+#             */
/*   Updated: 2026/09/28 16:31:04 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

//used by malloc to give memory area to user
void	*zone_area_alloc(t_list *zones, uint32_t size)
{
	t_memzone	*zone;
	t_area		*area;

	size += sizeof(t_area);
	while (zones)
	{
		zone = (t_memzone *)zones->content;
		if (zone->longest_chunk >= size)
		{
			DEBUG("zone okkk.. %d\n", zone->first_free_area);
			area = zone->first_free_area;
			area = area_find_alloc_block(area, size);
			DEBUG("zone found!!.. %d\n", area->next);
			area_alloc(zone, area, size);
			DEBUG("zone alloc..");
			return (((void *)area) + sizeof(t_area));
		}
		zones = zones->next;
	}
	return (NULL);
}

//used by free when user gives a wrong memory ptr
t_area	*zone_area_freed(t_list *zones, void *ptr)
{
	t_memzone	*zone;
	t_area		*area;

	ptr += sizeof(t_area);
	while (zones)
	{
		zone = (t_memzone *)zones->content;
		if (ptr >= (void *)zone && ptr < (void *)zone + zone->size)
		{
			area = ((void *)zone) + sizeof(t_memzone);
			area = area_find_freed_block(area, ptr);
			if (!area)
				return (NULL);
			area_freed(area);
			return (area);
		}
		zones = zones->next;
	}
	return (NULL);
}

//used when a new mmap zone is needed
t_list	*zone_add(t_alloc *data, t_list **zones, uint32_t size)
{
	t_memzone	*new_zone;
	void		*ptr;

	DEBUG("zone add..\n");
	ptr = mmap_syscall(data, size + sizeof(t_area));
	if (!ptr)
		return (error_malloc("zone_add: can't allocate memory\n"));
	DEBUG("zone add ok alloc..\n");
	new_zone = ptr;
	*new_zone = (t_memzone){0};
	new_zone->empty = true;
	new_zone->longest_chunk = size - sizeof(t_memzone);
	new_zone->first_free_area = ((void *)new_zone) + sizeof(t_memzone);
	*new_zone->first_free_area = (t_area){0};
	new_zone->first_free_area->next = new_zone->longest_chunk;
	new_zone->first_free_area->info = MEM_FREED;
	*((t_area *)(((void *)new_zone) + size)) = (t_area){0};
	new_zone->blocks_freed = 1;
	new_zone->size = round_page(size, data->pagesize);
	new_zone->node.content = new_zone;
	lst_front(zones, &new_zone->node);
	data->bytes_alloc += size + sizeof(t_memzone);
	DEBUG("zone add ok.. returning %p\n", new_zone->node);
	return (&new_zone->node);
}

//finds longest freed area in a zone
//used when:
/*
1)	there are multiple freed areas in a zone
2)	the current longest area is being allocated
*/
t_bytelist	zone_find_longest_chunk(t_memzone *zone)
{
	t_bytelist	record;
	t_area		*area;

	record = 0;
	area = zone->first_free_area;
	if (!area)
		return (0);
	while (area->next)
	{
		if (area->info & MEM_FREED && area->next > record)
			record = area->next;
		area = ((void *)area) + area->next;
	}
	return (record);
}

//used when the current first freed area is being allocated
t_area	*zone_find_first_free_area(t_memzone *zone)
{
	t_area	*area;

	//area = ((void *)zone + sizeof(t_memzone));
	area = zone->first_free_area;
	while (area)
	{
		if (area->info & MEM_FREED)
			return (area);
		area = bytelst_next(area);
	}
	zone->longest_chunk = 0;
	return (NULL);
}
