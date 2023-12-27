/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:00:29 by akdovlet          #+#    #+#             */
/*   Updated: 2023/12/27 22:23:15 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	t_flag	flags;
	int		wrote;
	int		i;

	i = 0;
	wrote = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			flag_parsing(str, &flags, &i);
			flag_precision(str, &flags, &i);
			//  printf("flags are: %d %d %d %d %d %d %d %d\n", flags.dash, flags.plus, flags.hash, flags.space, flags.zero, flags.width, flags.precision, flags.total_width);
			wrote += ft_draft(str[i], &arg, flags);
		}
		else
			wrote += ft_put_n_count_char(str[i]);
		i++;
	}
	va_end(arg);
	return (wrote);
}
