/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:32:33 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/24 19:12:31 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_before_p(t_pf *raw, intmax_t n, int base)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = (raw->fl & P_A) ? 1 : 0;
	if (raw->fl & F_Z)
	{
		j += ft_parser('0');
		j += ft_parser('x');
		while (raw->fi-- > ft_rawlen(n, base) + j)
			i += ft_parser('0');
	}
	else
	{
		while (raw->fi-- > ft_rawlen(n, base) + k + 2 -
				(n == 0 && (raw->fl & P_A) && raw->pr == -1))
			i += ft_parser(' ');
		j += ft_parser('0');
		j += ft_parser('x');
	}
	j += ft_nbr_uns(n, base, raw, "0123456789abcdef");
	return (j + i);
}

int	ft_parse_between_p(t_pf *raw, intmax_t n, int base)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = (raw->pr > ft_intlen(n, base)) ? raw->fi - raw->pr : raw->fi -
		ft_intlen(n, base);
	if (k < 0)
		k = 0;
	while (k-- > 2)
		j += ft_parser(' ');
	j += ft_parser('0');
	j += ft_parser('x');
	while (raw->pr-- > ft_rawlen(n, base))
		i += ft_parser('0');
	j += ft_nbr_uns(n, base, raw, "0123456789abcdef");
	return (j + i);
}

int	ft_parse_after_p(t_pf *raw, long long n, int base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	j += ft_parser('0');
	j += ft_parser('x');
	while (raw->pr-- > ft_rawlen(n, base))
		j += ft_parser('0');
	j += ft_nbr_uns(n, base, raw, "0123456789abcdef");
	while (raw->fi-- > j - (n == 0 && (raw->fl & P_A) && raw->pr == -1))
		i += ft_parser(' ');
	return (j + i);
}

int	ft_append_p(uintmax_t n, int base, t_pf *raw)
{
	int j;

	j = 0;
	if (raw->fl & F_M)
		j += ft_parse_after_p(raw, n, base);
	else if (!(raw->fl & P_A))
		j += ft_parse_before_p(raw, n, base);
	else
		j += ft_parse_between_p(raw, n, base);
	return (j);
}
