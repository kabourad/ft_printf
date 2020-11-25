/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:31:21 by kabourad          #+#    #+#             */
/*   Updated: 2020/03/09 23:30:20 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_flag(char **tmp, t_options *stru)
{
	while (**tmp && (**tmp == '-' || **tmp == '0'))
	{
		if (**tmp == '-')
		{
			(*stru).flag_left = 1;
			(*tmp)++;
		}
		if (**tmp == '0')
		{
			(*stru).flag_zero = 1;
			(*tmp)++;
		}
	}
}

int		ft_save_width(char **tmp, va_list *ap)
{
	int i;

	i = 0;
	if (**tmp && ft_isdigit(**tmp))
	{
		i = ft_atoi(*tmp);
		while (ft_isdigit(**tmp))
			(*tmp)++;
	}
	else if (**tmp == '*')
	{
		while (**tmp == '*')
		{
			i = va_arg(*ap, int);
			(*tmp)++;
		}
	}
	return (i);
}

int		ft_save_precision(char **tmp, va_list *ap, t_options *stru)
{
	int i;

	i = -1;
	if (**tmp == '.' && ((**tmp + 1) != '*' || !ft_isdigit(**tmp)))
	{
		stru->dot = 1;
		i = 0;
	}
	if (**tmp == '.')
		(*tmp)++;
	if (**tmp && (ft_isdigit(**tmp) || **tmp == '-') && *(*tmp - 1) == '.')
	{
		i = ft_atoi(*tmp);
		while (**tmp == '-' || ft_isdigit(**tmp))
			(*tmp)++;
	}
	if (**tmp == '*' && *(*tmp - 1) == '.')
	{
		while (**tmp == '*')
		{
			i = va_arg(*ap, int);
			(*tmp)++;
		}
	}
	return (i);
}
