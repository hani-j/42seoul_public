#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf(" %u %u %u \n", -1, -9, -10);
	ft_printf(" %u %u %u ",  -1, -9, -10);
}
