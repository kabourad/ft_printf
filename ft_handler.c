/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:00:49 by kabourad          #+#    #+#             */
/*   Updated: 2020/01/20 20:46:12 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_func	*ft_dispatch(t_options tab)
{
	if (tab.conv == 1)
		return (ft_treat_c);
	else if (tab.conv == 2)
		return (ft_treat_s);
	else if (tab.conv == 3)
		return (ft_treat_p);
	else if (tab.conv == 4)
		return (ft_treat_d);
	else if (tab.conv == 5)
		return (ft_treat_i);
	else if (tab.conv == 6)
		return (ft_treat_u);
	else if (tab.conv == 7)
		return (ft_treat_x);
	else if (tab.conv == 8)
		return (ft_treat_xmaj);
	else if (tab.conv == 9)
		return (ft_treat_perc);
	else
		return (ft_treat_error);
}

t_options	ft_save_struct(char **tmp, va_list ap)
{
	t_options	stru;

	stru.flag_left = 0;
	stru.flag_zero = 0;
	stru.conv = 0;
	ft_save_flag(tmp, &stru);
	stru.width = ft_save_width(tmp, ap);
	stru.precision = ft_save_precision(tmp, ap);
	stru.conv = ft_save_conv(tmp);
}

int			ft_handler(char **tmp, va_list ap)
{
	t_options	tab;
	t_func		*ft_treat;
	char		*pr;
	int			i;

	pr = *tmp;
	(*tmp)++;
	tab = ft_save_struct(tmp, ap);
	ft_treat = ft_dispatch(tab);
	i = ft_treat(tab, ap, pr);
	return (i);
}
