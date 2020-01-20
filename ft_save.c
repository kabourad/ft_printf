/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:31:21 by kabourad          #+#    #+#             */
/*   Updated: 2020/01/20 18:18:46 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_flag(char **tmp, t_options *stru)
{
	if (**tmp == '-')
	{
		(*stru).flag_left = 1;
		while (**tmp && **tmp == '-')
			(*tmp)++;
	}
	if (**tmp == '0')
	{
		(*stru).flag_zero = 1;
		while (**tmp && **tmp == '0')
			(*tmp)++;
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
			(*tmp)++;
	}
	else
	{
		i = ft_atoi(*tmp);
		while (ft_isdigit(**tmp))
			(*tmp)++;
	}
	return (i);
}

int		ft_save_precision(char **tmp, va_list ap)
{
	int i;

	i = 0;
	if (**tmp == '.')
		(*tmp)++;
	if (**tmp == '*')
	{
		i = va_arg(ap, int);
		while (**tmp == '*')
			(*tmp)++;
	}
	else
	{
		i = ft_atoi(*tmp);
		while (ft_isdigit(**tmp))
			(*tmp)++;
	}
	return (i);
}

//cspdiuxX%

int		ft_save_conv(char **tmp)
{
	if (**tmp == 'c')
		return (1);
	if (**tmp == 's')
		return (2);
	if (**tmp == 'p')
		return (3);
	if (**tmp == 'd')
		return (4);
	if (**tmp == 'i')
		return (5);
	if (**tmp == 'u')
		return (6);
	if (**tmp == 'x')
		return (7);
	if (**tmp == 'X')
		return (8);
	if (**tmp == '%')
		return (9);
	return (0);
}
