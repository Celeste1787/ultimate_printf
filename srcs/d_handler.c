/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:56:11 by akdovlet          #+#    #+#             */
/*   Updated: 2023/12/20 19:06:53 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_put_n_count_nbr(long n, int count)
{
	int		tmp;

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
int	d_width(long n, t_flag flags)
{
	int	count;

	count = 0;
	if (flags.plus && n >= 0 && !flags.zero)
		flags.width--;
	if (flags.dash)
	{
		if (flags.plus && n >= 0)
			count += ft_put_n_count_char('+');
		count += ft_put_n_count_nbr(n, 1);
	}
	if (flags.zero && n < 0 && !flags.dash && flags.width > ft_nbcount(n, 10))
	{
		count += ft_put_n_count_char('-');
		n *= -1;
	}
	count += width_manager(flags.width, ft_nbcount(n, 10), flags.zero);
	if (!flags.dash)
	{
		if (flags.plus && n >= 0 && !flags.zero)
			count += ft_put_n_count_char('+');
		count += ft_put_n_count_nbr(n, 1);
	}
	return (count);
}

int	d_dot(long n, t_flag flags)
{
	int	count;

	count = 0;
	if (flags.plus && n >= 0)
		count += ft_put_n_count_char('+');
	count += width_manager(flags.precision, ft_nbcount(n, 10), 1);
	count += ft_put_n_count_nbr(n, 1);
	return (count);
}

int	d_handler(int n, t_flag flags)
{
	int	count;
	long	x;

	x = n;
	count = 0;
	if ((flags.width || flags.dash || flags.plus
		|| flags.zero) && !flags.dot)
		return (d_width(x, flags));
	else if (flags.dot)
	{
		return (d_dot(x, flags));
	}
	else
		return (ft_put_n_count_nbr(x, 1));
}


