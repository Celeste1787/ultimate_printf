/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:48:49 by akdovlet          #+#    #+#             */
/*   Updated: 2023/12/19 15:28:50 by akdovlet         ###   ########.fr       */
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

int	x_handler(va_list *arg, int bin)
{
	unsigned int	hex;

	hex = va_arg(*arg, unsigned int);
	return (ft_put_n_count_hex(hex, 1, bin));
}
