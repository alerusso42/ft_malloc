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

#include "tests.h"

int	main(void)
{
	int	output;

	output = 0;
	output -= malloc_stressTest_launcher();
	output -= calloc_stressTest_launcher();
	output -= calloc_launcher();
	output -= malloc_launcher();
	output -= realloc_stressTest_launcher();
	output -= realloc_launcher();
	if (output == 0)
		write(1, "\033[1;32mTEST OK.\n\033[0m", 18);
	else
		write(1, "\033[1;31mTEST KO.\n\033[0m", 18);
	return (-(output != 0));
}
