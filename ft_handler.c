/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:00:49 by kabourad          #+#    #+#             */
/*   Updated: 2020/03/09 22:11:58 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_func		*ft_dispatch(t_options tab)
{
	if (tab.conv == 'c')
		return (ft_treat_c);
	else if (tab.conv == 's')
		return (ft_treat_s);
	else if (tab.conv == 'p')
		return (ft_treat_p);
	else if (tab.conv == 'd' || tab.conv == 'i')
		return (ft_treat_d);
	else if (tab.conv == 'u')
		return (ft_treat_u);
	else if (tab.conv == 'x')
		return (ft_treat_x);
	else if (tab.conv == 'X')
		return (ft_treat_xmaj);
	else if (tab.conv == '%')
		return (ft_treat_perc);
	else
		return (ft_treat_error);
}

t_options	ft_save_struct(char **tmp, va_list *ap)
{
	t_options	stru;

	stru.flag_left = 0;
	stru.flag_zero = 0;
	stru.dot = 0;
	stru.negative = 0;
	stru.conv = '\0';
	ft_save_flag(tmp, &stru);
	stru.width = ft_save_width(tmp, ap);
	stru.precision = ft_save_precision(tmp, ap, &stru);
	stru.conv = **tmp;
	stru.verif = stru.precision;
	stru.min = 0;
	return (stru);
}

int			ft_handler(char **tmp, va_list *ap)
{
	t_options	tab;
	t_func		*ft_treat;
	char		*pr;
	int			i;

	(*tmp)++;
	pr = *tmp;
	tab = ft_save_struct(tmp, ap);
	ft_treat = ft_dispatch(tab);
	if (ft_treat == ft_treat_error && tab.conv)
		pr = *tmp;
	i = ft_treat(tab, ap, pr);
	if (!tab.conv)
		(*tmp)--;
	return (i);
}
