/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 14:35:07 by kabourad          #+#    #+#             */
/*   Updated: 2020/02/25 22:11:58 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	with_flagleft_num(char *num, t_options tab, int minus)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (minus == 1 && !tab.precision)
		count += ft_putchar_ret('-');
	count += print_num(num, tab, minus);
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
	return (count);
}

int	without_flagleft_num(char *num, t_options tab, int minus)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (minus == 1 && !tab.precision && !tab.width)
		count += ft_putchar_ret('-');
	if (tab.width && tab.flag_zero == 0)
	{
		while (i < tab.width)
		{
			count += ft_putchar_ret(' ');
			i++;
		}
		if (minus == 1)
			count += ft_putchar_ret('-');
	}
	if (tab.width && tab.flag_zero == 1)
	{

		while (i < tab.width)
		{
			count += ft_putchar_ret('0');
			i++;
		}
	}
	count += print_num(num, tab, minus);
	return (count);
}

int	compose_result_num(t_options tab, char *num, int minus)
{
	int i;

	i = 0;
	if (tab.flag_left == 1)
		i += with_flagleft_num(num, tab, minus);
	if (tab.flag_left == 0)
		i += without_flagleft_num(num, tab, minus);
	return (i);
}

int	ft_treat_d(t_options tab, va_list *ap, char *pr)
{
	int		c;
	int		i;
	int		minus;
	char	*num;

	(void)pr;
	i = 0;
	c = va_arg(*ap, int);
	minus = c < 0;
	num = ft_itoa(c);
	check_flags_num(&tab);
	modify_pr_num(&tab, num, minus);
	modify_wd_num(&tab, num, minus);
	i += compose_result_num(tab, num, minus);
	free(num);
	return (i);
}
