/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguincha <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:26:10 by bguincha          #+#    #+#             */
/*   Updated: 2022/10/28 10:27:23 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*desti;
	char	*srci;

	i = 0;
	desti = (char *)dest;
	srci = (char *)src;
	if (!desti && !srci)
	{
		return (0);
	}
	while (i < n)
	{
		desti[i] = srci[i];
		i++;
	}
	return (dest);
}
