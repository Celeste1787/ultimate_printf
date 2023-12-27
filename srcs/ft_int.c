/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:58:12 by akdovlet          #+#    #+#             */
/*   Updated: 2023/12/27 23:23:18 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

// Bunch of functions for int management.
int	negative_int_len(long long n, int base)
{
	return (positive_int_len(-n, base));
}

int	positive_int_len(unsigned long long n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

// this was made specifically to handle ULONG_MAX
// probably not necessary but might as well
int	ft_nbcount(long long n, int base)
{
	if (n < 0)
		return (negative_int_len(n, base));
	else
		return (positive_int_len(n, base));
}
