/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overload.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 23:22:49 by alerusso          #+#    #+#             */
/*   Updated: 2026/09/29 11:28:52 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"
# include <malloc.h>

// equal to a realloc call
void 	*reallocarray(void *ptr, size_t nmemb, size_t size)
{
	size_t	total;

	if (nmemb && SIZE_MAX / nmemb < size)
	{
		WARNING("reallocarray: %u * %u overflows\n", nmemb, size);
		return (NULL);
	}
	if (!nmemb || !size)
		total = ALIGN;
	else
		total = nmemb * size;
	return (realloc(ptr, total));
}

// align size using alignment. Then it's equal to a malloc call
void	*memalign(size_t alignment, size_t size)
{
	ft_printf("memalign\n");
	if (alignment < sizeof(void *) || (alignment & (alignment - 1)) != 0)
	{
		WARNING("memalign: alignment %u must be pow of 2, >= sizeof(ptr)\n", \
		alignment);
		return (NULL);
	}
	size = (size + alignment - 1) & (alignment - 1);
	return (malloc(size));
}

// equal to a malloc call
void	*valloc(size_t size)
{
	ft_printf("valloc\n");
	return (malloc(size));
}

// equal to a malloc call
void	*pvalloc(size_t size)
{
	ft_printf("pvalloc\n");
	return (malloc(size));
}

// equal to a malloc call
void	*xmalloc(size_t size)
{
	ft_printf("xmalloc\n");
	return (malloc(size));
}
