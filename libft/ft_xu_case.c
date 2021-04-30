/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xu_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:53:31 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/24 13:35:52 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_append_xu(uintmax_t n, int base, t_pf *raw)
{
	int j;

	j = 0;
	if (raw->fl & F_M)
		j += ft_parse_after_xu(raw, n, base);
	else if (!(raw->fl & P_A))
		j += ft_parse_before_xu(raw, n, base);
	else
		j += ft_parse_between_xu(raw, n, base);
	return (j);
}

int	ft_xu_case(t_pf *raw, va_list ap)
{
	if (raw->id == 'X' && !raw->mod)
		return (ft_append_xu((unsigned int)va_arg(ap, uintmax_t), 16, raw));
	else if (raw->id == 'X' && raw->mod & L_)
		return (ft_append_xu((unsigned long)va_arg(ap, uintmax_t), 16, raw));
	else if (raw->id == 'X' && raw->mod & H_)
		return (ft_append_xu((unsigned short)va_arg(ap, uintmax_t), 16, raw));
	else if (raw->id == 'X' && raw->mod & LL_)
		return (ft_append_xu(va_arg(ap, uintmax_t), 16, raw));
	else if (raw->id == 'X' && raw->mod & HH_)
		return (ft_append_xu((unsigned char)va_arg(ap, uintmax_t), 16, raw));
	else if (raw->id == 'X' && raw->mod & J_)
		return (ft_append_xu(va_arg(ap, uintmax_t), 16, raw));
	else if (raw->id == 'X' && raw->mod & Z_)
		return (ft_append_xu((size_t)va_arg(ap, uintmax_t), 16, raw));
	else
		return (-1);
}
