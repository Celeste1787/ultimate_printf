#include <stdio.h>
#include <unistd.h>
#include "include/ft_printf.h"
#include <limits.h>

int main()
{
	int	x;
	// int x = ft_printf(" |%-3c|\n", '0' + 256);
	// ft_printf("return value is: %d\n", x);
	// ft_printf("========================================\n");
	// x = printf(" |%-3c|\n", '0' + 256);
	// ft_printf("return value is: %d\n", x);
	// ft_printf("========================================\n");
	// ft_printf("========================================\n");
	// ft_printf("========================================\n");

	char *str = "0test";
	char *str2 = "test";
	x = ft_printf("%.20s\n", "Hello World!");
	// printf("return value is: %d\n", x);
	// printf("num len is: %d\n", ft_nbcount(ULONG_MAX, 16));
	x = printf("%.20s\n", "Hello World!");
	//printf("return value is: %d\n", x);
	// ft_printf("return value is: %d\n", x);
	// ft_printf("return value is: %d\n", x);
	// ft_printf("========================================\n");
	// x = printf(" |%10.15d|\n", 14);
	// ft_printf("return value is: %d\n", x);
	// ft_printf("return value is: %d\n", x);

	//  printf("c is			|%-10c|\n", 'A');
	// printf("10 is			|%10c|\n", 'A');
	// printf("-10 is			|%-10c|\n", 'A');


	// printf("-10 is  |%-10d|\n", 150);
	// printf("+10 is  |%+10d|\n", 150);
	// printf("10.5 is |%-10.3d|\n", 150);
	// printf("% 10d\n", 150);
	// printf("% 10d\n", 150);
	// printf("%-10d\n", 150);
	// printf("%+10d\n", 150);
}
