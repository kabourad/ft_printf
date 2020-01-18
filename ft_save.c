/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:31:21 by kabourad          #+#    #+#             */
/*   Updated: 2020/01/15 13:33:10 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	save_flags(char *fmt, t_options *option, int i)
{
	if (fmt[i] == '-')
	{
		option->flag_left = 1;
		while (fmt[i] == '-' && fmt[i])
			i++;
	}
	else if (fmt[i] == '0')
	{
		option->flag_zero = 1;
		while (fmt[i] == '0' && fmt[i])
			i++;
	}
	return (i);
}

int	save_width(char *fmt, t_options *option, va_list ap, int i)
{
	if (fmt[i] == '*')
	{
		option->width = va_arg(ap, int);
		while (fmt[i] == '*')
			i++;
	}
	else
	{
		option->width = ft_atoi(fmt + i);
		while (ft_isdigit(fmt[i]))
			i++;
	}
	i--;
	return (i);
}

int	save_precision(char *fmt, t_options *option, va_list ap, int i)
{
	if (fmt[i] == '.')
		i++;
	if (fmt[i] == '*')
	{
		option->precision = va_arg(ap, int);
		while (fmt[i] == '*')
			i++;
	}
	else
	{
		option->precision = ft_atoi(fmt + i);
		while (ft_isdigit(fmt[i]))
			i++;
	}
	return (i);
}