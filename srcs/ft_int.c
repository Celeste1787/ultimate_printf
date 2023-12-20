/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:58:12 by akdovlet          #+#    #+#             */
/*   Updated: 2023/12/20 19:46:06 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_nbcount(size_t n, int base)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		n *= -1;
		count++;
	}
	while (n)
	{
		count++;
		n /= base;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*nb;
	long	ln;

	ln = (long) n;
	size = ft_nbcount(ln, 10);
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
