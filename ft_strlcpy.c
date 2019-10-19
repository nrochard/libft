/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 22:26:35 by nrochard          #+#    #+#             */
/*   Updated: 2019/10/19 12:01:26 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	a;
	unsigned int	b;
	size_t			c;

	a = 0;
	b = size - 1;
	if (dest == NULL || src == NULL)
		return (0);
	c = ft_strlen((char *)src);
	if (!dest || !src)
		return (0);
	while (src[a] != '\0' && a < b && size > 0)
	{
		dest[a] = src[a];
		a++;
	}
	if (size > 0)
		dest[a] = '\0';
	return (c);
}
