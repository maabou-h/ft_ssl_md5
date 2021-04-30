/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:57:18 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/24 13:22:53 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_is_prefix(char c)
{
	if (c == '#' || c == '0' || c == '+' || c == '-' || c == ' ')
		return (1);
	else
		return (0);
}

size_t	ft_is_spec(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X' ||
			c == 'b' || c == 'c' || c == 's' || c == 'p' || c == 'f' ||
			c == '%')
		return (1);
	else
		return (0);
}

size_t	ft_interpretable(char const *format, int pos)
{
	size_t	j;

	j = 0;
	if (!format)
		exit(-1);
	while (!ft_is_spec(format[pos++]))
		j++;
	return (j);
}

int		ft_prefix(char spec)
{
	if (spec == '#')
		return (F_H);
	else if (spec == '0')
		return (F_Z);
	else if (spec == '-')
		return (F_M);
	else if (spec == '+')
		return (F_P);
	else if (spec == ' ')
		return (F_S);
	else
		return (0);
}

int		ft_modif(char c, char d, char e, int *i)
{
	if ((c == 'l' || c == 'h') && (ft_is_spec(d)))
	{
		*i += 1;
		return (c == 'l') ? (L_) : (H_);
	}
	else if ((c == 'j' || c == 'z') && (ft_is_spec(d)))
	{
		*i += 1;
		return (c == 'j') ? (J_) : (Z_);
	}
	else if (((c == 'l' && d == 'l') || (c == 'h' && d == 'h')) &&
			(ft_is_spec(e)))
	{
		*i += 2;
		return (c == 'l' && d == 'l') ? (LL_) : (HH_);
	}
	else
		return (0);
}
