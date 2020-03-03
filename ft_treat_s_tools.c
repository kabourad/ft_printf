/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_s_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:06:28 by kabourad          #+#    #+#             */
/*   Updated: 2020/02/22 00:19:49 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags_s(t_options *tab)
{
	if ((*tab).flag_zero == 1 && (*tab).flag_left == 1)
		(*tab).flag_zero = 0;
	if ((*tab).width < 0)
	{
		(*tab).flag_left = 1;
		(*tab).width = (*tab).width * -1;
	}
}

void	modify_pr_s(t_options *tab, char *c)
{
	if ((*tab).precision > 0 && (*tab).precision < (int)ft_strlen(c))
		(*tab).precision = (*tab).precision;
	else if ((*tab).precision == 0)
		(*tab).precision = 0;
	else
		(*tab).precision = ft_strlen(c);
}

void	modify_wd_s(t_options *tab)
{
	if ((*tab).width && (*tab).width > (*tab).precision)
		(*tab).width = (*tab).width - (*tab).precision;
	else
		(*tab).width = 0;
}

int	print_only_s(char *c, int b)
{
	int y;
	int i;
	int count;

	y = 0;
	i = 0;
	count = 0;
	while (c[y] && i < b)
	{
		count += ft_putchar_ret(c[y]);
		y++;
		i++;
	}
	return (count);
}
