/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:53:43 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/27 00:36:59 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <wchar.h>
# include <unistd.h>
# include <float.h>
# include <stdlib.h>
# include <stdarg.h>

# define F_H 2
# define F_Z 4
# define F_M 8
# define F_P 16
# define F_S 32
# define P_A 64

# define L_ 2
# define H_ 4
# define LL_ 8
# define HH_ 16
# define J_ 32
# define Z_ 64

typedef struct	s_pf
{
	int			fl;
	int			fi;
	int			pr;
	int			mod;
	char		id;
}				t_pf;

int				ft_rawlenm(intmax_t nbr, int base);
size_t			ft_strlen(const char *s);
int				ft_putchar(unsigned char c, t_pf *raw);
int				ft_putstr(char const *s, t_pf *raw);
int				ft_csp_case(t_pf *raw, va_list ap);
int				ft_append_di(long long int n, int base, t_pf *raw);
int				ft_di_case(t_pf *raw, va_list ap);
int				ft_free_pf(t_pf *tmp);
int				ft_plusspace(t_pf *raw, long long n);
int				ft_parse_before(t_pf *raw, long long n, int base);
int				ft_parse_between(t_pf *raw, long long n, int base);
int				ft_parse_after(t_pf *raw, long long n, int base);
size_t			ft_is_prefix(char c);
size_t			ft_is_spec(char c);
size_t			ft_interpretable(char const *format, int pos);
int				ft_prefix(char spec);
int				ft_modif(char c, char d, char e, int *i);
int				ft_append_o(uintmax_t n, int base, t_pf *raw);
int				ft_o_case(t_pf *raw, va_list ap);
int				ft_parse_before_o(t_pf *raw, uintmax_t n, int base);
int				ft_parse_between_o(t_pf *raw, uintmax_t n, int base);
int				ft_parse_after_o(t_pf *raw, uintmax_t n, int base);
int				ft_parse_before_p(t_pf *raw, intmax_t n, int base);
int				ft_parse_between_p(t_pf *raw, intmax_t n, int base);
int				ft_parse_after_p(t_pf *raw, long long n, int base);
int				ft_append_p(uintmax_t n, int base, t_pf *raw);
void			ft_initialize_fmt(t_pf *raw);
t_pf			ft_get_struct_info(const char *format, int i, t_pf *raw);
int				ft_printf_wrapper(t_pf *raw, va_list ap);
int				ft_printf(const char *format, ...);
int				ft_intlen(intmax_t nbr, int base);
int				ft_rawlen(intmax_t nbr, int base);
int				ft_pflen(uintmax_t nbr, int base);
int				ft_parser(char c);
int				ft_atoi(const char *str);
int				ft_nbr_upp(intmax_t n, int base, t_pf *raw, char *radix);
int				ft_nbr_uns(uintmax_t n, int base, t_pf *raw, char *radix);
int				ft_append_u(uintmax_t n, int base, t_pf *raw);
int				ft_u_case(t_pf *raw, va_list ap);
int				ft_parse_before_u(t_pf *raw, uintmax_t n, int base);
int				ft_parse_between_u(t_pf *raw, uintmax_t n, int base);
int				ft_parse_after_u(t_pf *raw, uintmax_t n, int base);
int				ft_append_x(uintmax_t n, int base, t_pf *raw);
int				ft_x_case(t_pf *raw, va_list ap);
int				ft_parse_before_x(t_pf *raw, uintmax_t n, int base);
int				ft_parse_between_x(t_pf *raw, uintmax_t n, int base);
int				ft_parse_after_x(t_pf *raw, uintmax_t n, int base);
int				ft_append_xu(uintmax_t n, int base, t_pf *raw);
int				ft_xu_case(t_pf *raw, va_list ap);
int				ft_parse_before_xu(t_pf *raw, uintmax_t n, int base);
int				ft_parse_between_xu(t_pf *raw, uintmax_t n, int base);
int				ft_parse_after_xu(t_pf *raw, uintmax_t n, int base);

#endif
