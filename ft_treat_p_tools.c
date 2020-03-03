/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_p_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:53:22 by kabourad          #+#    #+#             */
/*   Updated: 2020/02/22 00:16:47 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_ox(void)
{
	int count;

	count = 0;
	count += ft_putchar_ret('0');
	count += ft_putchar_ret('x');
	return (count);
}

void	check_flags_p(t_options *tab)
{
	if ((*tab).flag_zero == 1)
		(*tab).flag_zero = 0;
	if ((*tab).width < 0)
	{
		(*tab).flag_left = 1;
		(*tab).width = (*tab).width * -1;
	}
}

void	modify_wd_p(t_options *tab, char *num)
{
	if ((*tab).width && (unsigned long)(*tab).width > (ft_strlen(num) + 2))
		(*tab).width = (*tab).width - (ft_strlen(num) + 2);
	else
		(*tab).width = 0;
}

void	modify_pr_p(t_options *tab, char *num)
{
	if ((*tab).precision > 0)
		(*tab).flag_zero = 0;
	if ((*tab).precision > 0 && (*tab).precision > (int)ft_strlen(num))
		(*tab).precision = (*tab).precision - ft_strlen(num);
	else
		(*tab).precision = 0;
}

int	print_p(char *num, t_options tab)
{
	int i;
	int y;
	int count;

	i = 0;
	y = -1;
	count = 0;
	if (tab.precision)
	{
		count += put_ox();
		while (i < tab.precision)
		{
			count += ft_putchar_ret('0');
			i++;
		}
	}
	else
		count += put_ox();
	while (num[++y])
		printf("hi");
		count += ft_putchar_ret(num[y]);
	return (count);
}
