/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:25:49 by kabourad          #+#    #+#             */
/*   Updated: 2019/12/04 16:07:10 by kabourad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//includes
# include "libft/libft.h"
# include <stdarg.h>

//structs

typedef	struct	s_options
{
	int		flagleft; //1 or 0
	int		flagzero; //1 or 0
	int		width;
	int		precision;
	char	type;
}				t_options;

//prototypes
int			ft_printf(const char *format, ...);
int			ft_flags(char **fmt);
t_options	*ft_options(void);

#endif