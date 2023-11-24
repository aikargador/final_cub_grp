/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:56:24 by aikram            #+#    #+#             */
/*   Updated: 2023/11/20 21:08:41 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *main_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!main_str[i])
		return (NULL);
	while (main_str[i] && main_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (main_str[i] && main_str[i] != '\n')
	{
		str[i] = main_str[i];
		i++;
	}
	if (main_str[i] == '\n')
	{
		str[i] = main_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_main_str(char *main_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (main_str[i] && main_str[i] != '\n')
		i++;
	if (!main_str[i])
	{
		free (main_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(main_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (main_str[i])
		str[j++] = main_str[i++];
	str[j] = '\0';
	free(main_str);
	return (str);
}
