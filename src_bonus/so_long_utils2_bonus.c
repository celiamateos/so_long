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
#include "../so_long_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, (count * size));
	return (p);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

static int	ft_lennum(int n)
{
	int	digit;

	digit = 0;
	while (n > 9)
	{
		n = n / 10;
		digit++;
	}
	digit++;
	return (digit);
}

char	*ft_itoa(int n)
{
	char	*trans;
	int		i;
	
	i = ft_lennum(n);
	trans = (char *)malloc((i + 1) * sizeof(char));
	if (!trans)
		return (NULL);
	trans[i] = '\0';
	while (i > 0)
	{
		i--;
		trans[i] = (n % 10) + '0';
		n = n / 10;
	}
	return (trans);
}
