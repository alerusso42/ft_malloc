#include "../tests.h"
#define OUTPUT_PATH "malloc/$counter$test.output"

int	malloc_$counter$test(void)
{
	t_test_fds		data;
	data = child_init(OUTPUT_PATH);
	child_redirect(&data, 2);
	if (malloc_test(42, 0) != 0)
		return (child_cleanup(&data), -1);
	if (child_cmp(&data, LIBUNIT_FLAGS_EXIST, 2) != 0)
		return (child_cleanup(&data), -1);
	child_cleanup(&data);
	return (0);
}
