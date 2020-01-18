/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:43:47 by kabourad          #+#    #+#             */
/*   Updated: 2020/01/18 20:04:39 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_special_join(char **result, char **format, int start, int len)
{
	char	*tmp;

	tmp = *result;
	*result = ft_strjoin(tmp, ft_substr(*format, start, len));
	free(tmp);
}

int		ft_printf(const char *format, ...)
{
	int				i;
	va_list			ap;
	char 			*tmp;

	va_start(ap, format);
	i	= 0;
	tmp = (char *)format;
	while (*tmp)
	{
		if (*tmp == '%')
		{
			tmp++;
			i += ft_handler(&tmp, ap);
		}
		else
		{
			i += ft_putchar_ret(*tmp);
		}
	}
	va_end(ap);
	return ();
}
