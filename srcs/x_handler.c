/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:48:49 by akdovlet          #+#    #+#             */
/*   Updated: 2023/12/27 19:00:47 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_put_n_count_hex(size_t n, int count, int bin)
{
	int		tmp;
	char	*base;
	char	*cbase;

	tmp = count;
	base = "0123456789abcdef";
	cbase = "0123456789ABCDEF";
	if (n >= 16)
		count = ft_put_n_count_hex(n / 16, count + 1, bin);
	if (bin)
		ft_put_n_count_char(base[n % 16]);
	else
		ft_put_n_count_char(cbase[n % 16]);
	return (count);
}

int	zero_x(unsigned int n, t_flag flags, int bin)
{
	int	count;

	count = 0;
	if (flags.hash && n > 0 && bin)
		count += ft_putstrlen("0x", 2);
	else if (flags.hash && n > 0 && !bin)
		count += ft_putstrlen("0X", 2);
	return (count);
}

void	x_rules(t_flag *flags, int len, unsigned int n)
{
	if (flags->precision >= flags->width)
		flags->total_width = 0;
	if (len > flags->total_width)
		flags->total_width = 0;
	if (flags->precision > len && !flags->dash)
		flags->total_width -= flags->precision;
	if (flags->precision < len && !flags->dash)
		flags->total_width -= len;
	if (flags->hash && n > 0)
		flags->total_width -= 2;
}

int	x_width(unsigned int n, t_flag flags, int bin)
{
	int	count;
	int	len;

	count = 0;
	len = ft_nbcount(n, 16);
	printf("len is: %d\n", len);
	x_rules(&flags, len, n);
	if (flags.dash)
	{
		count += zero_x(n, flags, bin);
		count += ft_put_n_count_hex(n, 1, bin);
	}
	if (flags.zero && n < 0 && !flags.dash && flags.width > ft_nbcount(n, 16))
	{
		count += ft_put_n_count_char('-');
		n *= -1;
	}
	count += width_manager(flags.width, ft_nbcount(n, 16), flags.zero);
	if (!flags.dash)
	{
		count += zero_x(n, flags, bin);
		count += ft_put_n_count_hex(n, 1, bin);
	}
	return (count);
}

int	x_dot(long n, t_flag flags, int bin)
{
	int	count;
	int nbcount;

	count = 0;
	if (flags.precision == 0 && n == 0)
		return (count);
	nbcount = ft_nbcount(n, 16);
	count += width_manager(flags.precision, nbcount, flags.zero);
	count += ft_put_n_count_hex(n, 1, bin);
	return (count);
}

int	x_handler(unsigned int hex, t_flag flags, int bin)
{
	int	count;

	count = 0;
	if ((flags.width || flags.dash || flags.plus
			|| flags.zero) && !flags.dot)
		return (x_width(hex, flags, bin));
	if (flags.dot)
		return (x_dot(hex, flags, bin));
	else
		return (ft_put_n_count_hex(hex, 1, bin));
}
