/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:16:40 by cmateos-          #+#    #+#             */
/*   Updated: 2023/05/15 17:36:16 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

char	*auxupdater(char *aux)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	j = 0;
	temp = malloc((ft_strlen(aux) + 1) * sizeof(char));
	if (!temp)
		return (free(aux), NULL);
	while (aux[i] != '\0')
		temp[i++] = aux[j++];
	temp[i] = '\0';
	free(aux);
	j = 0;
	while (temp[j] != '\n' && temp[j])
		j++;
	if (temp[j] == '\n')
		j++;
	aux = malloc(sizeof(char) * (i - j + 1));
	if (!aux)
		return (free(temp), NULL);
	i = 0;
	while (temp[j])
		aux[i++] = temp[j++];
	return (aux[i] = '\0', free(temp), aux);
}

char	*save_line(char *aux)
{
	size_t	i;
	char	*line;

	i = 0;
	while (aux[i] != '\n' && aux[i])
		i++;
	if (aux[i] == '\n')
		i++;
	line = malloc(i + 1 * sizeof(char));
	if (!line)
		return (free(aux), NULL);
	i = 0;
	while (aux[i] != '\0')
	{
		if (aux[i] != '\n')
			line[i] = aux[i];
		if (aux[i] == '\n')
		{
			line[i++] = '\n';
			line[i] = '\0';
			return (line);
		}
		i++;
	}
	return (line[i] = '\0', line);
}

char	*read_line(int fd, char *aux)
{
	char	*buffer;
	int		i;

	i = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(aux), NULL);
	while (i > 0 && !ft_strchr(aux, '\n'))
	{		
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(aux);
			free(buffer);
			aux = NULL;
			buffer = NULL;
			return (NULL);
		}
		buffer[i] = '\0';
		aux = ft_strjoin_gnl(aux, buffer);
	}
	free(buffer);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*aux;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{	
		free(aux);
		aux = 0;
		return (0);
	}
	if (!ft_strchr(aux, '\n'))
		aux = read_line(fd, aux);
	if (aux[0] == '\0' || aux == NULL)
	{
		free(aux);
		aux = NULL;
		return (NULL);
	}
	line = save_line(aux);
	aux = auxupdater(aux);
	return (line);
}
