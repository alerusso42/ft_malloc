/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:37:58 by alerusso            #+#    #+#           */
/*   Updated: 2026/10/12 23:37:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int	malloc_launcher(void)
{
	t_test_list	list;

	list = (t_test_list){0};
	load_test(&list, "basic", malloc_01_basic);
	load_test(&list, "size0", malloc_02_size0);
	load_test(&list, "size1", malloc_03_size1);
	load_test(&list, "size10", malloc_04_size10);
	load_test(&list, "size100", malloc_05_size100);
	load_test(&list, "size10000", malloc_06_size10000);
	load_test(&list, "size100000", malloc_07_size100000);
	load_test(&list, "size10000000", malloc_08_size10000000);
	load_test(&list, "alloc_and_free", malloc_09_alloc_and_free);
	load_test(&list, "memory_exaustion", malloc_10_memory_exaustion);
	return (launch_tests(&list, "MALLOC"));
}
