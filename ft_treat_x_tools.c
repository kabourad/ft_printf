/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_x_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 21:53:14 by kabourad          #+#    #+#             */
/*   Updated: 2020/02/25 22:38:28 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags_x(t_options *tab)
{
	if ((*tab).flag_zero == 1 && (*tab).flag_left == 1)
		(*tab).flag_zero = 0;
	if ((*tab).flag_zero == 1 && (*tab).precision > -1)
		(*tab).flag_zero = 0;
	if ((*tab).width < 0)
	{
		(*tab).flag_left = 1;
		(*tab).width = (*tab).width * -1;
	}
}

void	modify_pr_x(t_options *tab, char *num)
{
	if ((*tab).precision > 0 && (*tab).precision > (int)ft_strlen(num))
	{
		(*tab).precision = (*tab).precision - ft_strlen(num);
		if ((*tab).precision == 0)
			(*tab).verif = 0;
	}
	else
		(*tab).precision = 0;
}

void	modify_wd_x(t_options *tab, char *num)
{
	if ((*tab).width
	&& (unsigned long)(*tab).width > ((*tab).precision + ft_strlen(num)))
		(*tab).width = (*tab).width - ((*tab).precision + ft_strlen(num));
	else
		(*tab).width = 0;
}

int	print_num_x(char *num, t_options tab)
{
	int y;
	int count;

	y = 0;
	count = 0;
	while (y < tab.precision)
	{
		count += ft_putchar_ret('0');
		y++;
	}
	count += check_zero_n_print_x(num, tab);
	return (count);
}
