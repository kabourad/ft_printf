/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:41:38 by kabourad          #+#    #+#             */
/*   Updated: 2020/03/05 16:22:04 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		numblen(unsigned int n)
{
	int b;

	b = 0;
	if (n <= 0)
		b++;
	while (n)
	{
		n /= 10;
		b++;
	}
	return (b);
}

char			*ft_utoa(unsigned int n)
{
	char	*allocator;
	int		len;
	int		i;
	int		start;

	len = numblen(n);
	i = len - 1;
	start = 0;
	if (!(allocator = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i >= start)
	{
		allocator[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	allocator[len] = '\0';
	return (allocator);
}
