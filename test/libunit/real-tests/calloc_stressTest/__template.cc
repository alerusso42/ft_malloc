#include "../tests.h"
#define OUTPUT_PATH "calloc_stressTest/$counter$test.output"

int	calloc_stressTest_$counter$test(void)
{
	t_test_fds		data;

	if (calloc_rng_test(42000, 0, 1, 3) != 0)
		return (-1);
	return (0);
}
