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
    ft_save_wd(tmp, ap, &stru);
    ft_save_pr(tmp,ap, &stru);
    ft_save_conv(tmp, &stru);

}

int     ft_handler(char **tmp, va_list ap)
{
    t_options   tab;
    int         i;
    
    tab = ft_save_struct(tmp, ap);
    ft_dispatch(tab);
    i =ft_print_res(tmp, ap, tab);
    return (i);
}