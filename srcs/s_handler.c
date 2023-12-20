/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:43:29 by akdovlet          #+#    #+#             */
/*   Updated: 2023/12/20 20:16:27 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstrlen(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	s_handler(char *str, t_flag flags)
{
	int	count;
	int	len;

	count = 0;
	if (flags.dot && flags.precision == 0)
		return (0);
	if (!str)
		return (ft_putstrlen("(null)", 6));
	len = ft_strlen(str);
	if (flags.dot && flags.precision > 0)
		len = flags.precision;
	if (flags.dash)
		count += ft_putstrlen(str, len);
	count += width_manager(flags.width, len, 0);
	if (!flags.dash)
		count += ft_putstrlen(str, len);
	return (count);
}

// int s_width()
