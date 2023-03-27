/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschaefe <bguincha@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:18:18 by bguincha          #+#    #+#             */
/*   Updated: 2023/02/27 18:18:18 by bguincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//trouver si la sortie est bloquêe
int	ft_algo_find_e(char *map_readed_end)
{
	int	x;
	int	i;

	i = 0;
	x = ft_size_line(map_readed_end);
	while (map_readed_end[i] != '\0')
	{
		if (map_readed_end[i] == 'P')
			map_readed_end[i] = 'X';
		if (map_readed_end[i] == 'X')
		{
			if (map_readed_end[i - x] == 'E' || map_readed_end[i + x] == 'E')
				return (1);
			if (map_readed_end[i + 1] == 'E' || map_readed_end[i - 1] == 'E')
				return (1);
			if (map_readed_end[i + 1] == 'C' || map_readed_end[i + 1] == '0')
			{
				ft_algo_find_x(map_readed_end);
				ft_algo_find_x_reverse(map_readed_end);
				i = 0;
			}
		}
		i++;
	}
	return (0);
}

//trouver le P pour le mettre en X et commencer a changer en x ++
int	ft_algo_find_x(char *map_readed_end)
{
	int	i;

	i = 0;
	while (map_readed_end[i] != '\0')
	{
		if (map_readed_end[i] == 'X')
			ft_algo_put_x(map_readed_end, i);
		i++;
	}
	return (0);
}

//commencer a changer en x --
int	ft_algo_find_x_reverse(char *map_readed_end)
{
	int	i;

	i = ft_strlen(map_readed_end);
	while (i >= 0)
	{
		if (map_readed_end[i] == 'X')
			ft_algo_put_x(map_readed_end, i);
		i--;
	}
	return (0);
}

//remplacer le C et le 0 en x
void	ft_algo_put_x(char *map_readed_end, int i)
{
	int	x;

	x = ft_size_line(map_readed_end);
	if (map_readed_end[i - x] == 'C' || map_readed_end[i - x] == '0')
		map_readed_end[i - x] = 'X';
	if (map_readed_end[i + x] == 'C' || map_readed_end[i + x] == '0')
		map_readed_end[i + x] = 'X';
	if (map_readed_end[i + 1] == 'C' || map_readed_end[i + 1] == '0')
		map_readed_end[i + 1] = 'X';
	if (map_readed_end[i - 1] == 'C' || map_readed_end[i - 1] == '0')
		map_readed_end[i - 1] = 'X';
}
