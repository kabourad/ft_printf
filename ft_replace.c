/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:28:40 by kabourad          #+#    #+#             */
/*   Updated: 2020/01/15 13:30:40 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int		(*g_funct_tab[9])(t_options, va_list, char **) = {ft_treat_c,
// 		ft_treat_s, ft_treat_p, ft_treat_d, ft_treat_i, ft_treat_u,
// 		ft_treat_x, ft_treat_xmaj, ft_treat_perc};

int		find_conv(char *fmt, char *s)
{
	int	i;
	
	i = 0;
	while (!(ft_strchr(s, *fmt)) && *fmt)
		fmt++;
	if (*fmt == '\0')
		return (-1);
	while(s[i] != *fmt && s[i])
		i++;
	return(i);
}

int		ft_replace(char *fmt, va_list ap, char **res)
{
	t_options	option;
	int			i;
	int			conv;

	option = (t_options){0, 0, 0, 0};
	i = 0;
	i += save_flags(fmt, &option, i);
	//printf("i save flags : %d\n", i);
	i += save_width(fmt, &option, ap, i);
	//printf("i save  wd : %d\n", i);
	i += save_precision(fmt, &option, ap, i);
	//printf("i save precision : %d\n", i);


	return (i);
}
