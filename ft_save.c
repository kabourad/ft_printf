/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:31:21 by kabourad          #+#    #+#             */
/*   Updated: 2020/01/19 21:41:21 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_flag(char **tmp, t_options *stru)
{
	if (**tmp == '-')
	{
		(*stru).flag_left = 1;
		while (**tmp && **tmp == '-')
			tmp++;
	}
	if (**tmp == '0')
	{
		(*stru).flag_zero = 1;
		while (**tmp && **tmp == '0')
			tmp++;
	}
}

int		ft_save_width(char **tmp, va_list ap)
{
	int i;

	i = 0;
	if (**tmp == '*')
	{
		i = va_arg(ap, int);
		while (**tmp == '*')
			tmp++;
	}
	else
	{
		i = ft_atoi(*tmp);
		while (ft_isdigit(**tmp))
			tmp++;
	}
	return (i);
}

int		ft_save_precision(char **tmp, va_list ap)
{
	int i;

	i = 0;
	if (**tmp == '.')
		tmp++;
	if (**tmp == '*')
	{
		i = va_arg(ap, int);
		while (**tmp == '*')
			tmp++;
	}
	else
	{
		i = ft_atoi(*tmp);
		while (ft_isdigit(**tmp))
			tmp++;
	}
	return (i);
}









































	*tmp_options *option, int i)
// {
// 	if (fmt[i] == '-')
// 		{
// 		option->flag_left = 1;
// 		while (fmt[i] == '-' && fmt[i])
// 			i++;
// 	}
// 	else if (fmt[i] == '0')
// 	{
// 		option->flag_zero = 1;
// 		while (fmt[i] == '0' && fmt[i])
// 			i++;
// 	}
// 	return (i);
// }

// int	save_width(char *fmt, t_options *option, va_list ap, int i)
// {
// 	if (fmt[i] == '*')
// 	{
// 		option->width = va_arg(ap, int);
// 		while (fmt[i] == '*')
// 			i++;
// 	}
// 	else
// 	{
// 		option->width = ft_atoi(fmt + i);
// 		while (ft_isdigit(fmt[i]))
// 			i++;
// 	}
// 	i--;
// 	return (i);
// }

// int	save_precision(char *fmt, t_options *option, va_list ap, int i)
// {
// 	if (fmt[i] == '.')
// 		i++;
// 	if (fmt[i] == '*')
// 	{
// 		option->precision = va_arg(ap, int);
// 		while (fmt[i] == '*')
// 			i++;
// 	}
// 	else
// 	{
// 		option->precision = ft_atoi(fmt + i);
// 		while (ft_isdigit(fmt[i]))
// 			i++;
// 	}
// 	return (i);
// }