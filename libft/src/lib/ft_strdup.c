/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:04:10 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/02 12:16:33 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	str_size;
	void	*ptr;
	void	*result;

	if (!s1)
		return (NULL);
	str_size = ft_strlen(s1);
	ptr = malloc(str_size + 1);
	if (ptr == NULL)
		return (NULL);
	result = ft_memcpy(ptr, s1, str_size + 1);
	return ((char *)result);
}
