/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:56:11 by akdovlet          #+#    #+#             */
/*   Updated: 2023/12/26 22:27:41 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	width_m(int width, int count, int zero)
{
	int	tmp;

	tmp = 0;
	while (count < width)
	{
		if (zero)
			tmp += ft_put_n_count_char('0');
		else
			tmp += ft_put_n_count_char(' ');
		count++;
	}
	return (tmp);
}

int	ft_put_n_count_nbr(long n, int count)
{
	int	tmp;

	tmp = count;
	if (n < 0)
	{
		n *= -1;
		ft_put_n_count_char('-');
		tmp++;
	}
	if (n > 9)
		tmp = ft_put_n_count_nbr(n / 10, tmp + 1);
	ft_put_n_count_char((n % 10) + 48);
	return (tmp);
}

int	sign_manager(long *n, t_flag flags)
{
	int	count;

	count = 0;
	if (flags.zero && *n < 0)
	{
		count += ft_put_n_count_char('-');
		*n *= -1;
	}
	else if (flags.space && *n >= 0)
		count += ft_put_n_count_char(' ');
	else if (flags.plus && *n >= 0)
		count += ft_put_n_count_char('+');
	else if (*n < 0)
	{
		count += ft_put_n_count_char('-');
		*n *= -1;
	}
	return (count);
}
int	case_zero(t_flag flags)
{
	int	count;

	count = 0;
	if (flags.width)
		count += width_m(flags.width, count, flags.precision);
	return (count);
}
int	d_width_m(long n, t_flag flags)
{
	int count;
	int len;

	count = 0;
	len = ft_nbcount(n, 10);
	// printf("flags.total_width is: %d\n", flags.total_width);
	if (len > flags.total_width)
		flags.total_width = 0;
	if (flags.precision > len && !flags.dash)
		flags.total_width -= flags.precision;
	if (flags.precision < len && !flags.dash)
		flags.total_width -= len;
	if ((n < 0 || (n >= 0 && flags.plus)) && !flags.dash && !flags.zero)
		flags.total_width--;
	// printf("total width is: %d\n", flags.total_width);
	if (flags.dash)
	{
		count += sign_manager(&n, flags);
		if (flags.precision > len)
			count += precision_manager(flags.precision, len);
		count += ft_put_n_count_nbr(n, 1);
	}
	else if (flags.zero && n < 0)
		count += sign_manager(&n, flags);
	// printf("total width is: %d\n", flags.total_width);
	// printf("count is: %d\n", count);
	count += width_m(flags.total_width, count, flags.zero);
	if (!flags.dash)
	{
		count += sign_manager(&n, flags);
		if (flags.precision > len)
			count += precision_manager(flags.precision, len);
		count += ft_put_n_count_nbr(n, 1);
	}
	return (count);
}
int	precision_manager(int precision, int len)
{
	int	count;

	count = 0;
	while (precision > len)
	{
		count += ft_put_n_count_char('0');
		precision--;
	}
	return (count);
}

int	d_width(long n, t_flag flags)
{
	int	count;

	count = 0;
	if (n < 0 || (flags.plus && n >= 0 && !flags.zero))
		flags.width--;
	if (flags.precision > ft_nbcount(n, 10))
		count += precision_manager(flags.precision, ft_nbcount(n, 10));
	if (flags.dash)
	{
		if (flags.plus && n >= 0)
			count += ft_put_n_count_char('+');
		count += ft_put_n_count_nbr(n, 1);
	}
	if (flags.plus && n >= 0 && flags.zero && !flags.dash)
		count += ft_put_n_count_char('+');
	if (flags.zero && n < 0 && !flags.dash && flags.width > ft_nbcount(n, 10))
	{
		count += ft_put_n_count_char('-');
		n *= -1;
	}
	count += width_manager(flags.width, ft_nbcount(n, 10), flags.zero);
	if (!flags.dash)
	{
		if (flags.plus && n >= 0 && flags.zero)
			count += ft_put_n_count_char('+');
		count += ft_put_n_count_nbr(n, 1);
	}
	return (count);
}

int	d_dot(long n, t_flag flags)
{
	int	count;

	count = 0;
	if (flags.precision == 0 && n == 0)
		return (count);
	if (flags.plus && n >= 0)
		count += ft_put_n_count_char('+');
	if (n < 0)
	{
		count += ft_put_n_count_char('-');
		n *= -1;
	}
	count += width_manager(flags.precision, ft_nbcount(n, 10), flags.zero);
	count += ft_put_n_count_nbr(n, 1);
	return (count);
}

int	d_handler(int n, t_flag flags)
{
	int	count;
	long	x;

	x = n;
	count = 0;
	if (flags.dot && !flags.precision && n == 0)
		return (case_zero(flags));
	if (flags.width || flags.precision || flags.plus || flags.space)
		count += d_width_m(x, flags);
	else
		count = ft_put_n_count_nbr(x, 1);
	return (count);
}
