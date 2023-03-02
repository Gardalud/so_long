/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguincha <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:53:51 by bguincha          #+#    #+#             */
/*   Updated: 2022/11/10 15:14:16 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	longueur(int nbr)
{
	int	len;
	int	i;

	i = nbr;
	len = 0;
	while (i >= 0)
	{
		i = i / 10;
		len++;
		if (i == 0)
			break ;
	}
	return (len);
}

char	*result(char *resultat, int nbr, int len, int n)
{
	int	k;

	k = len - 1;
	if (n == 1)
		k++;
	while (k >= 0)
	{
		resultat[k] = nbr % 10 + '0';
		nbr = nbr / 10;
		k--;
	}
	if (n == 1)
		resultat[0] = '-';
	resultat[len + n] = '\0';
	return (resultat);
}

char	*ft_itoa(int nbr)
{
	char	*resultat;
	int		len;
	int		n;

	n = 0;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nbr < 0)
	{
		n = 1;
		nbr *= -1;
	}
	len = longueur(nbr);
	resultat = malloc(sizeof(char) * (len + n + 1));
	if (!resultat)
		return (NULL);
	return (result(resultat, nbr, len, n));
}
