/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:32:33 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/27 00:25:48 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_plusspace(t_pf *raw, long long n)
{
	int j;

	j = 0;
	(n < 0) ? j += ft_parser('-') : 0;
	(raw->fl & F_P && n >= 0) ? j += ft_parser('+') : 0;
	(raw->fl & F_S && n >= 0 && !(raw->fl & F_P)) ? j += ft_parser(' ') : 0;
	return (j);
}

int	ft_parse_before(t_pf *raw, long long n, int base)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = ((raw->fl & F_S || raw->fl & F_P) && n >= 0) ? 1 : 0;
	if (raw->fl & F_Z)
	{
		j += ft_plusspace(raw, n);
		(n < 0) ? n = -n : 0;
		while (raw->fi-- > ft_rawlen(n, base) + j)
			i += ft_parser('0');
	}
	else
	{
		while (raw->fi-- > ft_rawlen(n, base) + k)
			i += ft_parser(' ');
		j += ft_plusspace(raw, n);
		(n < 0) ? n = -n : 0;
	}
	j += ft_nbr_upp(n, base, raw, "0123456789");
	return (j + i);
}

int	ft_parse_between(t_pf *raw, long long n, int base)
{
	int i;
	int j;
	int len;
	int k;
	int z;

	i = 0;
	j = 0;
	k = (((raw->fl & F_P) && n >= 0) ||
			((raw->fl & F_S) && n >= 0) || (n < 0)) ? 1 : 0;
	len = ft_rawlenm(n, base) - (n == 0 && (raw->fl & P_A) && raw->pr == 0);
	z = (raw->pr > len) ? raw->pr : len;
	while (z++ < raw->fi - k)
		j += ft_parser(' ');
	j += ft_plusspace(raw, n);
	(n < 0) ? n = -n : 0;
	while (raw->pr-- > ft_rawlen(n, base))
		i += ft_parser('0');
	if (n == 0 && (raw->fl & P_A) && raw->pr == -1)
		return (j + i);
	j += ft_nbr_upp(n, base, raw, "0123456789");
	return (j + i);
}

int	ft_parse_after(t_pf *raw, long long n, int base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	(n < 0) ? j += ft_parser('-') : 0;
	(raw->fl & F_P && n >= 0) ? j += ft_parser('+') : 0;
	(raw->fl & F_S && n >= 0 && !(raw->fl & F_P)) ? j += ft_parser(' ') : 0;
	(n < 0) ? n = -n : 0;
	while (raw->pr-- > ft_rawlen(n, base))
		j += ft_parser('0');
	j += ft_nbr_upp(n, base, raw, "0123456789");
	while (raw->fi-- > j)
		i += ft_parser(' ');
	return (j + i);
}
