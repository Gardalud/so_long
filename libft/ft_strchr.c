/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguincha <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:57:57 by bguincha          #+#    #+#             */
/*   Updated: 2022/11/11 13:26:13 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((char)c == str[i])
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if ((char)c == str[i])
	{
		return ((char *)&str[i]);
	}
	return (0);
}
