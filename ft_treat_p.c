/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:25:14 by kabourad          #+#    #+#             */
/*   Updated: 2020/03/06 19:47:30 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	with_flagleft_p(char *num, t_options tab)
{
	int count;
	int i;

	count = 0;
	i = 0;
	count += print_p(num, tab);
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
		if (!tab.precision)
			count += put_ox();
		while (i < tab.width)
		{
			count += ft_putchar_ret('0');
			i++;
		}
	}
	return (count);
}

static int	without_flagleft_p(char *num, t_options tab)
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
		if (!tab.precision)
			count += put_ox();
		while (i < tab.width)
		{
			count += ft_putchar_ret('0');
			i++;
		}
	}
	count += print_p(num, tab);
	return (count);
}

static int	compose_result_p(t_options tab, char *num)
{
	int i;

	i = 0;
	if (tab.flag_left == 1)
		i += with_flagleft_p(num, tab);
	if (tab.flag_left == 0)
		i += without_flagleft_p(num, tab);
	return (i);
}

int			ft_treat_p(t_options tab, va_list *ap, char *pr)
{
	unsigned long long	c;
	int					i;
	char				*num;

	(void)pr;
	i = 0;
	c = va_arg(*ap, unsigned long long);
	num = ft_ulltoa_base(c, 16);
	check_flags_p(&tab);
	modify_pr_p(&tab, num);
	modify_wd_p(&tab, num);
	i += compose_result_p(tab, num);
	free(num);
	return (i);
}
