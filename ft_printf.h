/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:25:49 by kabourad          #+#    #+#             */
/*   Updated: 2020/01/18 20:22:27 by kabourad         ###   ########.fr       */
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
	char	conv;
}				t_options;


typedef	enum	e_index
{
	CH, STR, PTR, DEC, INTE, UNS, XSMALL, XBIG, PRCNT
}				t_index;

//prototypes
int			ft_printf(const char *format, ...);
char		*ft_itoa_base(int n, int base);
int			ft_putchar_ret(char c);
int     	ft_handler(char **tmp, va_list ap);
int			ft_treat_d(t_options option, va_list ap, char **res);
int			ft_treat_c(t_options option, va_list ap, char **res);
int			ft_treat_s(t_options option, va_list ap, char **res);
int			ft_treat_p(t_options option, va_list ap, char **res);
int			ft_treat_i(t_options option, va_list ap, char **res);
int			ft_treat_u(t_options option, va_list ap, char **res);
int			ft_treat_x(t_options option, va_list ap, char **res);
int			ft_treat_perc(t_options option, va_list ap, char **res);
int			ft_treat_xmaj(t_options option, va_list ap, char **res);

#endif
