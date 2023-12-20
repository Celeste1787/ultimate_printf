/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:49:03 by akdovlet          #+#    #+#             */
/*   Updated: 2023/12/20 20:09:36 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	p_handler(size_t n, t_flag flags)
{
	int	count;

	count = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	if (flags.dash)
	{
		count += ft_putstrlen("0x", 2);
		count += ft_put_n_count_hex(n, 1, 1);
	}
	count += width_manager(flags.width, ft_nbcount(n, 16) + 2, 0);
	if (!flags.dash)
	{
		count += ft_putstrlen("0x", 2);
		count += ft_put_n_count_hex(n, 1, 1);
	}
	return (count);
}

