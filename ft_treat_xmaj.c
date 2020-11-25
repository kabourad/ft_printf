/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_xmaj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:26:24 by kabourad          #+#    #+#             */
/*   Updated: 2020/02/21 21:38:32 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_xmaj(t_options tab, va_list *ap, char *pr)
{
	unsigned int	c;
	int				i;
	char			*num;

	(void)pr;
	i = 0;
	c = va_arg(*ap, unsigned int);
	num = ft_utoamaj_base(c, 16);
	check_flags_x(&tab);
	modify_pr_x(&tab, num);
	modify_wd_x(&tab, num);
	i += compose_result_x(tab, num);
	free(num);
	return (i);
}
