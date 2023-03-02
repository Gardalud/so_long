/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguincha <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:59:42 by bguincha          #+#    #+#             */
/*   Updated: 2022/11/10 14:30:01 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_i(int i)
{
	int		x;
	char	*str;

	str = ft_itoa(i);
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	x = ft_strlen(str);
	free(str);
	return (x);
}
