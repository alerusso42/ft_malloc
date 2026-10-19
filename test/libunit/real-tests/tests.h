/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 23:37:58 by alerusso            #+#    #+#           */
/*   Updated: 2026/10/12 23:37:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "../framework/libunit.h"

//SECTION - malloc_stressTest
int	malloc_stressTest_launcher(void);
int	malloc_stressTest_01_seed1(void);
int	malloc_stressTest_02_seed2(void);
int	malloc_stressTest_03_seed3(void);
int	malloc_stressTest_04_seed4(void);
int	malloc_stressTest_05_seed5(void);
int	malloc_stressTest_06_seed6(void);
int	malloc_stressTest_07_seed7(void);
int	malloc_stressTest_08_seed8(void);
int	malloc_stressTest_09_seed9(void);
int	malloc_stressTest_10_seed42(void);
//SECTION - calloc_stressTest
int	calloc_stressTest_launcher(void);
int	calloc_stressTest_01_seed1(void);
int	calloc_stressTest_02_seed2(void);
int	calloc_stressTest_03_seed3(void);
int	calloc_stressTest_04_seed4(void);
int	calloc_stressTest_05_seed5(void);
int	calloc_stressTest_06_seed6(void);
int	calloc_stressTest_07_seed7(void);
int	calloc_stressTest_08_seed8(void);
int	calloc_stressTest_09_seed9(void);
int	calloc_stressTest_10_seed42(void);
//SECTION - calloc
int	calloc_launcher(void);
int	calloc_01_basic(void);
int	calloc_02_size0(void);
int	calloc_03_size1(void);
int	calloc_04_size10(void);
int	calloc_05_size100(void);
int	calloc_06_size10000(void);
int	calloc_07_size100000(void);
int	calloc_08_size10000000(void);
int	calloc_09_alloc_and_free(void);
int	calloc_10_memory_exaustion(void);
int	calloc_11_overflow_nmemb(void);
int	calloc_12_zero_nmemb(void);
//SECTION - malloc
int	malloc_launcher(void);
int	malloc_01_basic(void);
int	malloc_02_size0(void);
int	malloc_03_size1(void);
int	malloc_04_size10(void);
int	malloc_05_size100(void);
int	malloc_06_size10000(void);
int	malloc_07_size100000(void);
int	malloc_08_size10000000(void);
int	malloc_09_alloc_and_free(void);
int	malloc_10_memory_exaustion(void);
//SECTION - realloc_stressTest
int	realloc_stressTest_launcher(void);
int	realloc_stressTest_01_seed1(void);
int	realloc_stressTest_02_seed2(void);
int	realloc_stressTest_03_seed3(void);
int	realloc_stressTest_04_seed4(void);
int	realloc_stressTest_05_seed5(void);
int	realloc_stressTest_06_seed6(void);
int	realloc_stressTest_07_seed7(void);
int	realloc_stressTest_08_seed8(void);
int	realloc_stressTest_09_seed9(void);
int	realloc_stressTest_10_seed42(void);
//SECTION - realloc
int	realloc_launcher(void);
int	realloc_01_basic(void);
int	realloc_02_size0(void);
int	realloc_03_size1(void);
int	realloc_04_size10(void);
int	realloc_05_size100(void);
int	realloc_06_size10000(void);
int	realloc_07_size100000(void);
int	realloc_08_size10000000(void);
int	realloc_09_alloc_and_free(void);
int	realloc_10_memory_exaustion(void);
int	realloc_11_null(void);
int	realloc_12_sizeZero(void);

#endif
