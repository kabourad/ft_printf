/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:41:38 by kabourad          #+#    #+#             */
/*   Updated: 2020/02/14 21:51:41 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numblen(unsigned int n, int base)
{
	int b;

	b = 0;
	if (n == 0)
		b++;
	while (n)
	{
		n /= base;
		b++;
	}
	return (b);
}

static char	calcul_base(int n)
{
	if (n > 9)
		return (n + 'a' - 10);
	else
		return (n + '0');
}

char		*ft_utoa_base(unsigned int n, int base)
{
	char	*allocator;
	int		len;
	int		i;
	int		start;

	len = numblen(n, base);
	i = len - 1;
	start = 0;
	if (!(allocator = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i >= start)
	{
		allocator[i] = calcul_base(n % base);
		n /= base;
		i--;
	}
	allocator[len] = '\0';
	return (allocator);
}
