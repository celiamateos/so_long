/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:48:53 by cmateos           #+#    #+#             */
/*   Updated: 2023/06/05 16:48:56 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
	dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	id;
	size_t	is;
	size_t	len;

	len = ft_strlen(dst);
	id = 0;
	is = 0;
	while (dst[id] != '\0')
			id++;
	if (dstsize != 0 && dstsize >= len)
	{
		while (src[is] && is + 1 < dstsize - len)
		{
			dst[id] = src[is];
			id++;
			is++;
		}
		dst[id] = '\0';
		return (len + ft_strlen(src));
	}	
	else
		return (dstsize + ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*caja;
	size_t	len1y2;

	len1y2 = ft_strlen(s1) + ft_strlen(s2) + 1;
	caja = malloc((len1y2) * sizeof(char));
	if (!caja)
		return (NULL);
	ft_strlcpy((char *)caja, s1, len1y2);
	ft_strlcat((char *)caja, s2, len1y2);
	caja[len1y2 - 1] = '\0';
	return (caja);
}