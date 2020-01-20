/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:43:47 by kabourad          #+#    #+#             */
/*   Updated: 2020/01/20 20:40:03 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
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
			i += ft_handler(&tmp, ap);
		else
			i += ft_putchar_ret(*tmp);
	}
	va_end(ap);
	return (i);
}
