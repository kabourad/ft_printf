/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero_n_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:47:16 by kabourad          #+#    #+#             */
/*   Updated: 2020/02/25 22:37:06 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	check_zero_n_print(char *num, t_options tab)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (num[i] == '-')
		i++;
	if (num[i] == '0' && tab.precision == 0 && tab.width && tab.verif == 0)
	{
		count += ft_putchar_ret(' ');
	}
	else if (num[i] == '0' && tab.precision == 0
	&& tab.verif == 0 && !tab.width)
		return(count);
	else
		while (num[i] && ft_isdigit(num[i]))
		{
			count += ft_putchar_ret(num[i]);
			i++;
		}
		return (count);
}

int 	check_zero_n_print_x(char *num, t_options tab)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (num[i] == '0' && tab.precision == 0 && tab.width && tab.verif == 0)
	{
		count += ft_putchar_ret(' ');
	}
	else if (num[i] == '0' && tab.precision == 0
			 && tab.verif == 0 && !tab.width)
		return(count);
	else
		while(num[i])
		{
			count += ft_putchar_ret(num[i]);
			i++;
		}
	return (count);
}