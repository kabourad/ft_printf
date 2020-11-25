/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 14:35:07 by kabourad          #+#    #+#             */
/*   Updated: 2020/03/06 19:38:04 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_min(int *count, int *minus)
{
	*count += ft_putchar_ret('-');
	*minus = 0;
}

int			with_flagleft_num(char *num, t_options tab, int *minus)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (*minus == 1 && !tab.precision)
	{
		count += ft_putchar_ret('-');
		*minus = 0;
	}
	count += print_num(num, tab, minus);
	if (tab.width && tab.flag_zero == 0)
	{
		while (i++ < tab.width)
			count += ft_putchar_ret(' ');
	}
	if (tab.width && tab.flag_zero == 1)
	{
		while (i++ < tab.width)
			count += ft_putchar_ret('0');
	}
	return (count);
}

int			without_flagleft_num(char *num, t_options tab, int *minus)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (*minus == 1 && !tab.precision && !tab.width)
		ft_put_min(&count, minus);
	if (tab.width && tab.flag_zero == 0)
	{
		while (i++ < tab.width)
			count += ft_putchar_ret(' ');
		if (*minus == 1)
			ft_put_min(&count, minus);
	}
	if (tab.width && tab.flag_zero == 1)
	{
		if (*minus == 1 && !tab.precision)
			ft_put_min(&count, minus);
		while (i++ < tab.width)
			count += ft_putchar_ret('0');
	}
	count += print_num(num, tab, minus);
	return (count);
}

int			compose_result_num(t_options tab, char *num, int minus)
{
	int i;

	i = 0;
	if (tab.flag_left == 1)
		i += with_flagleft_num(num, tab, &minus);
	if (tab.flag_left == 0)
		i += without_flagleft_num(num, tab, &minus);
	return (i);
}

int			ft_treat_d(t_options tab, va_list *ap, char *pr)
{
	int		c;
	int		i;
	int		minus;
	char	*num;

	(void)pr;
	i = 0;
	c = va_arg(*ap, int);
	minus = c < 0;
	if (c == -2147483648)
		tab.min = 1;
	if (minus == 1)
		c *= -1;
	num = ft_itoa(c);
	check_flags_num(&tab);
	modify_pr_num(&tab, num, minus);
	modify_wd_num(&tab, num, minus);
	i += compose_result_num(tab, num, minus);
	free(num);
	return (i);
}
