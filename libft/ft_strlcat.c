/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguincha <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:53:49 by bguincha          #+#    #+#             */
/*   Updated: 2022/11/11 13:25:27 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	i;
	size_t	r;
	char	*srci;

	i = 0;
	r = 0;
	srci = (char *)src;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(srci);
	if (size > lendst)
		r = lendst + lensrc;
	else
		r = lensrc + size;
	while (srci[i] != '\0' && (lendst + 1) < size)
	{
		dst[lendst] = srci[i];
		lendst++;
		i++;
	}
	dst[lendst] = '\0';
	return (r);
}
