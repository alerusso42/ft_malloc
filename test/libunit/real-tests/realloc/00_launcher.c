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

int	realloc_launcher(void)
{
	t_test_list	list;

	list = (t_test_list){0};
	load_test(&list, "basic", realloc_01_basic);
	load_test(&list, "size0", realloc_02_size0);
	load_test(&list, "size1", realloc_03_size1);
	load_test(&list, "size10", realloc_04_size10);
	load_test(&list, "size100", realloc_05_size100);
	load_test(&list, "size10000", realloc_06_size10000);
	load_test(&list, "size100000", realloc_07_size100000);
	load_test(&list, "size10000000", realloc_08_size10000000);
	load_test(&list, "alloc_and_free", realloc_09_alloc_and_free);
	load_test(&list, "memory_exaustion", realloc_10_memory_exaustion);
	load_test(&list, "null", realloc_11_null);
	load_test(&list, "sizeZero", realloc_12_sizeZero);
	return (launch_tests(&list, "REALLOC"));
}
