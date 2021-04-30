/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:53:31 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/25 19:27:20 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_append_di(long long int n, int base, t_pf *raw)
{
	int j;

	j = 0;
	if (raw->fl & F_M)
		j += ft_parse_after(raw, n, base);
	else if (!(raw->fl & P_A))
		j += ft_parse_before(raw, n, base);
	else
		j += ft_parse_between(raw, n, base);
	return (j);
}

int		ft_di_case(t_pf *raw, va_list ap)
{
	if ((raw->id == 'd' || raw->id == 'i') && !raw->mod)
		return (ft_append_di((int)va_arg(ap, intmax_t), 10, raw));
	else if ((raw->id == 'd' || raw->id == 'i') && raw->mod & L_)
		return (ft_append_di((long)va_arg(ap, intmax_t), 10, raw));
	else if ((raw->id == 'd' || raw->id == 'i') && raw->mod & H_)
		return (ft_append_di((short)va_arg(ap, intmax_t), 10, raw));
	else if ((raw->id == 'd' || raw->id == 'i') && raw->mod & LL_)
		return (ft_append_di((long long)va_arg(ap, intmax_t), 10, raw));
	else if ((raw->id == 'd' || raw->id == 'i') && raw->mod & HH_)
		return (ft_append_di((char)va_arg(ap, intmax_t), 10, raw));
	else if ((raw->id == 'd' || raw->id == 'i') && raw->mod & J_)
		return (ft_append_di(va_arg(ap, intmax_t), 10, raw));
	else if ((raw->id == 'd' || raw->id == 'i') && raw->mod & Z_)
		return (ft_append_di((ssize_t)va_arg(ap, intmax_t), 10, raw));
	else
		return (-1);
}
