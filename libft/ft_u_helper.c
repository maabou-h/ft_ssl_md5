/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:32:33 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/27 00:57:01 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_before_u(t_pf *raw, uintmax_t n, int base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (raw->fl & F_Z)
	{
		while (raw->fi-- > ft_pflen(n, base) + j)
			i += ft_parser('0');
	}
	else
	{
		while (raw->fi-- > ft_pflen(n, base))
			i += ft_parser(' ');
	}
	j += ft_nbr_uns(n, base, raw, "0123456789");
	return (j + i);
}

int	ft_parse_between_u(t_pf *raw, uintmax_t n, int base)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = (raw->pr > ft_pflen(n, base)) ? raw->fi - raw->pr : raw->fi
		- ft_rawlen(n, base);
	if (k < 0)
		k = 0;
	while (k--)
		j += ft_parser(' ');
	while (raw->pr-- > ft_pflen(n, base))
		i += ft_parser('0');
	if (n == 0 && raw->pr == -1 && (raw->fl & P_A))
		return (j + i);
	j += ft_nbr_uns(n, base, raw, "0123456789");
	return (j + i);
}

int	ft_parse_after_u(t_pf *raw, uintmax_t n, int base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (raw->fl & P_A)
	{
		while (raw->pr-- > ft_pflen(n, base))
			j += ft_parser('0');
	}
	j += ft_nbr_uns(n, base, raw, "0123456789");
	while (raw->fi-- > j)
		i += ft_parser(' ');
	return (j + i);
}
