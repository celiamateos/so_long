/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:02:58 by cmateos-          #+#    #+#             */
/*   Updated: 2023/05/24 22:15:38 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	ft_variables(char c, va_list arg, int *count)
{
	if (c == 'c')
		return (ft_putchr_pf(va_arg(arg, int)));
	if (c == 's')
		return (ft_putstr_pf(va_arg(arg, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_pf(va_arg(arg, int), count));
	if (c == 'p')
	{
		write(1, "0x", 2);
		return (ft_putptr_pf(va_arg(arg, unsigned long),
				"0123456789abcdef", 1));
	}
	if (c == 'x')
		return (ft_puthex(va_arg(arg, unsigned int)
				, "0123456789abcdef", count));
	if (c == 'X')
		return (ft_puthex(va_arg(arg, unsigned int)
				, "0123456789ABCDEF", count));
	if (c == '%')
		return (ft_putchr_pf('%'));
	if (c == 'u')
		return (ft_putun(va_arg(arg, unsigned int), count));
	return (0);
}

int	ft_printf(char const *s, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arg, s);
	if (s)
	{
		while (s[i])
		{
			if (s[i] == '%')
			{
				i++;
				if (s[i] == '\0')
					return (0);
				count += ft_variables(s[i], arg, &count);
			}
			else
				count += write(1, &s[i], 1);
			i++;
		}
	}
	va_end(arg);
	return (count);
}
