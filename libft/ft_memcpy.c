/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:32:58 by aikram            #+#    #+#             */
/*   Updated: 2023/11/19 22:32:59 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	unsigned int	i;
	int				dest_len;

	if (dest == NULL && src == NULL )
		return (0);
	dest_len = 0;
	if (!dest)
		dest_len = ft_strlen(dest);
	i = 0;
	while (n--)
	{
		((unsigned char *)dest)[dest_len + i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
