/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 14:49:18 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/17 22:03:28 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sp;

	if (!s)
		return (NULL);
	sp = (unsigned char *)s;
	while (n > 0)
	{
		if (*sp == (unsigned char)c)
			return ((void *)sp);
		sp++;
		n--;
	}
	return (NULL);
}
