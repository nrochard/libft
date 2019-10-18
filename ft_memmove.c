/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:57:42 by nrochard          #+#    #+#             */
/*   Updated: 2019/10/13 18:29:55 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dest;
	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 < s2)
	{
		while (++i <= n)
			s2[n - i] = s1[n - i];
	}
	else
		while (n > 0)
		{
			s2[i] = s1[i];
			n--;
			i++;
		}
	return (s2);
}
