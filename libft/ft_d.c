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

int	ft_d(int d)
{
	int		i;
	char	*str;

	str = ft_itoa(d);
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	i = ft_strlen(str);
	free(str);
	return (i);
}
