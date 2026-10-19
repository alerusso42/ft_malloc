#include "../tests.h"
#define OUTPUT_PATH "calloc/$counter$test.output"

int	calloc_$counter$test(void)
{
	if (calloc_test(42, 0) != 0)
		return (-1);
	return (0);
}
