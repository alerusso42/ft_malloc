/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:22:55 by alerusso          #+#    #+#             */
/*   Updated: 2025/12/29 17:22:55 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

void	test(void);

int	main(int ac, char **av)
{
	(void)ac, (void)av;

	// ft_printf("stack starts with: %p\n", &size);
	// ft_printf("pagesize: %d\n", sysconf(_SC_PAGE_SIZE));
	// ft_printf("max align: %d\n", ALIGN);
	test();
	// ft_printf("Program end!\n");
	// ft_printf("Internal Leak check: ");
	if (malloc_global_data()->bytes_alloc == malloc_global_data()->bytes_freed)
		ft_printf("$GSuccess!$z\n");
	else
	{
		ft_printf("$RLeak! $z%d allocated, %d freed\n", malloc_global_data()->bytes_alloc, malloc_global_data()->bytes_freed);
		ft_printf("Total leak: %d\n", malloc_global_data()->bytes_alloc - malloc_global_data()->bytes_freed);
	}
	del_filedata();
	return (0);
}

void	print_3d(char ***);

void	test(void)
{
	char	***data;

	daft_init(TEST_DATA_DIR, "SETTINGS.md");
    daft_swap(POKEDEX);
	data = daft_get("CALYREX");
	if (!data)
		return (daft_quit());
	print_3d(data);
	daft_quit();
	daft_init(TEST_DATA_DIR, "SETTINGS.md");
	daft_swap(POKEDEX);
	while (daft_iter((void **)&data))
		print_3d(data);
	daft_quit();
}

void	print_3d(char ***s)
{
	return ;
	if (s)
	{
		for (int i = 0; s[i]; i++)
			for (int j = 0; s[i][j]; j++)
				ft_printf("%s\n", s[i][j]);
	}
}
