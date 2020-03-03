/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabourad <kabourad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:25:49 by kabourad          #+#    #+#             */
/*   Updated: 2020/02/25 22:10:49 by kabourad         ###   ########.fr       */
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
	int		verif;
	char	conv;
}				t_options;

typedef	int	(t_func)(t_options, va_list*, char*);

//prototypes
int			ft_printf(const char *format, ...);
char		*ft_itoa_base(int n, int base);
int			ft_putchar_ret(char c);
int			ft_handler(char **tmp, va_list *ap);

t_options	ft_save_struct(char **tmp, va_list *ap);
void		ft_save_flag(char **tmp, t_options *stru);
int			ft_save_width(char **tmp, va_list *ap);
int			ft_save_precision(char **tmp, va_list *ap);


int			ft_treat_d(t_options tab, va_list *ap, char *pr);
int			ft_treat_c(t_options tab, va_list *ap, char *pr);
int			ft_treat_s(t_options tab, va_list *ap, char *pr); //char
int			ft_treat_p(t_options tab, va_list *ap, char *pr); //long long int 0x (before zeros)
int			ft_treat_i(t_options tab, va_list *ap, char *pr);//int 
int			ft_treat_u(t_options tab, va_list *ap, char *pr);//unsigned int
int			ft_treat_x(t_options tab, va_list *ap, char *pr);//unsigned int
int			ft_treat_perc(t_options tab, va_list *ap, char *pr); 
int			ft_treat_xmaj(t_options tab, va_list *ap, char *pr);
int			ft_treat_error(t_options tab, va_list *ap, char *pr);
t_func		*ft_dispatch(t_options tab);

//c
int			without_flagleft_c(char c, t_options tab);
int			with_flagleft_c(char c, t_options tab);
void		check_flags_c(t_options *tab);
int			compose_result_c(t_options tab, char c);

//s
void		check_flags_s(t_options *tab);
void		modify_pr_s(t_options *tab, char *c);
void		modify_wd_s(t_options *tab);
int			with_flagleft_s(char *c, t_options tab);
int			without_flagleft_s(char *c, t_options tab);
int			print_only_s(char *c, int b);
int			compose_result_s(t_options tab, char *c);

//d
void	check_flags_num(t_options *tab);
void	modify_pr_num(t_options *tab, char *num, int minus);
void	modify_wd_num(t_options *tab, char *num, int minus);
int		print_num(char *num, t_options tab, int minus);
int		compose_result_num(t_options tab, char *num, int minus);
int		with_flagleft_num(char *num, t_options tab, int minus);
int		without_flagleft_num(char *num, t_options tab, int minus);

//u
void	modify_pr_u(t_options *tab, char *num);
void	modify_wd_u(t_options *tab, char *num);
int		print_num_u(char *num, t_options tab);

//p
void	check_flags_p(t_options *tab);
void	modify_wd_p(t_options *tab, char *num);
void	modify_pr_p(t_options *tab, char *num);
int		print_p(char *num, t_options tab);
int		with_flagleft_p(char *num, t_options tab);
int		without_flagleft_p(char *num, t_options tab);
int		compose_result_p(t_options tab, char *num);
char	*ft_utoa(unsigned int n);
char	*ft_ulltoa_base(unsigned long long n, int base);
int		put_ox(void);

//x
char		*ft_utoa_base(unsigned int n, int base);
void	check_flags_x(t_options *tab);
void	modify_pr_x(t_options *tab, char *num);
void	modify_wd_x(t_options *tab, char *num);
int	print_num_x(char *num, t_options tab);
int	compose_result_x(t_options tab, char *num);
char		*ft_utoamaj_base(unsigned int n, int base);
int 	check_zero_n_print(char *num, t_options tab);
int 	check_zero_n_print_x(char *num, t_options tab);

#endif
