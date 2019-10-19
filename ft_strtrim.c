/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:46:36 by nrochard          #+#    #+#             */
/*   Updated: 2019/10/19 15:53:03 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*fill_string(char const *s1, char const *set, char *r, int size)
{
	int i;
	int j;
	int k;

	i = -1;
	k = 0;
	while (s1[++i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (s1[i] != set[j])
		{
			r[k] = s1[i];
			break ;
		}
	}
	while (k < size)
		r[k++] = s1[i++];
	r[k] = '\0';
	return (r);
}

int			decrement(char const *set, char cmp, int size)
{
	int j;

	j = 0;
	while (set[j] != '\0')
	{
		if (cmp == set[j])
			size--;
		j++;
	}
	return (size);
}

int			malloc_len(char const *s1, char const *set)
{
	int	size;
	int i;
	int j;
	int c;

	size = ft_strlen(s1);
	i = 0;
	c = 0;
	while (s1[i] != '\0' && c != size)
	{
		j = 0;
		c = size;
		size = decrement(set, s1[i], size);
		i++;
	}
	i = ft_strlen(s1) - 1;
	c = 0;
	while (i >= 0 && c != size)
	{
		j = 0;
		c = size;
		size = decrement(set, s1[i], size);
		i--;
	}
	return (size);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*r;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[i++] != '\0' && set[j++] != '\0')
	{
		if (s1[i] == set[j])
			return (ft_strdup("\0"));
	}
	size = malloc_len(s1, set);
	if (!(r = malloc(sizeof(char) * size + 1)))
		return (NULL);
	r = fill_string(s1, set, r, size);
	return (r);
}
