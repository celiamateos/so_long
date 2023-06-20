/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:05:22 by cmateos           #+#    #+#             */
/*   Updated: 2023/06/19 21:10:54 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	ft_puthex(unsigned int nbr, char *hex, int *count)
{
	if (nbr / 16 != 0)
		ft_puthex(nbr / 16, hex, count);
	nbr = nbr % 16;
	*count += write (1, &hex[nbr], 1);
	return (0);
}

int	ft_putptr_pf(unsigned long nbr, char *hex, int count)
{
	if (nbr < 16)
	{
		count += write(1, &hex[nbr], 1);
		count++;
	}
	else
	{
		count += ft_putptr_pf(nbr / 16, hex, count);
		nbr = nbr % 16;
		write(1, &hex[nbr], 1);
	}
	return (count);
}

int	ft_putun(unsigned int nbr, int *count)
{
	if (nbr / 10 != 0)
		ft_putun(nbr / 10, count);
	nbr = nbr % 10 + '0';
	*count += write (1, &nbr, 1);
	return (0);
}

int	ft_putnbr_pf(long nbr, int *count)
{
	if (nbr < 0)
	{
		*count += ft_putchr_pf('-');
		nbr = nbr * (-1);
	}
	if (nbr / 10 != 0)
		ft_putnbr_pf(nbr / 10, count);
	*count += ft_putchr_pf((nbr % 10) + '0');
	return (0);
}

int	ft_putstr_pf(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (s == NULL)
	count += (ft_putstr_pf("(null)"));
	if (s)
	{
		while (s[i] != '\0')
		{
			count += write(1, &s[i], 1);
			i++;
		}
	}
	return (count);
}
