/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:53:31 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/24 13:23:25 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_append_o(uintmax_t n, int base, t_pf *raw)
{
	int j;

	j = 0;
	if (raw->fl & F_M)
		j += ft_parse_after_o(raw, n, base);
	else if (!(raw->fl & P_A))
		j += ft_parse_before_o(raw, n, base);
	else
		j += ft_parse_between_o(raw, n, base);
	return (j);
}

int		ft_o_case(t_pf *raw, va_list ap)
{
	if (raw->id == 'o' && !raw->mod)
		return (ft_append_o((unsigned int)va_arg(ap, uintmax_t), 8, raw));
	else if (raw->id == 'o' && raw->mod & L_)
		return (ft_append_o((unsigned long)va_arg(ap, uintmax_t), 8, raw));
	else if (raw->id == 'o' && raw->mod & H_)
		return (ft_append_o((unsigned short)va_arg(ap, uintmax_t), 8, raw));
	else if (raw->id == 'o' && raw->mod & LL_)
		return (ft_append_o(va_arg(ap, uintmax_t), 8, raw));
	else if (raw->id == 'o' && raw->mod & HH_)
		return (ft_append_o((unsigned char)va_arg(ap, uintmax_t), 8, raw));
	else if (raw->id == 'o' && raw->mod & J_)
		return (ft_append_o(va_arg(ap, uintmax_t), 8, raw));
	else if (raw->id == 'o' && raw->mod & Z_)
		return (ft_append_o((size_t)va_arg(ap, uintmax_t), 8, raw));
	else
		return (-1);
}
