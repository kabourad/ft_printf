/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:25:49 by kabourad          #+#    #+#             */
/*   Updated: 2020/01/20 20:46:18 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//includes
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>


//structs

typedef	struct	s_options
{
	int		flag_left;
	int		flag_zero;
	int		width;
	int		precision;
	int		conv;
}				t_options;

typedef	int	(t_func)(t_options, va_list, char*);

//prototypes
int			ft_printf(const char *format, ...);
char		*ft_itoa_base(int n, int base);
int			ft_putchar_ret(char c);
int     	ft_handler(char **tmp, va_list ap);
void		ft_save_flag(char **tmp, t_options *stru);
int			ft_save_width(char **tmp, va_list ap);
int			ft_save_conv(char **tmp);
int			ft_save_precision(char **tmp, va_list ap);
int			ft_treat_d(t_options tab, va_list ap, char *pr);
int			ft_treat_c(t_options tab, va_list ap, char *pr);
int			ft_treat_s(t_options tab, va_list ap, char *pr);
int			ft_treat_p(t_options tab, va_list ap, char *pr);
int			ft_treat_i(t_options tab, va_list ap, char *pr);
int			ft_treat_u(t_options tab, va_list ap, char *pr);
int			ft_treat_x(t_options tab, va_list ap, char *pr);
int			ft_treat_perc(t_options tab, va_list ap, char *pr);
int			ft_treat_xmaj(t_options tab, va_list ap, char *pr);
int			ft_treat_error(t_options tab, va_list ap, char *pr);
t_func		*ft_dispatch(t_options tab);

#endif
