/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:02:57 by nrochard          #+#    #+#             */
/*   Updated: 2019/10/18 19:59:45 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[count] != '\0')
		count++;
	while (count >= 0)
	{
		if (s[count] == c)
		{
			i = 1;
			break ;
		}
		count--;
	}
	if (count <= 0 && i == 0)
		return (NULL);
	return ((char *)&s[count]);
}
