/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:00:49 by kabourad          #+#    #+#             */
/*   Updated: 2020/01/18 20:26:49 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


t_options   ft_save_struct(char **tmp, va_list ap)
{
    t_options stru;

    ft_saveflag(tmp, &stru);
    stru.width = ft_save_wd(tmp, ap, &stru);
    stru.precision = ft_save_pr(tmp,ap, &stru);
    stru.conv = ft_save_conv(tmp);

}

int     ft_handler(char **tmp, va_list ap)
{
    t_options   tab;
	t_func		*f;
    int         i;
    
    tab = ft_save_struct(tmp, ap);
    f = ft_dispatch(tab);
	i = f(tab, ap);
    return (i);
}