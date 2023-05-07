/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguincha <bguincha@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:18:18 by bguincha          #+#    #+#             */
/*   Updated: 2023/02/28 18:18:18 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arbre(char c, va_list valist)
{
	int	res;

	res = 0;
	if (c == 'c')
		res += ft_c(va_arg(valist, int));
	if (c == 's')
		res += ft_s(va_arg(valist, char *));
	if (c == 'p')
		res += ft_p(va_arg(valist, unsigned long long));
	if (c == 'd')
		res += ft_d(va_arg(valist, int));
	if (c == 'i')
		res += ft_i(va_arg(valist, int));
	if (c == 'u')
		res += ft_u(va_arg(valist, unsigned int));
	if (c == 'x')
		res += ft_x(va_arg(valist, unsigned int));
	if (c == 'X')
		res += ft_xmaj(va_arg(valist, unsigned int));
	if (c == '%')
	{
		ft_putchar_fd(c, 1);
		res++;
	}
	return (res);
}

int	ft_printf(const char *drop, ...)
{
	va_list	valist;
	int		i;
	int		res;

	i = 0;
	res = 0;
	va_start(valist, drop);
	while (drop[i] != '\0')
	{
		if (drop[i] == '%')
		{
			i++;
			res += ft_arbre(drop[i], valist);
			i++;
		}
		else
		{
			ft_putchar_fd(drop[i], 1);
			i++;
			res++;
		}
	}
	va_end(valist);
	return (res);
}
