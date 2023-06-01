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
#include "../so_long.h"

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