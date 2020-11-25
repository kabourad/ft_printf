/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:43:47 by kabourad          #+#    #+#             */
/*   Updated: 2020/03/09 23:29:50 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int				i;
	va_list			ap;
	char			*tmp;

	va_start(ap, format);
	i = 0;
	tmp = (char *)format;
	while (*tmp)
	{
		if (*tmp == '%')
		{
			i += ft_handler(&tmp, &ap);
			tmp++;
		}
		else
		{
			i += ft_putchar_ret(*tmp);
			tmp++;
		}
	}
	va_end(ap);
	return (i);
}
