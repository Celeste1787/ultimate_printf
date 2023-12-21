/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:58:12 by akdovlet          #+#    #+#             */
/*   Updated: 2023/12/21 18:18:38 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
int	negative_int_len(long long n, int base)
{
	return (positive_int_len(-n, base));
	//return (positive_int_len(n * -1, base) + 1);
}

int positive_int_len(unsigned long long n, int base)
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

int	ft_nbcount(long long n, int base)
{
	if (n < 0)
		return (negative_int_len(n, base));
	else
		return (positive_int_len(n, base));
}

char	*ft_itoa(int n)
{
	int		size;
	char	*nb;
	long	ln;

	ln = (long) n;
	size = ft_nbcount(ln, 10);
	size += ln < 0;
	nb = ft_calloc(sizeof(char), size + 1);
	if (!nb)
		return (NULL);
	if (ln < 0)
	{
		ln *= -1;
		nb[0] = '-';
	}
	while (size--)
	{
		if (nb[size] == '-')
			break ;
		nb[size] = ln % 10 + 48;
		ln /= 10;
	}
	return (nb);
}

int	ft_atoi(const char *nptr, int *index)
{
	size_t	i;
	int		flip;
	long	nb;

	i = 0;
	flip = 1;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			flip *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nb = nb * 10 + nptr[i] - 48;
		i++;
	}
*index += i;
	return (nb * flip);
}
