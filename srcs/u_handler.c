/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:25:54 by akdovlet          #+#    #+#             */
/*   Updated: 2023/12/19 15:28:46 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_put_n_count_u(unsigned int n, int count)
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

int	u_handler(va_list *arg)
{
	unsigned int	nb;

	nb = va_arg(*arg, unsigned int);
	return (ft_put_n_count_u(nb, 1));
}
