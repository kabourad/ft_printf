/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:29:47 by kabourad          #+#    #+#             */
/*   Updated: 2020/01/31 15:45:35 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_error(t_options tab, va_list *ap, char *pr)
{
	int count;

	count = 0;
	(void)tab;
	(void)ap;
	pr++;
	while (*pr && *pr != ' ' && *pr != '\n' && *pr != '%'
	&& *pr != '\t' && *pr != '\v' && *pr !='\f' && *pr != '\r')
	{
		count += ft_putchar_ret(*pr);
		pr++;
	}
	return (count);
}
