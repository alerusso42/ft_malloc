/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:59:47 by alerusso          #+#    #+#             */
/*   Updated: 2026/10/20 12:33:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
int main(int argc, char *argv[])
{
    char    *destination;
    char    *source;
    size_t  n;
    
    if (argc < 4)
    {
        printf("INSERISCI: \nargv[1] = dest;\n");
        printf("argv[2] = source\n");
        printf("argv[3] = n bytes da muovere.\n");
        return (42);
    }
    source = argv[2];
    if (atoi(argv[3]) < 0)
    {
        printf("Allora, qui non siamo in villaggio ");
        printf("turistico, e tu non fai ridere.\n");
        return (42);
    }
    n = (size_t)atoi(argv[3]);
    destination = (char *)malloc(30 * sizeof(char));
    destination = ft_strcpy(destination, argv[1]);
    destination = (char *)ft_memcpy((void *)destination,
	 (const void *)source, n);
    printf("\n%s\n", destination);
    free(destination);
    return (0);
}*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*pointer;
	size_t	i;

	i = n;
	if ((!dest) && (!src))
		return (NULL);
	pointer = dest;
	while ((i--) && (dest))
	{
		*((char *)dest) = *((char *)src);
		++dest;
		++src;
	}
	return (pointer);
}
