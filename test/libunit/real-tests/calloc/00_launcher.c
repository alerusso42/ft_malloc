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

int	calloc_launcher(void)
{
	t_test_list	list;

	list = (t_test_list){0};
	load_test(&list, "basic", calloc_01_basic);
	load_test(&list, "size0", calloc_02_size0);
	load_test(&list, "size1", calloc_03_size1);
	load_test(&list, "size10", calloc_04_size10);
	load_test(&list, "size100", calloc_05_size100);
	load_test(&list, "size10000", calloc_06_size10000);
	load_test(&list, "size100000", calloc_07_size100000);
	load_test(&list, "size10000000", calloc_08_size10000000);
	load_test(&list, "alloc_and_free", calloc_09_alloc_and_free);
	load_test(&list, "memory_exaustion", calloc_10_memory_exaustion);
	load_test(&list, "overflow_nmemb", calloc_11_overflow_nmemb);
	load_test(&list, "zero_nmemb", calloc_12_zero_nmemb);
	return (launch_tests(&list, "CALLOC"));
}
