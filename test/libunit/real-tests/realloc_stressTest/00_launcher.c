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

int	realloc_stressTest_launcher(void)
{
	t_test_list	list;

	list = (t_test_list){0};
	load_test(&list, "seed1", realloc_stressTest_01_seed1);
	load_test(&list, "seed2", realloc_stressTest_02_seed2);
	load_test(&list, "seed3", realloc_stressTest_03_seed3);
	load_test(&list, "seed4", realloc_stressTest_04_seed4);
	load_test(&list, "seed5", realloc_stressTest_05_seed5);
	load_test(&list, "seed6", realloc_stressTest_06_seed6);
	load_test(&list, "seed7", realloc_stressTest_07_seed7);
	load_test(&list, "seed8", realloc_stressTest_08_seed8);
	load_test(&list, "seed9", realloc_stressTest_09_seed9);
	load_test(&list, "seed42", realloc_stressTest_10_seed42);
	return (launch_tests(&list, "REALLOC_STRESSTEST"));
}
