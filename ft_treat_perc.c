/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:25:25 by kabourad          #+#    #+#             */
/*   Updated: 2020/03/05 16:23:40 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_perc(t_options tab, va_list *ap, char *pr)
{
	char	c;
	int		i;

	(void)pr;
	(void)ap;
	c = '%';
	check_flags_c(&tab);
	i = compose_result_c(tab, c);
	return (i);
}
