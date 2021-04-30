/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:16:45 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/24 16:19:22 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialize_fmt(t_pf *raw)
{
	raw->fl = 0;
	raw->fi = 0;
	raw->pr = 0;
	raw->mod = 0;
	raw->id = '\0';
}

t_pf	ft_get_struct_info(const char *format, int i, t_pf *raw)
{
	ft_initialize_fmt(raw);
	while (ft_is_prefix(format[i]))
		raw->fl |= ft_prefix(format[i++]);
	if (format[i] >= '1' && format[i] <= '9')
		raw->fi = ft_atoi(format + i);
	i = (raw->fi) ? i + ft_rawlen(raw->fi, 10) : i;
	if (format[i] == '.')
	{
		i++;
		raw->fl += P_A;
		if (format[i] >= '0' && format[i] <= '9')
		{
			raw->pr = ft_atoi(&format[i]);
			i += ft_rawlen(raw->pr, 10);
		}
	}
	raw->mod = ft_modif(format[i], format[i + 1], format[i + 2], &i);
	raw->id = format[i];
	return (*raw);
}

int		ft_printf_wrapper(t_pf *raw, va_list ap)
{
	if (raw->id == 'c' || raw->id == 's' || raw->id == 'p' || raw->id == '%')
		return (ft_csp_case(raw, ap));
	else if (raw->id == 'd' || raw->id == 'i')
		return (ft_di_case(raw, ap));
	else if (raw->id == 'o' || raw->id == 'u')
		return (raw->id == 'o') ? ft_o_case(raw, ap) : ft_u_case(raw, ap);
	else if (raw->id == 'x' || raw->id == 'X')
		return (raw->id == 'x') ? ft_x_case(raw, ap) : ft_xu_case(raw, ap);
	else
		return (-1);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_pf	fmt;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_get_struct_info(format, i, &fmt);
			i += ft_interpretable(format, i) + 1;
			k = j;
			if (k > (j += ft_printf_wrapper(&fmt, ap)))
				return (-1);
		}
		else
			j += ft_parser(format[i++]);
	}
	va_end(ap);
	return (j);
}
