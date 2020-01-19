/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:00:49 by kabourad          #+#    #+#             */
/*   Updated: 2020/01/19 21:41:22 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_options	ft_save_struct(char **tmp, va_list ap)
{
	t_options	stru;

	stru.flag_left = 0;
	stru.flag_zero = 0;
	stru.conv = '\0';
	ft_save_flag(tmp, &stru);
	stru.width = ft_save_width(tmp, ap);
	stru.precision = ft_save_precision(tmp, ap);
	stru.conv = ft_save_conv(tmp);
}

int			ft_handler(char **tmp, va_list ap)
{
	t_options	tab;
	t_func		*f;
	int			i;

	tab = ft_save_struct(tmp, ap);
	f = ft_dispatch(tab);
	i = f(tab, ap);
	return (i);
}
