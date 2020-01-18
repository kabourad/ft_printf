/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:24:28 by kabourad          #+#    #+#             */
/*   Updated: 2020/01/15 13:30:51 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_c(t_options option, va_list ap, char **res)
{
    printf("%d, %d, %d, %d", option.flag_left, option.flag_zero, option.width, option.precision);
	return (0);
}