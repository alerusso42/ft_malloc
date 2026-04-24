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

# include "../../Libft/libft.h"
# include <malloc.h>

void	test();
void	print_3d(char ***s);

int	main(int ac, char **av)
{
	(void)ac, (void)av;
	struct mallinfo2	mData;

	// ft_printf("stack starts with: %p\n", &size);
	// ft_printf("pagesize: %d\n", sysconf(_SC_PAGE_SIZE));
	test();
	mData = mallinfo2();
	if (mData.uordblks == mData.fordblks)
		ft_printf("$GSuccess!$z\n");
	else
	{
		ft_printf("$RLeak! $z%d allocated, %d freed\n", mData.uordblks, mData.fordblks);
		ft_printf("Total leak: %d\n", mData.uordblks - mData.fordblks);
	}
	del_filedata();
	// FILE	*f = fopen("/dev/tty", "w");
	// malloc_info(0, f);
	// fclose(f);
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
