/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:11:13 by cmateos           #+#    #+#             */
/*   Updated: 2023/06/05 13:14:05 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	subs = malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	ft_memcpy(subs, &s[start], len);
	subs[len] = '\0';
	return (subs);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*destination;
	unsigned const char	*source;
	size_t				i;

	destination = dst;
	source = src;
	i = 0;
	if (dst != '\0' || src != '\0')
	{
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (dst);
}

int	ft_putchr_pf(char c)
{
	return (write(1, &c, 1));
}
