/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:31:21 by kabourad          #+#    #+#             */
/*   Updated: 2020/02/04 19:14:30 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_flag(char **tmp, t_options *stru)
{
	while (**tmp && **tmp != '*' && **tmp != '.' && **tmp != '%' &&
	(!ft_isalnum(**tmp) || **tmp == '0'))
	{
		if (**tmp == '-')
			(*stru).flag_left = 1;
		if (**tmp == '0')
			(*stru).flag_zero = 1;
		(*tmp)++;
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
		i = va_arg(*ap, int);
            (*tmp)++;
	}
	return (i);
}

int		ft_save_precision(char **tmp, va_list *ap)
{
	int i;

	i = -1;
	if (**tmp == '.' && ((**tmp + 1) != '*' || !ft_isdigit(**tmp)))
		i = 0;
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
        i = va_arg(*ap, int);
        (*tmp)++;
    }
    return (i);
}
