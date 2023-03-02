/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ft_ strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguincha <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 08:55:28 by bguincha          #+#    #+#             */
/*   Updated: 2022/11/11 13:34:27 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*stri;
	int		len;

	stri = (char *)str;
	c = (char)c;
	len = ft_strlen(str);
	while (len >= 0)
	{
		if (stri[len] == c)
			return (&stri[len]);
		len--;
	}
	return (0);
}
