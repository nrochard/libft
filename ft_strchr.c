/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:48:54 by nrochard          #+#    #+#             */
/*   Updated: 2019/10/13 18:30:16 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *)s;
	while (s2[i] != '\0')
	{
		if (s2[i] == c)
			return (&s2[i]);
		i++;
	}
	if (s2[i] == '\0' && (unsigned char)c != '\0')
		return (NULL);
	return (&s2[i]);
}
