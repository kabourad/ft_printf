/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:16:18 by kabourad          #+#    #+#             */
/*   Updated: 2019/12/04 18:20:56 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

	//printf works like this %(flags)(minimumfieldwidth)(period)(argtype)
	
	/*args reading
	format treatement
	flags -0.* minimum field width
	deal with cspdiuxX% conversions
	final result
	print final result */

// 0 == 1
// - == 2

int	ft_flags(char **fmt)
{
	char *a;

	a = *fmt;
	if (*a == '0')
	{
		*fmt = a + 1;
		return (1);
	}
	else if (*a == '-')
	{
		*fmt = a + 1;
		return (2);
	}
	return (-1);
}

t_options	*ft_options(void)
{
	t_options *op;

	if (!(op = malloc(sizeof(t_options))))
		return (NULL);
	op->flagleft = 0;
	op->flagzero = 0;
	op->width = -1;
	op->precision = -1;
	op->type = '\0';
	return (op);
}



int	ft_printf(const char *format, ...)
{
	t_options	*stru;
	va_list		pr;
	int			i;
	char		*fmt;
	int			ret;

	i = 0;
	stru = NULL;
	fmt = (char *)format;
	va_start(pr, format);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			stru = ft_options();
			while ((ret = ft_flags(&fmt)) != -1)
			{
				if (ret == 1)
					stru->flagzero = 1;
				else if (ret == 2)
					stru->flagleft = 1;
			}
		}
		else
			putchar(*fmt);
		fmt++;
	}
}


int	main()
{
	ft_printf("ayman is a bitch %0d");

	return(0);
}