cmake_minimum_required(VERSION 3.15)
project(printf C)

set(CMAKE_C_STANDARD 99)

add_executable(printf  ft_printf.c
        ft_treat_c_tools.c
        ft_treat_num_tools.c
        ft_treat_u_tools.c
        ft_treat_x_tools.c
        ft_treat_p_tools.c
        ft_handler.c
        ft_save.c
        ft_treat_c.c
        ft_treat_s_tools.c
        ft_itoa_base.c
        ft_utoa.c
        ft_utoa_base.c
        ft_utoamaj_base.c
        ft_ulltoa_base.c
        ft_putchar_ret.c
        ft_treat_s.c
        ft_treat_p.c
        ft_treat_error.c
        check_zero_n_print.c
        ft_treat_perc.c
        ft_treat_x.c
        ft_treat_xmaj.c
        ft_treat_d.c
        ft_treat_u.c
        libft/ft_isalnum.c
        libft/ft_atoi.c
        libft/ft_isalpha.c
        libft/ft_calloc.c
        libft/ft_isascii.c
        libft/ft_bzero.c
        libft/ft_isdigit.c
        libft/ft_itoa.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_putchar_fd.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr_fd.c
        libft/ft_split.c
        libft/ft_strchr.c
        libft/ft_strdup.c
        libft/ft_strjoin.c
        libft/ft_strncmp.c
        libft/ft_strlcat.c
        libft/ft_strlen.c
        libft/ft_substr.c
        libft/ft_strlcpy.c
        libft/ft_strmapi.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_isprint.c
        libft/ft_strtrim.c ft_printf.h)