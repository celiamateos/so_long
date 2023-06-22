/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:46:41 by cmateos-          #+#    #+#             */
/*   Updated: 2023/05/15 17:31:51 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long_bonus.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
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

char	*ft_strjoin_gnl(char *aux, char *buffer)
{
	char	*caja;
	size_t	i;
	size_t	j;

	caja = malloc((ft_strlen(aux) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!caja)
		return (free(buffer), NULL);
	i = 0;
	j = 0;
	if (aux && aux[0] != '\0')
	{
		while (aux[i] != '\0')
			caja[i++] = aux[j++];
	}
	j = 0;
	if (buffer)
	{
		while (buffer[j])
			caja[i++] = buffer[j++];
		caja[i] = '\0';
	}
	if (buffer == NULL)
		return (free(caja), NULL);
	return (free(aux), aux = NULL, caja);
}
