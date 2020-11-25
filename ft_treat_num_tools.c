/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_num_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:06:12 by kabourad          #+#    #+#             */
/*   Updated: 2020/03/09 23:32:04 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags_num(t_options *tab)
{
	if ((*tab).width < 0)
	{
		(*tab).flag_left = 1;
		(*tab).width = (*tab).width * -1;
	}
	if ((*tab).flag_zero == 1 && (*tab).flag_left == 1)
		(*tab).flag_zero = 0;
}

void	modify_pr_num(t_options *tab, char *num, int minus)
{
	(*tab).negative = minus;
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
		if (tab->min)
			(*tab).precision = (*tab).precision - (ft_strlen(num) - 1);
		else
			(*tab).precision = (*tab).precision - (ft_strlen(num));
		if ((*tab).precision == 0)
			(*tab).verif = 0;
	}
	else
		(*tab).precision = 0;
}

void	modify_wd_num(t_options *tab, char *num, int minus)
{
	(void)minus;
	if ((*tab).width && (unsigned long)(*tab).width > ((*tab).precision +
			ft_strlen(num)) && (*tab).negative)
	{
		if (tab->min)
			(*tab).width = (*tab).width - ((*tab).precision + ft_strlen(num));
		else
			(*tab).width = (*tab).width -
				((*tab).precision + ft_strlen(num) + 1);
	}
	else if ((*tab).width && (unsigned long)(*tab).width
			> ((*tab).precision + ft_strlen(num)) && !(*tab).negative)
		(*tab).width = (*tab).width - ((*tab).precision + ft_strlen(num));
	else
		(*tab).width = 0;
}

int		print_num(char *num, t_options tab, int *minus)
{
	int y;
	int count;

	y = 0;
	count = 0;
	if (*minus == 1 && tab.precision)
	{
		count += ft_putchar_ret('-');
		*minus = 0;
	}
	while (y < tab.precision)
	{
		count += ft_putchar_ret('0');
		y++;
	}
	count += check_zero_n_print(num, tab);
	return (count);
}
