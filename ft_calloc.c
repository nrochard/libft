/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:37:51 by nrochard          #+#    #+#             */
/*   Updated: 2019/10/18 18:59:42 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbr, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (nbr == 0)
		nbr++;
	if (size == 0)
		size++;
	if (!(str = malloc(sizeof(char) * (nbr * size))))
		return (NULL);
	while (i < (nbr * size))
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}
