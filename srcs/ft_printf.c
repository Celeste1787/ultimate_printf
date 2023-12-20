/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:00:29 by akdovlet          #+#    #+#             */
/*   Updated: 2023/12/20 17:01:31 by akdovlet         ###   ########.fr       */
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
			// printf("flags->hash 		= %d\n", flags.hash);
			// printf("flags->dash 		= %d\n", flags.dash);
			// printf("flags->space 		= %d\n", flags.space);
			// printf("flags->precision 	= %d\n", flags.precision);
			// printf("flags->dot			= %d\n", flags.dot);
			// printf("flags->width 		= %d\n", flags.width);
			// printf("flags->zero 		= %d\n", flags.zero);
			wrote += ft_draft(str[i], &arg, flags);
			// i++;
		}
		else
			wrote += ft_put_n_count_char(str[i]);
		i++;
	}
	va_end(arg);
	return (wrote);
}
