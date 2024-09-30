#include "ft_abs.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void)argc;
	int abs = ABS(atoi(argv[1]));
	printf("The absolute value of %s is %i.\n", argv[1], abs);
	return (0);
}
