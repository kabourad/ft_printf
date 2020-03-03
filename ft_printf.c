/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:43:47 by kabourad          #+#    #+#             */
/*   Updated: 2020/02/04 18:46:34 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

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
			i += ft_handler(&tmp, &ap);
		else
			i += ft_putchar_ret(*tmp);
		tmp++;
	}
	va_end(ap);
	return (i);
}
//#define  STR "|hello%u|\n",  0
#define  STR "|hello%p|\n",0
//#define  STR "|hello%d|\n",  INT_MAX + 2
//#define  STR "|hello%10d|\n", -10

int main()
{
  int a = ft_printf(STR);
  int b  = printf(STR);
  printf("%i %i\n", a, b);
}
// .s .0 .0s s