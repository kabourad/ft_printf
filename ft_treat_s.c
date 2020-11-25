/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:25:36 by kabourad          #+#    #+#             */
/*   Updated: 2020/03/06 20:22:59 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	with_flagleft_s(char *c, t_options tab)
{
	int i;
	int y;

	i = 0;
	y = 0;
	y += print_only_s(c, tab.precision);
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
	else
		return (y);
	return (y);
}

static int	without_flagleft_s(char *c, t_options tab)
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
	y += print_only_s(c, tab.precision);
	return (y);
}

static int	compose_result_s(t_options tab, char *c)
{
	int i;

	i = 0;
	if (tab.flag_left == 1)
		i += with_flagleft_s(c, tab);
	if (tab.flag_left == 0)
		i += without_flagleft_s(c, tab);
	return (i);
}

int			ft_treat_s(t_options tab, va_list *ap, char *pr)
{
	char	*c;
	int		i;

	(void)pr;
	i = 0;
	c = va_arg(*ap, char *);
	if (!c)
		c = "(null)";
	check_flags_s(&tab);
	modify_pr_s(&tab, c);
	modify_wd_s(&tab);
	i += compose_result_s(tab, c);
	return (i);
}
