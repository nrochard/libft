/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 22:26:50 by nrochard          #+#    #+#             */
/*   Updated: 2019/10/18 19:28:48 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (str[0] == '\0')
		return (NULL);
	if (!*str || !*to_find)
		return ((char *)str);
	if (len == 0)
		return (NULL);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		if (str[i] == to_find[0])
		{
			while (to_find[j] != '\0' && str[i + j] == to_find[j]
				&& (i + j) < len)
				j++;
		}
		if (to_find[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
