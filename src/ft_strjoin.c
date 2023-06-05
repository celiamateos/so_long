/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:33:46 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/06 22:26:24 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
/*
int	main(void)
{
	char	s1 [] = "Esto es una secta ";
	char	s2 [] = "de cajas";
	char	*result;

	result = ft_strjoin(s1, s2);
	printf("%s", result);
	return (0);
}*/
