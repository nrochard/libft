/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 22:26:50 by nrochard          #+#    #+#             */
/*   Updated: 2019/10/19 14:03:53 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (s2 && s2[i] == '\0')
		return ((char *)s1);
	if (s2 && len == 0)
		return (NULL);
	while (s1[i] != '\0' && i < len)
	{
		j = 0;
		if (s1[i] == s2[0])
		{
			while (s2[j] != '\0' && s1[i + j] == s2[j]
				&& (i + j) < len)
				j++;
		}
		if (s2[j] == '\0')
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
