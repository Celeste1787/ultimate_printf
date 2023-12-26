/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:38:02 by akdovlet          #+#    #+#             */
/*   Updated: 2023/12/26 22:26:28 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void apply_rules(t_flag *flags)
{
	if (flags->precision >= flags->width)
		flags->width = 0;
	flags->total_width = flags->width;
	if ((flags->zero && flags->dash) || flags->precision > 0)
		flags->zero = 0;
	if (flags->plus && flags->space)
		flags->space = 0;
	// if (flags->precision > 0 && flags->precision < flags->width)
	// 	flags->total_width = flags->width - flags->precision;
}
void	flag_parsing(char const *str, t_flag *flags, int *i)
{
	*flags = (t_flag){};
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
	apply_rules(flags);
}
