/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_c_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:24:28 by kabourad          #+#    #+#             */
/*   Updated: 2020/03/09 22:12:23 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags_c(t_options *tab)
{
	if ((*tab).flag_zero == 1 && (*tab).flag_left == 1)
		(*tab).flag_zero = 0;
	if ((*tab).width < 0)
	{
		(*tab).flag_left = 1;
		(*tab).width = (*tab).width * -1;
	}
	if ((*tab).width)
		(*tab).width = (*tab).width - 1;
}

int		with_flagleft_c(char c, t_options tab)
{
	int i;
	int y;

	i = 0;
	y = 0;
	y += write(1, &c, 1);
	if (tab.width && tab.flag_zero == 0)
	{
		while (i < tab.width)
		{
			y += ft_putchar_ret(' ');
			i++;
		}
	}
	if (tab.width && tab.flag_zero == 1)
	{
		while (i < tab.width)
		{
			y += ft_putchar_ret('0');
			i++;
		}
	}
	return (y);
}

int		without_flagleft_c(char c, t_options tab)
{
	int i;
	int y;

	i = 0;
	y = 0;
	if (tab.width && tab.flag_zero == 0)
	{
		while (i < tab.width)
		{
			y += ft_putchar_ret(' ');
			i++;
		}
	}
	if (tab.width && tab.flag_zero == 1)
	{
		while (i < tab.width)
		{
			y += ft_putchar_ret('0');
			i++;
		}
	}
	y += write(1, &c, 1);
	return (y);
}
