/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:36:12 by ajafy             #+#    #+#             */
/*   Updated: 2022/07/01 19:17:18 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_compteur(char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] && (s[i] == c))
		i++;
	while (s[i] != '\0')
	{
		j = i;
		while (s[j] != c && s[j] != '\0')
		{
			if (s[j + 1] == c || s[j + 1] == '\0')
				k++;
			j++;
			i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (k);
}

static char	**ft_freetab(char **p, int tab)
{
	int	i;

	i = 0;
	while (i <= tab)
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

static int	ft_iter(char const *s, int i, int j)
{
	if (s[j] == '\0')
		i = j;
	else
		i = j + 1;
	return (i);
}

static char	**ft_remp(char **p, char const *s, char c)
{
	int	i;
	int	j;
	int	tab;

	i = 0;
	tab = 0;
	while (s[i] && (s[i] == c))
		i++;
	while (*(s + i) != '\0')
	{
		j = i;
		while (s[j] != c && s[j] != '\0')
			j++;
		if (s[i] != c)
		{
			p[tab] = ft_substr(s, i, j - i);
			if (!p[tab])
				return (ft_freetab(p, tab));
			tab++;
		}
		i = ft_iter(s, i, j);
	}
	p[tab] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	p = (char **)malloc((ft_compteur(s, c) + 1) * sizeof(char *));
	if (!p)
	{
		free(p);
		return (NULL);
	}
	if (ft_remp(p, s, c) == NULL)
		return (NULL);
	return (p);
}
