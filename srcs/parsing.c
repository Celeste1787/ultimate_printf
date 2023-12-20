/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:38:02 by akdovlet          #+#    #+#             */
/*   Updated: 2023/12/20 17:00:40 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	flag_init(t_flag *flags)
{

	flags->dash = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->length = 0;
	flags->dot = 0;
}

void	flag_parsing(char const *str, t_flag *flags, int *i)
{
	flag_init(flags);
	while (str[*i])
	{
		if (str[*i] == '-')
			flags->dash = 1;
		else if (str[*i] == '+')
			flags->plus = 1;
		else if (str[*i] == '#')
			flags->hash = 1;
		else if (str[*i] == ' ')
			flags->space = 1;
		else if (str[*i] == '0')
			flags->zero = 1;
		else
			break ;
		(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		flags->width = flags->width * 10 + (str[*i] - 48);
		(*i)++;
	}
}

void	flag_precision(char const *str, t_flag *flags, int *i)
{
	if (str[*i] == '.')
	{
		flags->dot = 1;
		(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		flags->precision = flags->precision * 10 + (str[*i] - 48);
		(*i)++;
	}
}
