/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:25:57 by kabourad          #+#    #+#             */
/*   Updated: 2020/03/06 19:46:03 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	with_flagleft_x(char *num, t_options tab)
{
	int count;
	int i;

	count = 0;
	i = 0;
	count += print_num_x(num, tab);
	if (tab.width && tab.flag_zero == 0)
	{
		while (i < tab.width)
		{
			count += ft_putchar_ret(' ');
			i++;
		}
	}
	return (count);
}

int	without_flagleft_x(char *num, t_options tab)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (tab.width && tab.flag_zero == 0)
	{
		while (i < tab.width)
		{
			count += ft_putchar_ret(' ');
			i++;
		}
	}
	if (tab.width && tab.flag_zero == 1)
	{
		while (i < tab.width)
		{
			count += ft_putchar_ret('0');
			i++;
		}
	}
	count += print_num_x(num, tab);
	return (count);
}

int	compose_result_x(t_options tab, char *num)
{
	int i;

	i = 0;
	if (tab.flag_left == 1)
		i += with_flagleft_x(num, tab);
	if (tab.flag_left == 0)
		i += without_flagleft_x(num, tab);
	return (i);
}

int	ft_treat_x(t_options tab, va_list *ap, char *pr)
{
	unsigned int	c;
	int				i;
	char			*num;

	(void)pr;
	i = 0;
	c = va_arg(*ap, unsigned int);
	num = ft_utoa_base(c, 16);
	check_flags_x(&tab);
	modify_pr_x(&tab, num);
	modify_wd_x(&tab, num);
	i += compose_result_x(tab, num);
	free(num);
	return (i);
}
