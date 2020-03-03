/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_num_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:06:12 by kabourad          #+#    #+#             */
/*   Updated: 2020/02/25 22:27:51 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags_num(t_options *tab)
{
	if ((*tab).flag_zero == 1 && (*tab).flag_left == 1)
		(*tab).flag_zero = 0;
	if ((*tab).width < 0)
	{
		(*tab).flag_left = 1;
		(*tab).width = (*tab).width * -1;
	}
}

void	modify_pr_num(t_options *tab, char *num, int minus)
{
	if ((*tab).precision > -1)
		(*tab).flag_zero = 0;
	if ((*tab).precision > -1 && (*tab).precision > (int)ft_strlen(num)
	&& minus == 0)
	{
		(*tab).precision = (*tab).precision - ft_strlen(num);
		if ((*tab).precision == 0)
			(*tab).verif = 0;
	}
	else if ((*tab).precision > -1 && (*tab).precision > (int)ft_strlen(num)
	&& minus == 1)
	{
		(*tab).precision = (*tab).precision - (ft_strlen(num) - 1);
		if ((*tab).precision == 0)
			(*tab).verif = 0;
	}
	else
		(*tab).precision = 0;
}

void	modify_wd_num(t_options *tab, char *num, int minus)
{
	(void)minus;
	if ((*tab).width
	&& (unsigned long)(*tab).width > ((*tab).precision + ft_strlen(num)))
		(*tab).width = (*tab).width - ((*tab).precision + ft_strlen(num));
	else
		(*tab).width = 0;
}

int		print_num(char *num, t_options tab, int minus)
{
	int y;
	int i;
	int count;

	y = 0;
	i = 0;
	count = 0;
	if (minus == 1 && tab.precision && !tab.width)
	{
		count += ft_putchar_ret('-');
	}
	while (y < tab.precision)
	{
		count += ft_putchar_ret('0');
		y++;
	}
	count += check_zero_n_print(num, tab);
	return (count);
}
