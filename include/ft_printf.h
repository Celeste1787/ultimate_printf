/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:41:04 by akdovlet          #+#    #+#             */
/*   Updated: 2023/12/20 20:08:58 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>

typedef	struct s_flag
{
	int dash;
	int	plus;
	int	zero;
	int	space;
	int	hash;
	int width;
	int	precision;
	int	dot;
	int	length;
}	t_flag;

int		ft_printf(const char *str, ...);
int		ft_draft(char flag, va_list *arg, t_flag flags);

int		ft_strlen(char *str);
int		ft_putstrlen(char *str, int len);

int		ft_put_n_count_char(char c);
int		ft_put_n_count_nbr(long n, int count);
int		ft_put_n_count_u(unsigned int n, int count);
int		ft_put_n_count_hex(size_t n, int count, int bin);

int		ft_nbcount(size_t n, int base);
char	*ft_itoa(int n);
int		ft_atoi(const char *nptr, int *i);
int		ft_isdigit(int c);

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

int		c_handler(int c, t_flag flags);
int		d_handler(int n, t_flag flags);
int		p_handler(size_t n, t_flag flags);
int		s_handler(char *str, t_flag flags);
int		u_handler(va_list *arg);
int		x_handler(va_list *arg, int bin);

void	flag_init(t_flag *flags);
void	flag_parsing(char const *str, t_flag *flags, int *i);
void	flag_precision(char const *str, t_flag *flags, int *i);

int		width_manager(int width, int minus, int zero);

#endif
