/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:29:47 by kabourad          #+#    #+#             */
/*   Updated: 2020/03/09 22:13:25 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_error(t_options tab, va_list *ap, char *pr)
{
	int		count;
	char	c;

	(void)tab;
	(void)ap;
	c = *pr;
	count = 0;
	if (!c)
		return (count);
	check_flags_c(&tab);
	count = compose_result_c(tab, c);
	return (count);
}
