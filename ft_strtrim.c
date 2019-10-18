/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:46:36 by nrochard          #+#    #+#             */
/*   Updated: 2019/10/18 19:51:19 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check_left(char const *s1, char const *set, char *new, int j)
{
	int k;
	int i;

	i = 0;
	k = 0;
	while (s1[i] != '\0')
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
			new[k] = s1[i];
			break ;
		}
		i++;
	}
	while (s1[i++] != '\0')
		new[++k] = s1[i];
	new[k] = '\0';
	return (new);
}

char	*check_right(char *final, char const *set, char *new, int len)
{
	int j;
	int k;
	int max;

	k = 0;
	while (len-- > 0)
	{
		j = -1;
		while (set[++j] != '\0')
			if (new[len] == set[j])
				break ;
		if (new[len] != set[j])
		{
			max = len;
			len = 0;
			while (len <= max)
				final[k++] = new[len++];
			final[k] = '\0';
			break ;
		}
	}
	final[k] = '\0';
	return (final);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		j;
	int		len;
	char	*new;
	char	*final;

	j = 0;
	len = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[len] != '\0')
		len++;
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new = check_left(s1, set, new, j);
	len = 0;
	while (new[len] != '\0')
		len++;
	if (!(final = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	final = check_right(final, set, new, len);
	return (final);
}
