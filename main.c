#include <stdio.h>
#include <unistd.h>
#include "include/ft_printf.h"
#include <limits.h>

int main()
{

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
	// x = ft_printf("%-13p %-14p\n", ULONG_MAX, -ULONG_MAX);
	// printf("return value is: %d\n", x);
	// printf("num len is: %d\n", ft_nbcount(ULONG_MAX, 16));
	// x = printf("%-13p %-14p\n", ULONG_MAX, -ULONG_MAX);
	// ft_printf(" %-+4d\n", -14);
	// ft_printf(" %02d\n", -1);
	// ft_printf(" %-6d\n", -16);
	// ft_printf(" %-6d\n", -16);
	ft_printf("%04d\n", -14);
	printf("%04d\n", -14);
	ft_printf("%05d\n", -15);
	printf("%05d\n", -15);
	ft_printf("%06d\n", -16);
	printf("%06d\n", -16);
	// int c = printf(" %-13p %-14p\n", ULONG_MAX, -ULONG_MAX);
	// int x = ft_printf(" %-13p %-14p\n", ULONG_MAX, -ULONG_MAX);
	// printf("return value is: %d\n", c);
	// printf("return value is: %d\n", x);
	// printf("return value is: %d\n", x);
	printf("nbcount of ULONG_MAX is: %d\n", ft_nbcount(ULONG_MAX, 10));
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
