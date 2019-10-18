/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 23:14:18 by nrochard          #+#    #+#             */
/*   Updated: 2019/10/17 20:53:58 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	tmp_c;
	size_t			i;

	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dest;
	tmp_c = (unsigned char)c;
	i = 0;
	while (i < n && s1[i] != tmp_c)
	{
		s2[i] = s1[i];
		i++;
	}
	if (i == n)
		return (NULL);
	s2[i] = s1[i];
	return (&s2[i + 1]);
}
