/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:00:14 by eparisot          #+#    #+#             */
/*   Updated: 2017/11/20 21:18:53 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	pos;

	if (!s1 && !s2)
		return (NULL);
	if (!(new = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	pos = 0;
	while (s1[i] != '\0')
		new[pos++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		new[pos++] = s2[i++];
	new[pos] = '\0';
	return (new);
}