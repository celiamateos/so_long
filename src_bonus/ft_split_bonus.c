/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:10:29 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/13 20:47:09 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long_bonus.h"

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	ft_lenstring(char const *s, char c, int i)
{
	int	lenstr;

	lenstr = 0;
	while (s[i] != c && s[i] != '\0')
	{
		lenstr++;
		i++;
	}
	return (lenstr);
}

static int	ft_desmalokeo(char **arraystr, int row)
{
	int	i;

	i = 0;
	if (arraystr[row] == NULL)
	{
		while (i < row)
		{
			free(arraystr[i]);
			i++;
		}
		free(arraystr);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**arraystr;
	int		i;
	int		row;

	i = 0;
	row = 0;
	if (!s)
		return (NULL);
	arraystr = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!arraystr)
		return (NULL);
	while (row < ft_countwords(s, c))
	{
		if (s[i] != '\0' && s[i] != c)
		{
			arraystr[row] = ft_substr(s, i, ft_lenstring(s, c, i));
			if (ft_desmalokeo(arraystr, row++) == 1)
				return (NULL);
			i += ft_lenstring(s, c, i);
		}
		else
			i++;
	}
	arraystr[row] = NULL;
	return (arraystr);
}
/*
int	main(void)
{
	char	s [] = "     lu b ldsjñ l  ";
	char	c = ' ';
	ft_split(s, c);
	return(0);
}*/
