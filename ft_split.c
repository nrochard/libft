/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrochard <nrochard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:17:57 by nrochard          #+#    #+#             */
/*   Updated: 2019/10/18 19:55:02 by nrochard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**malloc_line_ft_split(char const *str, char c, char **tab)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c && j > 0)
		{
			if ((tab[k] = malloc(sizeof(char) * (j + 1))) == 0)
				return (NULL);
			j = 0;
			k++;
		}
		else if (str[i] != c)
			j++;
		i++;
	}
	if ((tab[k] = malloc(sizeof(char) * (j + 1))) == 0)
		return (NULL);
	return (tab);
}

static char	**malloc_ft_split(char const *str, char c, int i, int k)
{
	char	**tab;

	while (str[i] != '\0')
	{
		if (str[i] == c)
			k++;
		i++;
	}
	if ((tab = malloc(sizeof(char *) * (k + 2))) == 0)
	{
		free(tab);
		return (NULL);
	}
	if ((tab = malloc_line_ft_split(str, c, tab)) == NULL)
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}

static char	**fill_ft_split(char const *str, char c, char **tab, int i)
{
	int	k;
	int x;

	k = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c && x > 0)
		{
			tab[k][x] = '\0';
			x = 0;
			k++;
		}
		else if (str[i] != c)
			tab[k][x++] = str[i];
		i++;
	}
	if (x > 0)
		tab[k][x] = '\0';
	else
		tab[k] = NULL;
	tab[k + 1] = NULL;
	return (tab);
}

char		**ft_split(char const *str, char c)
{
	char	**tab;

	if (str == NULL)
		return (NULL);
	if ((tab = malloc_ft_split(str, c, 0, 0)) == NULL)
		return (NULL);
	tab = fill_ft_split(str, c, tab, 0);
	return (tab);
}
