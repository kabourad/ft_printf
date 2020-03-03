/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_u_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:06:12 by kabourad          #+#    #+#             */
/*   Updated: 2020/02/25 22:28:37 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	modify_pr_u(t_options *tab, char *num)
{
	if ((*tab).precision > 0)
		(*tab).flag_zero = 0;
	if ((*tab).precision > 0 && (*tab).precision > (int)ft_strlen(num))
	{
		(*tab).precision = (*tab).precision - ft_strlen(num);
		if ((*tab).precision == 0)
			(*tab).verif = 0;
	}
	else
		(*tab).precision = 0;
}

void	modify_wd_u(t_options *tab, char *num)
{
	if ((*tab).width && (*tab).width > (int)((*tab).precision + ft_strlen(num)))
		(*tab).width = (*tab).width - ((*tab).precision + ft_strlen(num));
	else
		(*tab).width = 0;
}
