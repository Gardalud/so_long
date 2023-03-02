/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguincha <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:53:51 by bguincha          #+#    #+#             */
/*   Updated: 2022/11/10 15:14:16 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexadecimal(unsigned long long nbr)
{
	int	i;

	i = 0;
	if (nbr >= 16)
	{
		i += ft_hexadecimal(nbr / 16);
		i += ft_hexadecimal(nbr % 16);
	}
	if (nbr < 16)
	{
		if (nbr <= 9)
			ft_putchar_fd(nbr + '0', 1);
		else
			ft_putchar_fd((nbr - 10) + 'a', 1);
		i++;
	}
	return (i);
}
