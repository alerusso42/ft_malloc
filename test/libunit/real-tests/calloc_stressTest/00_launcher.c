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

int	calloc_stressTest_launcher(void)
{
	t_test_list	list;

	list = (t_test_list){0};
	load_test(&list, "seed1", calloc_stressTest_01_seed1);
	load_test(&list, "seed2", calloc_stressTest_02_seed2);
	load_test(&list, "seed3", calloc_stressTest_03_seed3);
	load_test(&list, "seed4", calloc_stressTest_04_seed4);
	load_test(&list, "seed5", calloc_stressTest_05_seed5);
	load_test(&list, "seed6", calloc_stressTest_06_seed6);
	load_test(&list, "seed7", calloc_stressTest_07_seed7);
	load_test(&list, "seed8", calloc_stressTest_08_seed8);
	load_test(&list, "seed9", calloc_stressTest_09_seed9);
	load_test(&list, "seed42", calloc_stressTest_10_seed42);
	return (launch_tests(&list, "CALLOC_STRESSTEST"));
}
