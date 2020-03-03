/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:24:28 by kabourad          #+#    #+#             */
/*   Updated: 2020/02/21 21:38:57 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	compose_result_c(t_options tab, char c)
{
	int i;

	i = 0;
	if (tab.flag_left == 1)
		i += with_flagleft_c(c, tab);
	if (tab.flag_left == 0)
		i += without_flagleft_c(c, tab);
	return (i);
}

int	ft_treat_c(t_options tab, va_list *ap, char *pr)
{
	char	c;
	int		i;

	(void)pr;
	c = va_arg(*ap, int);
	check_flags_c(&tab);
	i = compose_result_c(tab, c);
	return (i);
}
