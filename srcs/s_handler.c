/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   s_handler.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: akdovlet <akdovlet@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/11/09 17:43:29 by akdovlet		  #+#	#+#			 */
/*   Updated: 2023/12/22 12:15:51 by akdovlet		 ###   ########.fr	   */
/*																			*/
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
	if (len == 0)
		return (0);
	return (write(1, str, len));
}

// int	s_handler(char *str, t_flag flags)
// {
// 	int	count;
// 	int	len;

// 	count = 0;
// 	if (flags.dot && flags.precision == 0)
// 		return (0);
// 	len = ft_strlen(str);
// 	if (flags.dot && flags.precision >= 0 && flags.precision < len)
// 		len = flags.precision;
// 	if (flags.dash)
// 		count += ft_putstrlen(str, len);
// 	count += width_manager(flags.width, len, 0);
// 	if (!flags.dash)
// 		count += ft_putstrlen(str, len);
// 	return (count);
// }

int s_handler(char *str, t_flag flags)
{
	int count = 0;
	int len = 6;

	if (str)
	{
		len = ft_strlen(str);
		if (flags.dot && flags.precision >= 0 && flags.precision < len)
			len = flags.precision;
	}
	else if (!str)
	{
		if (flags.dot && flags.precision < 6)
			len = 0;
		else
			str = "(null)";
	}
	if (flags.dash)
		count += ft_putstrlen(str, len);
	count += width_manager(flags.width, len, flags.zero);
	if (!flags.dash)
		count += ft_putstrlen(str, len);
	return (count);
}
