#include "../tests.h"
#define OUTPUT_PATH "realloc_stressTest/$counter$test.output"

int	realloc_stressTest_$counter$test(void)
{
	t_test_fds		data;
	data = child_init(OUTPUT_PATH);
	child_redirect(&data, 2);
	if (realloc_rng_test(42000, 0, 1, 3) != 0)
		return (child_cleanup(&data), -1);
	if (child_cmp(&data, LIBUNIT_FLAGS_EXIST, 2) != 0)
		return (child_cleanup(&data), -1);
	child_cleanup(&data);
	return (0);
}
