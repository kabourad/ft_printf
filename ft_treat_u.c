/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:25:42 by kabourad          #+#    #+#             */
/*   Updated: 2020/02/25 22:13:11 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_u(t_options tab, va_list *ap, char *pr)
{
	unsigned int	c;
	int				i;
	int				minus;
	char			*num;

	(void)pr;
	i = 0;
	minus = 0;
	c = va_arg(*ap, unsigned int);
	num = ft_utoa(c);
	check_flags_num(&tab);
	modify_pr_u(&tab, num);
	modify_wd_u(&tab, num);
	i += compose_result_num(tab, num, minus);
	free(num);
	return (i);
}
