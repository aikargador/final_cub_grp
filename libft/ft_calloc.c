/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:31:07 by aikram            #+#    #+#             */
/*   Updated: 2023/11/19 22:31:08 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb >= 65535 && size >= 65535)
		return (NULL);
	result = malloc(nmemb * size);
	if (!result)
		return (0);
	ft_bzero(result, (nmemb * size));
	return (result);
}
